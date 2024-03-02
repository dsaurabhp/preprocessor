#include"Pre.h"
/* This function find "#define" in string
 * after find, macro name is collect by q using Found();
 * and macro expression collect by r using String();
 * after that we replace using Replace_Mac();*/
void Macro(char *str)
{
	char *p;
	char *q;
	char *r;
	p=str;
	while(p=strstr(p,"#define"))
	{
		q=Found(p);
		if(q!=NULL)
		{
			r=String(q,p);
			if(r!=NULL)
			{
				Remove_Mac(p);
				Replace_Mac(q,r,str);			
				free(r);
			}
			free(q);
		}
		p++;
	}
}
char *Found(char *p)
{
	int i=0,f=0,c=0;
	char *str=NULL;
	for(i=0;p[i];i++)
	{
		if(c)
		{
			str=realloc(str,f+1);
			str[f++]=p[i];
		}
		if(p[i]==32)
			c++;
		if(c==2)
			break;
	}
	if(c==2)
	{
		str[f-1]='\0';
		return str;
	}
	return NULL;
}
void Remove_Mac(char *p)
{
	int i=0;
	for(i=0;p[i];i++)
		if((p[i]==10)||(p[i]==9))
			break;
		else
			p[i]=' ';
}
void Replace_Mac(char *macro,char *replace,char *str)
{
	char *p;
	p=str;
	int i=0,j=0;
	while(p=strstr(p,macro))
	{
		i=strlen(macro);
		j=strlen(replace);
		if(i==j)// if macro name size == macro expresion
			strCpy(p,replace);
		if(i<j)// if macro name size is less than macro expression
			INC(p,replace,str,j-i);
		if(i>j)// if macro name size is greater than macro expression
			DEC(p,replace,str,i-j);
		p++;
	}
}
void strCpy(char *p,char *replace)
{
	int i=0;
	for(i=0;replace[i];i++)
		p[i]=replace[i];
}
void INC(char *p,char *replace,char *str,int m)
{
	str=realloc(str,strlen(str)+m);
	memmove(p+m,p,strlen(p));
	strCpy(p,replace);	
}
void DEC(char *p,char *replace,char *str,int m)
{
	memmove(p,p+m,strlen(p));
	str=realloc(str,strlen(str)-m);
	strCpy(p,replace);	
}
char *String(char *str,char *f)
{
	char *p=NULL,*q=NULL;
	int i=0,c=0,j=0;
	p=strstr(f,"#define");
	p=strstr(p,str);
	for(i=0;p[i];i++)
	{
		if(p[i]==32)
			c=1;
		if(c)
		{
			if((p[i]=='\n')||(p[i]==9))
				break;
			if(p[i]!=32)
			{
				q=realloc(q,j+1);
				q[j++]=p[i];
			}
		}
	}
	if(c)
		q[j]='\0';
	return q;
}
