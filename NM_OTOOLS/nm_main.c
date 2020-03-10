#include "nm.h"

uint16_t endian16(uint16_t num)
{
	return (num>>8) | (num<<8);
}

uint32_t endian32(uint32_t num)
{
	return ((num>>24)&0xff) |
                    ((num<<8)&0xff0000) |
	 				((num>>8)&0xff00) | 
                    ((num<<24)&0xff000000); 
}

uint64_t endian64(uint64_t val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL ) | ((val >> 8) & 0x00FF00FF00FF00FFULL );
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL ) | ((val >> 16) & 0x0000FFFF0000FFFFULL );
    return (val << 32) | (val >> 32);
}

int *get_ppc(void)
{
	static int ppc = 0;
	return &ppc;
}

void set_ppc(int i)
{
	if (i)
	{
		ft_printf("powerpc\n");
		*(get_ppc()) = 1;
	}
}


uint64_t ppc_64(uint64_t num)
{
	if (*(get_ppc()))
	{
		return endian64(num);
	}
	return num;
}
uint32_t ppc_32(uint32_t num)
{
	if (*(get_ppc()))
	{
		return endian32(num);
	}
	return num;
}
uint16_t ppc_16(uint16_t num)
{
	if (*(get_ppc()))
	{
		return endian16(num);
	}
	return num;
}




char get_symbol(t_symbol *symbol, t_sect *sections)
{
	if (symbol->type == N_ABS)
		return (symbol->type) ? 'A' : 'a';
	else if (symbol->type == N_INDR)
		return (symbol->ext) ? 'I' : 'i';
	else if (symbol->type == N_SECT)
	{
		if (symbol->sect == sections->bss)
			return (symbol->ext) ? 'B' : 'b';
		else if (symbol->sect == sections->data)
			return (symbol->ext) ? 'D' : 'd';
		else if (symbol->sect == sections->text)
			return (symbol->ext) ? 'T' : 't';
		else
			return (symbol->ext) ? 'S' : 's';
	}
	return 'U';
}

void print_all(t_list *symbols, t_sect *sections, int bit)
{
	t_symbol * temp;
	while(symbols)
	{
		temp = symbols->content;
		if (ft_strcmp(temp->name, "") && (temp->type == N_ABS || temp->type == N_SECT || temp->type == N_INDR || (temp->type == N_UNDF && temp->ext)))
		{
			if(temp->type == N_UNDF)
				ft_printf("%*s U %s\n", bit, "", temp->name);
			else if (temp->value)
				ft_printf("%0*llx %c %s\n", bit, temp->value, get_symbol(temp , sections), temp->name);
		}
		symbols = symbols->next;
	}
}

int symbol_cmp(t_symbol *s1, t_symbol *s2)
{
	return (ft_strcmp(s1->name, s2->name));
}

static void	place(t_node *n, t_list **alst, int *flag)
{
	n->temp->next = n->curr;
	if (n->prev != NULL)
		n->prev->next = n->temp;
	else
		*alst = n->temp;
	*flag = 0;
}

void		ft_lstadd_sorted(t_list **alst,
int (*cmp)(t_symbol*a, t_symbol*b), t_symbol *s, int flag)
{
	t_node		n;

	n.prev = NULL;
	n.temp = ft_lstnew((void*)s, sizeof(*s));
	n.curr = *alst;
	if (n.curr == NULL)
	{
		*alst = n.temp;
		flag = 0;
	}
	while (n.curr && flag)
	{
		if (cmp(n.curr->content, (void*)s) > 0)
			place(&n, alst, &flag);
		n.prev = n.curr;
		n.curr = n.curr->next;
	}
	if (n.curr == NULL && flag)
		n.prev->next = n.temp;
}

int ft_nm(void *file)
{

	if (*(uint32_t *)file == MH_MAGIC_64 || *(uint32_t *)file == MH_CIGAM_64)
		mach64(file);
	return 0;
}

int error(char *file, char *str)
{
	ft_printf("%s : %s\n", file, str);
	return (-1);
}

int run_file(char *file)
{
	int fd;
	struct stat stt;
	void *file_copy;

	fd = open(file, O_RDONLY);
	if ((fstat(fd, &stt) < 0) || (fd < 0 && errno == EACCES))
		return error(file, "Permission denied");
	else if(fd < 0)
		return error(file, "No such file or directory");
	if(S_ISDIR(stt.st_mode))
		return error(file, "Is a directory");
	if ((file_copy = mmap(NULL,stt.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) < 0)
		return error(file, "Mmap failed");
	if (ft_nm(file_copy) < 0)
		return error(file, "Failed to get symbols");
	munmap(file_copy, stt.st_size);
	close(fd);
	return 0;
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		return run_file("a.out");
	while (i < argc)
	{
		run_file(argv[i]);
		i++;
	}
	return 0;
}
