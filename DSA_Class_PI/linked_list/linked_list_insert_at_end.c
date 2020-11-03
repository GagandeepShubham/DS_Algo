/**
 * Linked list implementation
 * Inserting a new node at end
 **/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp -> data = x;
    if(head == NULL) //inserting the first node.
    {
        temp -> next = NULL;
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;
        while(temp1 -> next != NULL) //finding the last node of the linked list.
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp; // now the last node point to this new node
        temp -> next = NULL; // and this new node points to null.
    }
}

void print() //this will print the nodes of the linked list.
{
    struct Node *temp = head;
    printf("The linked list is: ");
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int n , data;
    printf("Enter the no. of nodes to be created: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        Insert(data);
    }
    printf("\n");
    print();
}