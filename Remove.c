#include"Pre.h"
/*This Fun is for remove single line and multi line comments
 * in header file as well as main.c file
 * */
void Remove(char *str)
{
	Single(str);
	Multi(str);
}
void Multi(char *str)
{
	int i=0,f=0;
	for(i=0;str[i];i++)
	{
		if(str[i]==47)
		{
			if(str[i+1]=='*')
			{
				str[i]=' ';
				str[i+1]=' ';
				f=1;
			}
		}
		if(str[i]=='*')
		{
			if((str[i+1]=='/')||(str[i+2]=='/'))
			{
				str[i]=' ';
				str[i+1]=' ';
				f=0;
			}
		}
		if(f)
			str[i]=' ';
	}
}
void Single(char *str)
{
	int i=0,f=0;
	for(i=0;str[i];i++)
	{
		if(str[i]==47)
			if(str[i+1]==47)
				f=1;
		if((str[i]=='\n')||(str[i]==9)||(str[i]=='*'))
		{
			if(str[i]=='*')
			{
				if(str[i+1]=='/')
					f=0;
			}
			else
				f=0;
		}
		if(f)
			str[i]=' ';
	}
}
