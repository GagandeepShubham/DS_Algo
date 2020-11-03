/**
 * A sample program for getch and ungetch()
 * getch() - gets the character while we require it.
 * ugetch() - stores the non required character inside the buffer.
**/
#include<stdio.h>
#include<ctype.h> //to check whether the character is digit or not.
#define BUFSIZE 100
char buf[BUFSIZE]; //buffer for ungetch.
int bufp = 0; //next free position in buffer.

int getch() //it works same as getchar but it returns a buffer contents 
{
    return (bufp > 0) ? buf[--bufp] : getchar(); //if buffer is non empty then it must be holding non-integer values 
}
void ungetch(int c) //pushes character back on the input.
{
    if(bufp >= BUFSIZE) //if the buffer is already full.
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c; // push the character(non digit) into the buffer.
    }
}

int main()
{
    int i = 0; char ch;
    printf("Enter an integer followed by a character:\n");

    //reads character(integer) until non digit or EOF.
    while((ch = getch()) != EOF && isdigit(ch))
    {
        i = 10 * i + ch - 48; //convert ascii into int value.
    }
    //if non digit char was read , push it back into input buffer.
    if(ch != EOF)ungetch(ch);
    printf("i = %d, next char in buffer = %c\n", i, getch());
}