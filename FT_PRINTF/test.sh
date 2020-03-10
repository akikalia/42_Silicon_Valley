#!/bin/bash
make > /dev/null
cd test_stuff
gcc main_ft.c ../libftprintf.a -o ft > /dev/null
gcc main_orig.c -w -o orig > /dev/null
./orig > orig_out.txt
./ft > ft_out.txt
cat orig_out.txt
cat ft_out.txt
diff -s orig_out.txt ft_out.txt
cd ..
make fclean > /dev/null