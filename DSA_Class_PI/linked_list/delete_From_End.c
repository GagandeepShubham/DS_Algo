/**
 * Program to demonstrate the deletion in linked list.
 * First the linked list will be created and the new nodes will be inserted at the end of the linked list.
**/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
struct Node *head;

void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    if(head == NULL) //it is the first node to be inserted.
    {
        head = temp;
        temp -> next = NULL;
    }
    else
    {
        struct Node *temp1 = head;
        while(temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
        temp -> next = NULL;
    }
}
void delete_from_end()
{
    struct Node *temp = head;
    struct Node *p;
    while(temp -> next != NULL)
    {
        p = temp;
        temp = temp -> next;
    }
    p -> next = NULL;
    free(temp);
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
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }

    printf("\nThe linked list is:");
    print();  //will display the list.

    printf("\nAfter deletion of the last node:");
    delete_from_end();
    print(); //will display the list.
}