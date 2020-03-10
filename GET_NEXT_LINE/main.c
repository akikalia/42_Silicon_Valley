#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
    int fd;
    char *line;

    fd = (argc > 1) ?  open(argv[1], O_RDONLY) : 0;
    if (fd < 0)
        exit(1);
    while(0 < get_next_line(fd, &line))
        printf("%s\n", line);
    if (fd > 0)
        close(fd);
}