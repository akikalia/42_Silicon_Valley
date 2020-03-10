#include "ftp.h"

char	*get_cmd()
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	char	*res;
	char	*nl;
	int		err;

	res = "";
	temp = NULL;
	while (!(nl = ft_strchr(res, '\n')))
	{
		err = read(0, buf, BUFF_SIZE);
		buf[err] = '\0';
		if (temp)
			res = ft_strjoin(temp, buf);
		else
			res = ft_strdup(buf);
		free(temp);
		temp = res;
	}
	*nl = '\0';
	return (res);
}



void socket_echo_cmd(char *cmd, int socket_fd)
{
	char *input;
	
	input = get_input(socket_fd);
	ft_printf("%s", input);
	free(input);
}

void run_cmd(char *cmd, int socket_fd)
{
	char *prog;
	char **temp;
   
//	if (check_cmd(cmd) < 0)
//		ft_printf("directory does not exist or permission denied");
	if (*cmd)
	{
		temp = ft_strsplit(cmd, ' ');
		prog = temp[0];
		send_str(socket_fd, cmd);
		if (!ft_strcmp(prog, "cd") || !ft_strcmp(prog, "ls") || !ft_strcmp(prog, "pwd"))
			socket_echo_cmd(cmd, socket_fd);
		else if (!ft_strcmp(prog, "quit"))
		{
			close(socket_fd);
			free_arr(temp);
			free(cmd);
			exit(0);
		}
		else if (!ft_strcmp(prog, "get"))
			get_file(socket_fd, temp[1]);
		else if (!ft_strcmp(prog, "put"))
			send_file(socket_fd, temp[1]);
		else
			ft_printf("Undefined Command\n");
		free_arr(temp);
	}
	free(cmd);
}

int establish_connection(struct hostent *server, int server_port)
{
	int fd;
	struct sockaddr_in serv_addr;

	if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("could not create a socket");
	ft_bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    ft_memmove((char *)&serv_addr.sin_addr.s_addr,(char *)server->h_addr,server->h_length);
    serv_addr.sin_port = htons(server_port);
	if (connect(fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");
	return fd;
}
/*
void go_to_dir(int fd)
{
	int id;
	if (read(fd, &id, sizeof(int)) < 0)
		error("could not read socket");
	dir = ft_itoa(id);
	if(mkdir(dir, S_IRWXU) < 0)
		ft_printf("dir already exists");
	if(chdir(dir) < 0)
		error("could not change a directory");
}
*/
int main(int argc, char **argv)
{
	int sock_fd;
	int port;
	struct hostent *server;

	if(argc != 3)
		error("wrong number of arguments");
	if (MIN_PORT >= (port = ft_atoi(argv[2])) || port >= MAX_PORT)
		error("port number invalid");
	if((server = gethostbyname(argv[1])) == NULL)
		error("hostname issue");
	sock_fd = establish_connection(server, port);
	//go_to_dir(sock_fd);
	while(1)
	{
		ft_printf("ftp> ");
		run_cmd(get_cmd(), sock_fd);
	}
}
