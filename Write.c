#include"Pre.h"
/*this function is create new file name
 *argv[1] in .i format ex. main.c main.i
 *after that write all data.
 * */
void write(char *str,char*filename)
{
	FILE *fd;
	int i=0;
	for(i=0;filename[i];i++)
		if(filename[i]=='.')
			filename[i+1]='i';
	fd=fopen(filename,"w");
	fwrite(str,strlen(str),1,fd);
	fclose(fd);
}
