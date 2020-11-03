/** Program to implement a linked list.
 * Insertion of each new node is done at the beginning of the list.
 **/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;
void Insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); //allocating memory to the node.

    temp -> data = data; //since data is to be inserted everytime so insert it here only.

    if(head == NULL) //no node in the linked list yet
    {
        head = temp;
        temp -> next = NULL;
    }
    else //for now we will insert at beginning of the linked list.
    {
        temp -> next = head;
        head = temp;
    }
    
}
void print()
{
    struct Node *temp = head;
    while(temp != NULL) //keep on printing the data till the pointer points to null.
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int n; //number of nodes to be created;
    int data; //data to be inserted.
    printf("Enter the number of nodes to be created: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }
    printf("\n");
    print();
}