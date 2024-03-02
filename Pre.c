/*  This is main file for Preprocessor
    Written By SAURABH V23HE5S4
*/
#include"Pre.h"
char *s;
int main(int argc,char *argv[])
{
	char *p;
	char *q;
	if(argc!=2)
	{
		printf("Enter proper format .exe filename\n");
		exit(0);
	}
	/*Reading file ex. main.c and create DMA
	 *and assign that address to p*/
	p=read(argv[1]);
	Remove(p);// Remove Comments
	Macro(p);// Replace Macros found in main.c file
	s=p;
	// Find Header File means "#include" in File
	while((q=Header(s))!=NULL)
	{
		p=Include(q);// Including that file
		Remove(p);// Remove Comments
	}
	write(p,argv[1]);// creat new file in .i ex. main.i and write all data
	return 0;
}
