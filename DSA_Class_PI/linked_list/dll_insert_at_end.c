/**
 * In this program we will insert each new node at the end of the dll.
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

void insert(int x)
{
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
    int n , data;
    printf("Enter the nodes to be created:");
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }
    printf("\nThe linked list is : ");
    print();
}