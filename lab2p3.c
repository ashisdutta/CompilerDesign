#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void stateQ0(char c);
void stateQ1(char c);
void stateQ2(char c);
void stateQ4(char c);
void stateQ3();

char *s="+106.5";
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
    if("+" || "-")
    {
        stateQ2(nextChar());
    }
    else if(isdigit(c))
    {
        stateQ1(nextChar());
    }
    else
    {
        stateQ3(); 
    }

}

void stateQ1(char c)
{
    if(isdigit(c))
    {
        stateQ1(nextChar());

    }
    else if(".")
    {
        stateQ4(nextChar());
    }
    else
    {
        stateQ3();
    }
}

void stateQ2(char c)
{
    if(isdigit(c))
    {
        stateQ1(nextChar());
    }
    else{
        stateQ3();
    }
}

void stateQ4(char c)
{
    if(isdigit(c))
    {
        stateQ4(nextChar());
    }
    else if(c=='\0')
    {
        printf("accepted");
    }
    else
    {
        stateQ3();
    }

    
}

void stateQ3()
{
    printf("rejected");
    exit(0);
}
