#include<stdio.h>
#define MAXSIZE 5
int S[MAXSIZE];
int tp = -1; //stack top

void push(int x) //push elements into the stack.
{
    if(tp == MAXSIZE - 1)  //if no space in stack
    {
        printf("Stack is full!");
    }
    else
    {
        S[++tp] = x; // first increment then store.
    }
}

void pop() //pop the elements from the stack.
{
    if(tp == -1)
    {
        printf("Stack is empty!");
    }
    else
    {
        tp--; //we simply point to the one location back.
    }
}

int top() //returns the topmost element of the stack.
{
    int x = S[tp];
    return x;   
}

int isFull() //checks wheter the stack is full or not.
{
    if(tp == MAXSIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty() // checks whether the stack is empty or not.
{
    if(tp == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    for(int i = tp; i >= 0; i--)
    {
        printf("%d\n", S[i]);
    }
}

int main()
{
   int  i , data;
   //Entering the data in the stack.
   push(2);
   push(4);
   push(5);
   push(9);
   printf("The top is:%d", top());

   pop();

   printf("\nAfter popping top, the new top is:%d", top());

   printf("\nEnter an element to push:");
   scanf("%d",&data);
   push(data);

   printf("Now new top is:%d\n", top());

   pop();

   printf("\nStack empty?:");
   printf(isEmpty()? "true" : "false");
   printf("\n");
   if(!isEmpty())
   {
       printf("Inside stack are:\n");
       display();
   }
}