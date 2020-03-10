
# École 42

## FT_ssl

This is an implementation of famous system command - 'ssl'.
Program runs with following algorithms : md5, sha256, sha224.
Program runs with following flags : -p, -q, -r, -s.
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

 './ft_ssl sha256'

 './ft_ssl sha256 -s "sample text here"'
 
 './ft_ssl sha256 -q -s "sample text here"'

 './ft_ssl sha224 -r -s "sample text here"'
 
 './ft_ssl md5 ~/_file_name_'

 or, run included bash file:

 './test.sh'
