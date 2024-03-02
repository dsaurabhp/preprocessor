#include"Pre.h"
/* I call this funcrion only one time to read main.c file data
 * after that i allocate memory dynamically and return that address*/
char *read(char* fn)
{
	FILE *fp;
	char *p=NULL;
	long size;
	if((fp=fopen(fn,"r"))==NULL)
	{
		printf("%s not found :(\n",fn);
		exit(0);
	}
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	p=calloc(size+1,1);
	fread(p,size+1,1,fp);
	p[size]='\0';
	fclose(fp);
	return p;
}
