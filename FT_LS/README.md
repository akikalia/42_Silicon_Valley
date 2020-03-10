
# École 42

## FT_ls

This is an implementation of famous system command - 'ls'.
Program runs with following options : -l, -R, -a, -r and -t.
Instructions of the implementation can be found in ft_ls.en.pdf file, located in the same directory.

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
 To test the program, run program as follows:

 './ft_ls'

 './ft_ls ~/_directory_name_'

 './ft_ls -R ~/_directory_name_'
 
 './ft_ls -lRart ~/_directory_name_'

 './ft_ls -l -R -a -r -t ~/_directory_name_'

 './ft_ls -R /'

 or, run included bash file:

 './test.sh'