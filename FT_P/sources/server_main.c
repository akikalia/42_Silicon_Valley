#include "ftp.h"

int init_socket(int port)
{
	int socket_fd;
	struct sockaddr_in serv_addr;

	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("error opening socket");
	ft_bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(socket_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR binding");
	return socket_fd;
}

void change_dir(int fd, char *path)
{
	if (chdir(path) < 0)
		send_str(fd, "could not change dir\n");
	else
		send_str(fd, "");
}

void pipe_ls(int socket_fd, char **argv)
{
	int pid;
	int size;
	char term;

	term = -1;
	size = -1;
	if((pid = fork()) < 0)
		error("error forking for ls");
	else if (pid == 0)
	{
		if (dup2(socket_fd, 1) < 0)
			error("fd could not dup");	
		if (dup2(socket_fd, 2) < 0)
			error("fd could not dup");	
		write(1, &size, sizeof(int));
		if(execv("/bin/ls", argv) < 0)
			error("could not execute ls");
	}
	wait4(pid, NULL, 0 ,NULL);
	write(socket_fd, &term , 1);
}

void send_pwd(int fd)
{
	char pwd[100];
	int size;
	char *cwd;

	size = 100;
	cwd = ft_strjoin(getcwd(pwd, size), "\n");
	send_str(fd, cwd);
	free(cwd);
}

void exec_cmd(char *cmd, int fd, char *root)
{
	char **argv;
	char *prog;

	argv = ft_strsplit(cmd, ' ');
	prog = argv[0];
	printf("cmd : %s\n",cmd);
	if (!ft_strcmp(prog, "cd"))
		change_dir(fd, argv[1]);
	else if(!ft_strcmp(prog, "pwd"))
		send_pwd(fd);
	else if(!ft_strcmp(prog, "ls"))
		pipe_ls(fd, argv);
	else if (!ft_strcmp(prog, "get"))
		send_file(fd, argv[1]);
	else if (!ft_strcmp(prog, "put"))
		get_file(fd, argv[1]);
	else if (!ft_strcmp("quit", prog))
	{
		close(fd);
		free_arr(argv);
		free(cmd);
		ft_printf("Connection Closed\n");
		exit(0);
	}
	else
		printf("Undefined Command\n");
	free_arr(argv);
}

void get_pwd(char **root)
{
	char buf[200];

	if(!getcwd(buf, 200))
		error("error getting current dir");
	*root = ft_strdup(buf);
}

void serve_client(int new_fd, int client_id)
{
	char *cmd;
	char *dir;
	char *root;

	dir = ft_itoa(client_id);
	if(mkdir(dir, S_IRWXU) < 0)
		ft_printf("dir already exists\n");
	if(chdir(dir) < 0)
		error("could not change a directory");
	get_pwd(&root);
	while(1)
	{
		cmd = get_input(new_fd);
		exec_cmd(cmd, new_fd, root);
		free(cmd);
	}
	free(root);
}

int main(int argc, char **argv)
{
	int socket_fd;
	int pid;
	int port;
	socklen_t clisize;
	struct sockaddr_in cli_addr;
	int new_fd;
	char *root;


	int i = 0;
	if (argc != 2)
		error("no port provided");
	if (MIN_PORT >= (port = ft_atoi(argv[1])) || port >= MAX_PORT)
		error("port number invalid");
	socket_fd = init_socket(port);
	while(1)
	{
		printf("waiting for clients...\n");
		if (listen(socket_fd, 5) < 0)
			error("listen failed");
		clisize = sizeof(cli_addr);
		if ((new_fd = accept(socket_fd,  (struct sockaddr *)&cli_addr, &clisize)) < 0)
			error("could not accept");
		if((pid = fork()) < 0)
			error("process could not fork");
		else if (pid > 0)
			serve_client(new_fd, i);
		printf("client id: %d\n", i);
		i++;
	}
}
