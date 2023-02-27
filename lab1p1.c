#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stateQ0(char c);
void stateQ1(char c);
void stateQ2();
char *s="baba";
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
    switch(c)
    {
        case'a': stateQ1(nextChar());
        case'b':
        default: stateQ2();

    
    }
}

void stateQ1(char c)
{
    switch(c)
    {
        case'a':
        case'b':
            stateQ1(nextChar());
        case'\0': 
            printf("Accept");
            exit(0);
        default: 
            stateQ2();
    }
}

void stateQ2()
{
    printf("Reject");
    exit(0);
}

