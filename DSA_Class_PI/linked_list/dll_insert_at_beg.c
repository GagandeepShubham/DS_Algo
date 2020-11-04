/**
 * This programs creates a doubly linked list and each new node
 * created will be inserted at the beginning of the linked list.
 * NOTE: remember that when you'll print the list , the output will be reverse of what you entered
 * because each  new node is inserted at the begining one by one which made all the nodes present
 * in the node backward.
**/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev; //pointer to the previous node.
    struct Node *next; //pointer to the next node.
};

struct Node *head;

void insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    if(head == NULL)head = temp;
    else
    {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
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

int main()
{
    head = NULL;
    int n, data;
    printf("Enter the nodes to be created: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }

    printf("\nThe linked list is: ");
    print(); //print the dll.
}
