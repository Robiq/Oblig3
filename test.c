#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	int x=12;
	char to[10];
	char* cp="abcdefghi";

	sprintf(to, "%d%s", x, cp);

	printf("Pls %s.\n", to);	
}