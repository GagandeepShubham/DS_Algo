/*Program to implement the circular queue */
#include<stdio.h>
#define MAXSIZE 5

int cq[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == -1 && front == -1) // if its the very first element.
    {
        cq[++rear] = x;
        front++;
    }
    else if((rear + 1 ) % MAXSIZE == front) //when the rear is pointing to the last pos in queue and front is point to the first pos.
    {
        printf("The queue is full");   //
    }
    else
    {
        rear = (rear + 1) % MAXSIZE;
        cq[rear] = x; 
    }
}
void dequeue()
{
    if(front == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        front++;
    }
}

int get_Front()
{
    return cq[front];
}

int get_Rear()
{
    return cq[rear];
}

int isEmpty()
{
    if(front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if((rear + 1) % MAXSIZE == front)
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
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", cq[i]);
    }
}

int main()
{
  

    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(8);
    enqueue(10);

    printf("\nThe front element is : %d", get_Front());
    printf("\nThe rear element is:%d", get_Rear());

    dequeue();
    dequeue();
    dequeue();
    dequeue();
 

    printf("\nCircular Queue empty? : ");
    printf((isEmpty() == 1)? "true" : "false");

    printf("\nCircular Queue Full? : " );
    printf((isFull() == 1)? "true" : "false");

    printf("\nThe front element is : %d", get_Front());
    printf("\nThe rear element is:%d", get_Rear());

    //just to check the display function
    printf("\n");
    display();
}