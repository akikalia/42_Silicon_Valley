#include "nm.h"

void parse_table_32(struct symtab_command * sym, char * ptr, t_sect *sections)
{
    struct nlist *tbl;
	t_list *symbols;
	t_symbol* entry;
	char *str;
    uint32_t i;

	symbols = NULL;
	str = ptr + sym->stroff;
    tbl = (struct nlist *)(ptr + sym->symoff);
	i = 0;
    while (i < sym->nsyms)
    {
		entry = malloc(sizeof(t_symbol));
		entry->name = str + tbl->n_un.n_strx;
	   	entry->value =  tbl->n_value;
		entry->type = tbl->n_type & N_TYPE;
		entry->ext = tbl->n_type & N_EXT;
		entry->sect = tbl->n_sect;
		ft_lstadd_sorted(&symbols, &symbol_cmp, entry, 1);
		tbl++;
		i++;
    }
	print_all(symbols, sections, BIT_32);
}

t_sect *get_section_32()
{
	t_sect *sect = malloc(sizeof(t_sect));
	sect->bss = 0;
	sect->text = 0;
	sect->data = 0;
	sect->index = 0;

	return sect;
}


void populate_sections_32(struct segment_command *seg_cmd, t_sect * sections)
{
	struct section			*sect;
	uint32_t i;

	sect = (struct section *)((void *)seg_cmd + sizeof(struct segment_command));
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

int mach32(void *file)
{
	struct mach_header *header;
	struct load_command *load_cmd;
	t_sect *sect;
	uint32_t i;

	sect = get_section_32();
	header = file;
	load_cmd = (struct load_command *)(header + 1);
	i = 0;
	while(i < header->ncmds)
	{
		if (load_cmd->cmd == LC_SEGMENT)
			populate_sections_32((struct segment_command *)load_cmd, sect);
		if (load_cmd->cmd == LC_SYMTAB)
			parse_table_32((struct symtab_command *)load_cmd, file, sect);
		load_cmd = (void *)load_cmd + load_cmd->cmdsize;
		i++;
	}
	free(sect);
	return 0;
}
