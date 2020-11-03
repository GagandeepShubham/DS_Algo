/**
 * GAGANDEEP SHUBHAM
 * 2020CSM1009 
 * Calculator program implementation(extension of the program done in lecture 06). 
**/
#include<stdio.h>
#include<string.h> //to compare the strings.
#include<math.h> //to perform the math operations like sin, cos, pow,exp.
#include<ctype.h> //for isdigit.
#include<stdlib.h> // for atof()
#define MAXOP_SIZE 100 // max size of operand or operator.
#define NUM '0' //signal that number was found.
#define FUNC 'f' //signal that function was found.
#define MAXSIZE 100 //max depth of the stack.
#define BUFFER_SIZE 100
char buffer[BUFFER_SIZE]; //buffer for ungetch
int bfp = 0; //next free position in buffer.
int tp = 0; //next free stack position.
double val[MAXSIZE];

void push(double d) //pushes the items in the stack
{
    if(tp < MAXSIZE) 
    {
        val[tp++] = d;
    }
    else
    {
        printf("Error:Stack Overflow, can't push %f\n", d);
    }
}

double pop() //pops the items from the stack and returns it.
{
    if(tp > 0)
    {
        return val[--tp];
    }
    else
    {
        printf("Error: Stack Underflow, can't pop\n");
        return 0.0;
    }
}

int getch()
{
    //if buffer is empty then get the character from input.
    //else return a character from the buffer.
    return (bfp > 0) ? buffer[--bfp] : getchar();
}

void ungetch(int c)
{
    if(bfp >= BUFFER_SIZE) // if the buffer is full then we can't add more in it.
    {
        printf("ungetch : too many characters\n");
    }
    else
    {
        buffer[bfp++] = c; //else add the character to the buffer and then increment the buffer pointer.
    }    
}

void function(char str[])
{
    double var1;
    double var2;
    if(strcmp(str, "sin") == 0) //if the string str == sin it will return 0 else 1
    {
        var1 = pop();
        var2 = sin(var1); //performing the sin operation.
        push(var2); //pushing the value of the operation in the stack.
    }
    else if(strcmp(str, "cos") == 0) //if the string str == cos , it will return 0.
    {
        var1 = pop();
        var2 = cos(var1);
        push(var2);
    }
    else if(strcmp(str, "exp") == 0) //if the string str == exp, it will return 0.
    {
        var1 = pop();
        var2 = exp(var1); //exp performs e ^ var  = (2.78...)^var
        push(var2);
    }
    else if(strcmp(str, "pow") == 0)
    {
        var2 = pop();
        var1 = pop();
        push(pow(var1 ,var2)); // var1 ^ var2.
    }
    else //if string str doesn't match with any of the above functions.
    {
        printf("Error: %s command is not supported!\n",str);
    }
}

int getopr(char s[])
{
    int i , c;
    while((s[0] = c = getch()) ==  ' ' || c == '\t'); //getting all the whitespace and tab characters in begining.
    s[1] = '\0'; 

    i = 0; //initializing i;
    //when above while loop becomes false, c is already holding a character.
    //following if condition on that character c.
    if(isalpha(c)) //the chracter is a alphabet.
    {
        while(isalpha(s[++i]= c = getch())); //getting all the alphabets.
            
        s[i]= '\0'; //marking the string end;
        if(c != EOF) //putting the character back into buffer. [the character c  which broke the while loop above.]
        {
            ungetch(c);
        }
        if(strlen(s) > 1) //if the length of the string s is greater than 1 , it means that it might be a function.
        { 
            return FUNC; //signaling for the FUNC
        }
        else
        {   
            return c; //other wise return it.
        }
    }
    if(!isdigit(c) && c != '.' && c != '-')
    {
        //TODO: check if '-' is sign of an integer or just a -ve char.
         return c; //not a number, it will just be an operator.
    }
    if(c == '-')
    {
        if(isdigit(c = getch()) || c == '.') //checking that the next char is a digit or not.
        {
            s[++i] = c; //if a next character is a digit then put it in s.
        }
        else
        {
            if(c != EOF)ungetch(c); //first non digit encoutered then put the read character back in the buffer.
            return '-'; //return the -
        }
    }
    if(isdigit(c)) //collect integer part.
        while(isdigit(s[++i] = c = getch())); //while the digits are coming keep on putting them in array s.
            
    if(c == '.') //collects fractional part. 
        while(isdigit(s[++i] = c = getch())); //while the digits are coming keep on putting them in array s.
            
    s[i] = '\0'; //put the null character to complete the string.
    if(c != EOF) ungetch(c); //putting the character back on buffer which broke the while condition in fractional part if statement.
    return NUM; //returning the NUM, the signal for the number.
}

int main()
{
    int type;
    double op1, op2; //for operands of stack
    char s[MAXOP_SIZE]; //for the number , function, etc.
    int var1, var2; //variables for modulus.
    while((type = getopr(s)) != EOF) //while Ctrl-Z + Enter not pressed, call getop(s).
    {
        switch(type) //since we can't pass a string to a case in switch case, therefore we have used signals for number and functions.
        {
            case NUM: //if we have a number.
                push(atof(s)); //convert the string to float.
                break;
            case FUNC: //if we have a mathematical function
                function(s); //call the function function.
                break;
            case '+':
                op2 = pop();
                op1 = pop();
                push(op2 + op1);
                break;
            case '*':
                op2 = pop();
                op1 = pop();
                push(op2 * op1);
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
                break;
            case '/':
                op2 = pop();
                op1 = pop();
                if(op2 != 0.0)
                    push(op1 / op2);
                else
                    printf("Error: Can't divide with Zero!\n");
                break;
            case '%': //modulus doesn't works on float.
                var2 = (int)pop(); 
                var1 = (int)pop(); 
                push(var1 % var2);
                break;
            case '\n': //popping the output from the stack
                printf("\t%f\n", pop());
                break;
            default:
                printf("Error: Unknown Command: %s\n", s);
                break;
        }
    }
    return 0;
}
