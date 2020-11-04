/**
 * This program reverses a linked list.
**/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if(head == NULL)head = temp;
    else
    {
        struct Node *temp1 = head;
        while(temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
    }
}
void print()
{
    struct Node *temp = head;
    while(temp != NULL)
    { 
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void reverse(struct Node *p) //recursive function to reverse the linked list.
{
    struct Node *q; // q will always point to the previous node of p. There will be a q for each node in stack.
    if(p -> next != NULL)
    {
        q = p;
        p = p -> next;
    }
    else
    {
        head = p; // when we reach the last node whose next is null then head will point to that.
        return;
    } 
    
    reverse(p); // After every reverse call is executed then the following instructions will execute.
    p -> next = q;
    q -> next = NULL;
}
int main()
{
    head = NULL;
    int n, data;
    printf("Enter the nodes to be created: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }

    printf("\nBefore reversal: ");
    print();

    printf("\nAfter reversal: ");
    reverse(head);
    print();
}
