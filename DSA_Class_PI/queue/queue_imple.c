#include<stdio.h>
#define MAXSIZE 5 
#define pb push_back
#define nl printf("\n")

int Q[MAXSIZE];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if(rear == MAXSIZE - 1)
    {
        printf("The queue is full!");
    }
    if(front == -1 && rear == -1)
    {
        Q[++rear] = x;
        ++front;
    }
    else
    {
        Q[++rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("Queue is already empty!");
    }
    else
    {
        front++;
    }
}

int get_Front()
{
    return Q[front];
}

int get_Rear()
{
    return Q[rear];
}

int isEmpty()
{
    if(front == -1 && rear == -1)
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
    if(rear == MAXSIZE - 1)
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
    for(int i = front; i <= rear ; i++)
    {
        printf("%d ", Q[i]);
    }
}

int main()
{

    //enqueing the elements in the queue.
    enqueue(3);
    enqueue(5);
    enqueue(7);
    enqueue(9);

    //printing the front element of the queue.
    printf("\nThe front element of the queue is: %d", get_Front());

    dequeue();
    dequeue();

    printf("\nAfter 2 dequeue operations, the front is:%d", get_Front());

    //printing the rear element of the queue.
    printf("\nThe rear element of the queue is:%d", get_Rear());

    dequeue();

    //checking whether queue is empty or not.
    printf("\nQueue Empty? :");
    printf((isEmpty() == 1)? "true" : "false");

    //checking whether queue is full or not.
    printf("\nQueue Full? :");
    printf((isFull() == 1)? "true": "false");
    //NOTE: Even if the queue has enough space to still accomodate elements it will show full.
    //this is the main drawback of the queue implementation this way.
    //that's why we move to circular queue which are more beneficial considering space.

    printf("\n");
    display(); //for displaying all the queue elements at once.
}