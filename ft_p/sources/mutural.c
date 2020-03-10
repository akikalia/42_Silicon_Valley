#include "ftp.h"


/*
int check_dir(char *cmd, char *root)
{

}
*/
void error(char *msg)
{
    printf("error: %s\n", msg);
    exit(1);
}
void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void str_to_file(file_str *file, char *filename)
{
	int fd;
	char *temp;

	//if((temp = ft_strrchr(filename, '/')))
	//		filename = temp + 1;
	if (!((fd = open(filename, O_RDONLY)) < 0))
		error("file already exists");
	fd = open(filename , O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	if (write(fd, file->content, file->size) < 0)
		error("error writing to a file");
	close(fd);
}

void file_to_str(char *filename, file_str *file)
{
	char *buf;
	struct stat stt;
	int size;
	int fd;

	if((fd = open(filename, O_RDONLY)) < 0)
		error("file does not exist");
	if(fstat(fd , &stt))
		error("fstat error");
	buf = malloc(sizeof(char) * (stt.st_size + 1));
	if (read(fd, buf, stt.st_size) < 0)
		error("error reading from a file");
	buf[stt.st_size] = '\0';
	file->content = buf;
	file->size = stt.st_size;
	close(fd);
}

void get_file(int fd, char *filename)
{
	file_str file;

	if(read(fd, &(file.size), sizeof(int)) < 0)
		error("error getting file size");
	file.content = malloc(sizeof(char) * (file.size + 1));
	file.content[file.size] = '\0';
	if (read(fd, file.content, file.size) < 0)	
		error("error getting file");
	ft_printf("about to create file\n");
	ft_printf("file sent\nsize : %d\ncontent : \"%s\"\n", file.size, file.content);
	str_to_file(&file, filename);
}


void send_file(int socket_fd, char *path)
{
	file_str file;
	file_to_str(path, &file);
	if(write(socket_fd, &(file.size), sizeof(int)) < 0)	
		error("error sending file");
	if(write(socket_fd, file.content, file.size) < 0)
		error("error sending file");
	ft_printf("file sent\nsize : %d\ncontent : \"%s\"\n", file.size, file.content);
}

char *ft_strdupfree(char *str)
{
	char *temp;

	temp = ft_strdup(str);
	free(str);
	return temp;
}

char	*get_input(int fd)
{
	char	*buf;
	char buff[BUFF_SIZE + 1];
	int size;
	char *temp;

	buf = NULL;
	if(read(fd,&size,sizeof(int)) < 0)
		error("error reading from fd");
	if (size < 0)
	{
		while(1)
		{
			size = read(fd, buff, BUFF_SIZE);
			buff[size] = 0;
			if((temp = ft_strchr(buff, -1)))
			{
				*temp = '\0';
				buf = ft_stradd(buf, ft_strdup(buff));
				break ;
			}
			else
				buf = ft_stradd(buf, ft_strdup(buff));
		}
	}
	else 
	{
		buf = malloc(sizeof(char) * size);
		if(read(fd, buf, size) < 0)
			error("error reading from fd");
	}
	return (buf);
}

void send_str(int fd, char *str)
{
	int len = ft_strlen(str) + 1;
	if (write(fd, (char *)&len, sizeof(int)) < 0)
		error("could not write to socket");
	if(write(fd, str, len) < 0)
		error("could not write to socket");
}
