
# École 42

## minishell

This is an implementation of mini command interpreter.
Instructions of the implementation can be found in minishell.en.pdf file, located in the same directory.

## Getting Started

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`

### Execution
 To test the program, run it as follows:

 './minishell'

 'echo "ls" | ./minishell'

 './minishell ms_inputs.txt'

 'cat ms_inputs.txt | ./minishell'

 or, run included bash file:

 './test.sh'

 To exit the program run:
 
 'exit'
 