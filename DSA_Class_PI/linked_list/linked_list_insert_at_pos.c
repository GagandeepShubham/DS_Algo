/**
 * Linked list implementation.
 * Insert at the given position.(a particular node.)
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
    struct Node *temp = malloc(sizeof(struct Node));
    temp -> data = x;
    if(head == NULL) //linked list is empty
    {
        temp -> next = NULL;
        head = temp;
    }
    else // insert at end;
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

void Insert_at_position(int x, int position) // insert the node at a given position
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node -> data = x;
    int count = position - 1;
    struct Node *temp = head;
    if(position == 0) //if the position of the node to be inserted is the 0th position
    {
        new_node -> next = head;
        head = new_node;
    }
    else //any other position for the node to be inserted.
    {
        for(int i = 1; i < count; i++)
        {
            temp = temp -> next;
        }
        new_node -> next = temp -> next;
        temp->next = new_node;
    }
}

void print() //prints the linked list.
{
    struct Node *temp = head;
    printf("\nThe linked list is: ");
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
    int n, data, position;
    printf("Enter the nodes to be created: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }

    //getting the data and position for a new node.
    printf("\nEnter the data for a new node to be inserted: ");
    scanf("%d", &data);
    printf("\nEnter the position for the node: ");
    scanf("%d", &position);

    printf("\nThe linked before inserting new node: "); //printing the list.
    print();
    Insert_at_position(data, position); //insert at the given position.

    printf("\nThe linked list after inserting the new node: ");
    print(); // printing the list.
    printf("\n");

}