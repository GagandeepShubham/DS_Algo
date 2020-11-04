/**
 * This program takes a position from the user and deletes the node from that position.
 * User should provide the position on 0 based indexing.
 * The linked list is created by inserting each node at the end.
**/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void Insert(int x) //inserting the nodes into the linked list.
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    if(head == NULL) // it is the first node.
    {
        head = temp;
        temp -> next = NULL;
    }
    else // the node is not the first node.
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

void delete_from_pos(int position)
{
    if(position == 0) //the node to be deleted is the first node.
    {
        struct Node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
    else
    {
        int count = 0;
        struct Node *temp = head;
        struct Node *p; //p will point the node just before the node which is to be deleted.
        while(count != position)
        {
            p = temp;
            temp = temp -> next;
            count++; 
        }
        p -> next = temp -> next;
        temp -> next = NULL;
        free(temp);
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
    int n, data, pos;
    printf("Enter the nodes to be created for the linked list:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }

    printf("\nThe linked list is:");
    print(); //prints the linked list.

    printf("\nEnter the position from where node is to be deleted:");
    scanf("%d", &pos);

    delete_from_pos(pos);
    printf("\nThe linked list is now:");
    print();
}
