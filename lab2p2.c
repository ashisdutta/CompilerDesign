#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void stateQ0(char c);
void stateQ1(char c);
void stateQ2();

char *s="b0";
int i=0;
char nextChar()
{
    return s[i++];
}


void main()
{
   stateQ0(nextChar());
}

void stateQ0(char c)
{
    if(isalpha(c))
    {
        stateQ1(nextChar());
    }
    else
    {
        stateQ2(); 
    }

}

void stateQ1(char c)
{
    if(isalpha(c) || isdigit(c))
    {
        stateQ1(nextChar());
    }
    else if(c=='\0')
    {
        printf("Accepcted");
        exit(0);
    }
    else
    {
        stateQ2(); 
    }
}

void stateQ2()
{
    printf("Rejected");
}