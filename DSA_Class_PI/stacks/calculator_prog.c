/**
 * Calculator program implementation.
**/
#include<stdio.h>
#include<ctype.h> //for isdigit.
#include<stdlib.h> // for atof()
#define MAXOP 100 // max size of operand or operator.
#define NUMBER '0' //signal that number was found.
#define MAXVAL 100 //max depth of the stack.
#define BUFSIZE 100
char buf[BUFSIZE]; //buffer for ungetch
int bufp = 0; //next free position in buffer.
int sp = 0; //next free stack position.
double val[MAXVAL];

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, can't push %f\n", f);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch : too many characters\n");
    else
        buf[bufp++] = c;
}

int getop(char s[])
{
    int i , c;
    while((s[0] = c = getch()) ==  ' ' || c == '\t');
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; //not a number.
    i = 0;
    if(isdigit(c)) //collect integer part.
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.') //collects fractional part.
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF) ungetch(c);
    return NUMBER;
}

int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%f\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}