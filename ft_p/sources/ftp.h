#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <netdb.h>
#include "../libft/libft.h"
#define MIN_PORT 2000
#define MAX_PORT 65535
#define BUFF_SIZE 32
typedef struct s_file_str 
{
	char *content;
	int size;
}				file_str;

void	free_arr(char **arr);
void error(char *msg);
void get_file(int fd, char *filename);
char *ft_strdupfree(char *str);
char	*get_input(int fd);
void send_file(int socket_fd, char *path);
void send_str(int fd, char *str);
