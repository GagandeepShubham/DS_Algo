/**
 * This program demonstrates circular linked list.
**/
 
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
int n; //nodes to be created

void insert(int x)
{
    static int count = 0;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> prev = NULL;
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
        temp -> prev = temp1;
    }
    count++;   
    if(count == n) //all nodes are created
    {
        temp -> next = head; //linked the last node with the first
        head -> prev = temp; //linked the first node with the last.
    }
}

void print()
{
    struct Node *temp = head;
    int count = 0;
    while(1)
    {
        printf("%d ",temp -> data);
        temp = temp -> next;
        count++;
        if(count == n)break;
    }
}
int main()
{
    head = NULL;
    int data;
    printf("Nodes to be created ?: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("\nThe circular linked list : ");
    print();
}
