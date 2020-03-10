#!/bin/bash
make > /dev/null

FILES=tests/*
for f in $FILES
do
    echo $f
    ./fillit $f
    echo
done

make fclean > /dev/null