#include "nm.h"

void parse_table(struct symtab_command * sym, char * ptr, t_sect *sections)
{
    struct nlist_64 *tbl;
	t_list *symbols;
	t_symbol* entry;
	char *str;
    uint32_t i;

	symbols = NULL;
	str = ptr + sym->stroff;
    tbl = (struct nlist_64 *)(ptr + sym->symoff);
	i = 0;
    while (i < sym->nsyms)
    {
		entry = malloc(sizeof(t_symbol));
		entry->name = str + (tbl->n_un).n_strx;
	   	entry->value =  tbl->n_value;
		entry->type = tbl->n_type & N_TYPE;
		entry->ext = tbl->n_type & N_EXT;
		entry->sect = tbl->n_sect;
		ft_lstadd_sorted(&symbols, &symbol_cmp, entry, 1);
		tbl++;
		i++;
    }
	print_all(symbols, sections, BIT_64);
}

t_sect *get_section()
{
	t_sect *sect = malloc(sizeof(t_sect));
	sect->bss = 0;
	sect->text = 0;
	sect->data = 0;
	sect->index = 0;

	return sect;
}


void populate_sections(struct segment_command_64 *seg_cmd, t_sect * sections)
{
	struct section_64			*sect;
	uint32_t i;

	sect = (struct section_64 *)((void *)seg_cmd + sizeof(struct segment_command_64));
	i = 0;
	while(i < seg_cmd->nsects)
	{
		if (!ft_strcmp((sect + i)->sectname, SECT_TEXT)
			&& !ft_strcmp((sect + i)->segname, SEG_TEXT))
			sections->text = sections->index + 1;
		else if (!ft_strcmp((sect + i)->sectname, SECT_DATA)
			&& !ft_strcmp((sect + i)->segname, SEG_DATA))
			sections->data = sections->index + 1;
		else if (!ft_strcmp((sect + i)->sectname, SECT_BSS)
			&& !ft_strcmp((sect + i)->segname, SEG_DATA))
			sections->bss = sections->index + 1;
		i++;
		sections->index++;
	}
}

int mach64(void *file)
{
	struct mach_header_64 *header;
	struct load_command *load_cmd;
	t_sect *sect;
	uint32_t i;

	sect = get_section();
	header = file;
	load_cmd = (struct load_command *)(header + 1);
	set_ppc(swap_uint64(header->cputype) == CPU_TYPE_POWERPC64);
	i =  ppc_64(header->ncmds);
	while(i < header->ncmds)
	{
		if (ppc_64(load_cmd->cmd) == LC_SEGMENT_64)
			populate_sections((struct segment_command_64 *)load_cmd, sect);
		if (ppc_64(load_cmd->cmd) == LC_SYMTAB)
			parse_table((struct symtab_command *)load_cmd, file, sect);
		load_cmd = (void *)load_cmd + ppc_32(load_cmd->cmdsize);
		i--;
	}
	free(sect);
	return 0;
}
