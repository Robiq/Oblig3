#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdarg.h>


int sprinter(char* a, char* b,...)
{
	va_list liste;
	va_start(liste, b);

	int x = strlen(b);
	int i;

	char c, *s;
	int d, apoint=0;
	float f;

	
	for(i=0;i<=x;i++){

		if(b[i-1] == '%'){
			
			switch(b[i]){
				//String
				case 's':
					s=va_arg(liste, char*);
					//Add string
					for(d=0;d<=(strlen(s));d++)	a[apoint++]=s[d];
					break;
				//Int
				case 'd':
					d=va_arg(liste, int);
					if(d%10 < 10){
						a[apoint++]=d+'\0';
					}else{
						while(d=d%10 > 10){
							a[apoint++]=d+'\0';
						}
						a[apoint++]=d+'\0';
					}
					break;
				//Char
				case 'c':
					c=(char) va_arg(liste, int);
					a[apoint++]=c;
					break;
				//Float
				case 'f':
					f=va_arg(liste, float);

					break;
				//Unsigned int til Hex
				case 'x':
					d=va_arg(liste, int);
					if(d%16 == 0){

					}else{

					}
					break;
				//%% = Sett inn %.
				case '%':
					a[apoint++]='%';
					break;
				//If none of the above.
				default:
					return -1;
			}
		}else{
			a[apoint++]=b[i];
		}
	}

	va_end(liste);

	a[apoint+1]='\0';

	return x;
}
void main(int argc, char argv[])
{

	char* a=malloc(10);

	char* a2=malloc(10);

	char* copy="Copy me!";

	sprintf(a2, "%s", copy);

	sprinter(a, copy);

	printf("Orginal: %s, Sprintf: %s, target: %s\n", copy, a2, a);

	free(a);
	free(a2);
}