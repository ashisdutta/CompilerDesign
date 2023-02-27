#include<stdio.h>

#include<stdlib.h>
#include<string.h>

void stateQ0(char c);
void stateQ1(char c);
void stateQ2(char c);
void stateQ3();


char *s="134.03";
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
        case'0': 
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
            stateQ1(nextChar());
        default: stateQ3();

    
    }
}




void stateQ1(char c)
{
    switch(c)
    {
        case'0': 
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':
            stateQ1(nextChar());
        case'.':
            stateQ2(nextChar());
        default: stateQ3();

    
    }
}



void stateQ2(char c)
{
    switch(c)
    {
        case'o':
        case'1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':

            stateQ2(nextChar());
        case'\0': 
            printf("Accepted");
            exit(0);
        default: 
            stateQ3();
    }
}

void stateQ3()
{
    printf("Rejected");
    exit(0);
}
