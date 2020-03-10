#!/bin/bash
make -C ./libft/ > /dev/null
gcc -g main.c get_next_line.c ./libft/libft.a -o GNL > /dev/null
echo -e "Printing main file:\n" 
./GNL main.c
echo -e "\nPrinting GNL file:\n"
./GNL get_next_line.c
echo -e "\nPrinting from stdin:\n"
echo -e "this is a test\nstdin input handled" | ./GNL
rm -f GNL
make -C ./libft/ fclean > /dev/null