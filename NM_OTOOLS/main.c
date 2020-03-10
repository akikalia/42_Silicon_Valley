#include <stdio.h>

void hello(int a)
{
	printf("hello %d", a);
}

int main (int argc, char **argv)
{
	int i = 0 ;
	while( i< argc)
	{
		hello(i);
		i++;
	}
	return 0;
}


