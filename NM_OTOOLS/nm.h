#include <mach-o/nlist.h>
#include <mach-o/loader.h>
#include <unistd.h>
#include <sys/mman.h>
#include "libft/libft.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BIT_32 8
#define BIT_64 16

typedef struct	s_node
{
	t_list		*prev;
	t_list		*curr;
	t_list		*temp;
}				t_node;

typedef struct s_symbol
{
	unsigned long	value;
	char			*name;
	uint8_t			type;
	uint8_t			ext;
	uint8_t			sect;
}				t_symbol;


typedef struct s_sect 
{
	uint32_t bss;
	uint32_t data;
	uint32_t text;
	uint32_t index;
}	t_sect;

uint16_t ppc_16(uint16_t num);
uint32_t ppc_32(uint32_t num);
uint64_t ppc_64(uint64_t num);
void set_ppc(int i);
int *get_ppc(void);
uint64_t endian64(uint64_t val);
uint32_t endian32(uint32_t num);
uint16_t endian16(uint16_t num);
int mach64(void *file);
int mach32(void *file);
int fat32(void *file);
int fat64(void *file);
void		ft_lstadd_sorted(t_list **alst,
int (*cmp)(t_symbol*a, t_symbol*b), t_symbol *s, int flag);
int symbol_cmp(t_symbol *s1, t_symbol *s2);
void print_all(t_list *symbols, t_sect *sections, int bit);
