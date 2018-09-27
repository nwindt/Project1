
#include 	<stdio.h>
#include	<stdlib.h>
#include	<iostream>
#include "rt.h"

int main(int argc, char *argv[])
{
	int i;

	/*	printf("argc = %d\n", argc);
		for( i = 0; i < argc; i ++)
			printf("arg[%d] = %s\n", i, argv[i]) ;

		getch() ;
	*/
	if (!(argc == 3))
		std::cout << "unexpected number of inputs exiting process...." << std::endl;

	std::string phrase = argv[1];
	int iterations = atoi(argv[2]);

	for (i = 0; i < iterations; i++) {
		std::cout << phrase << std::endl;
		Sleep(50);
	}

	return 0;		// exit child program by returning status value 0
				// Note we could also call exit(0) to achieve the same thing
}