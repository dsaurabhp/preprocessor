#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *read(char*);// function reading file main.c and create DMA and return add.
void Remove(char *);//Remove all comments from given string
void Multi(char *str);// Remove multiline comments from string
void Single(char *str);// Remove single line comments from string
void write(char *,char*);//write data to .i file ex. main.i
void Macro(char *);//find and replace Macro
char * Found(char *);// function that find "#define"
char * String(char *,char *);// giving string to replace
void Remove_Mac(char *);// remove macro
void Replace_Mac(char *,char *,char *);// replace macro with string given by func String		
void strCpy(char *,char *);//copy one string to another withount last '\0'
void INC(char *,char *,char *,int);//if macro size is less than macro expression
void DEC(char *,char *,char *,int);//if macro size is greater than macro expression
char * Header(char *);// find header file in given string "#include"
char *Include(char *);// add that header file
