#include"Pre.h"
extern char *s;
/* This Function find string "#include" in string if found return address
 * if not found return NULL*/
char *Header(char *str)
{
	char *p;
	if(p=strstr(str,"#include"))
		return p;
	if(p=strstr(str,"# include"))
		return p;
	if(p=strstr(str,"#  include"))
		return p;
	return NULL;
}
/* We try to open That Hederfile.
 * If found than add that file.
 * realloc memory and include that all file data
 * */
char *Include(char *str)
{
	int i=0,j=0,f=0,k=0,l=0;
	char file[50]="/usr/include/";
	char file1[100]="/usr/include/x86_64-linux-gnu/";
	char file2[50]="/usr/include/linux/";
	l=19;
	j=13;
	k=30;
	if(str[i]=='#')
	{
		if((str[i+1]=='i')||(str[i+2]=='i')||(str[i+3]=='i'))
		{
			if((str[i+3]=='n')||(str[i+2]=='n')||(str[i+4]=='n'))
			{
				strCpy(str,"         ");
				i=9;
				f=1;
			}
		}
	}
	for(;str[i];i++)
	{
		/*if(str[i]=='#')
		{
			if((str[i+1]=='i')||(str[i+2]=='i'))
			{
				if((str[i+2]=='n')||(str[i+3]='n'))
				{
					strCpy(str+i,"         ");
					i+=9;
					f=1;
				}
			}
		}*/
		if(str[i]=='>')
		{
			str[i]=' ';
			break;
		}
		if((str[i]!=32)&&(f)&&(str[i]!='<'))
		{
			file2[l++]=str[i];
			file1[k++]=str[i];
			file[j++]=str[i];
			str[i]=' ';
		}
		if(str[i]=='<')
			str[i]=' ';
	}
	file1[k]='\0';
	file[j]='\0';
	file2[l]='\0';
	FILE *fp,*fp1;
	long size;
	if((fp=fopen(file,"r"))!=NULL)
	{
		printf("SUCESS :%s\n",file);
		fseek(fp,0,2);
		size=ftell(fp);
		rewind(fp);
		if((str=realloc(s,strlen(s)+size+1))!=NULL)
		{
			s=str;
			memmove(str+size,str,strlen(str)+1);
			fread(str,size,1,fp);
			fclose(fp);
		}
		return str;
	}
	if((fp1=fopen(file1,"r"))!=NULL)
	{
		printf("SUCESS :%s\n",file1);
		fseek(fp1,0,2);
		size=ftell(fp1);
		rewind(fp1);
		if((str=realloc(s,strlen(s)+size+1))!=NULL)
		{
			s=str;
			memmove(str+size,str,strlen(str)+1);
			fread(str,size,1,fp1);
			//printf("%s\n",str);
			fclose(fp1);
		}
		return str;
	}
	if((fp1=fopen(file2,"r"))!=NULL)
	{
		printf("SUCESS :%s\n",file2);
		fseek(fp1,0,2);
		size=ftell(fp1);
		rewind(fp1);
		if((str=realloc(s,strlen(s)+size+1))!=NULL)
		{
			s=str;
			memmove(str+size,str,strlen(str)+1);
			fread(str,size,1,fp1);
			//printf("%s\n",str);
			fclose(fp1);
		}
		return str;
	}
	printf("Error: %s\n",file);
	return str;
}
