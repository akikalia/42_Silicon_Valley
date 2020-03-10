#!/bin/bash
make > /dev/null
./minishell  ms_inputs.txt
make fclean > /dev/null