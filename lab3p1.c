#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *ptr;
void openFile();
void endOfFile(char ch);
void stateQ0(char ch);
void stateQ1(char ch);
void stateQ2(char ch);
void stateQ3(char ch);
void stateQ4(char ch);
void stateQ5(char ch);
void stateQ6();


void openFile()
{
    ptr=fopen("test.c","r");
    if(ptr== NULL)
    {
        printf("problem to open");
        exit(0);
    }
}
char nextChar()
{
    return fgetc(ptr);
}

void endOfFile(char ch)
{
    if(ch==EOF)
    {
        printf("END\n");
        fclose(ptr);
        exit(0);
    }
}
void main()
{
    openFile();
    stateQ0(nextChar());
}

void stateQ0(char ch)
{
    if(ch=='#')
    {
        stateQ1(nextChar());
    }
    else if(ch=='/')
    {
        stateQ2(nextChar());
    }
    else if(ch==' '||ch=='\n')
    {
        stateQ0(nextChar());
    }
    else{
        stateQ5(nextChar());
    }
}

void stateQ1(char ch)
{
    if(ch='\n')
    {
        stateQ0(nextChar());
    }
    else
    {
        stateQ1(nextChar());
    }
}

void stateQ2(char ch)
{
    if(ch=='/')
    {
        stateQ1(nextChar());
    }
    else if(ch=='*')
    {
        stateQ3(nextChar());
    }
}

void stateQ3(char ch)
{
    if(ch=='*')
    {
        stateQ4(nextChar());
    }
    else
    {
        stateQ3(nextChar());
    }
}
void stateQ4(char ch)
{
    if(ch=='/')
    {
        stateQ0(nextChar());
    }
}

void stateQ5(char ch)
{
    if(ch==' ')
    {
        stateQ0(nextChar());
    }
    
    else if(ch=='(')
    {
        stateQ6(nextChar());
    }

printf("%c",ch);
}

void stateQ6()
{
    printf("\n");
}