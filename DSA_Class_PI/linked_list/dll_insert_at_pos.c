/**
 * Program to insert a given node at the given position.
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
    temp -> next = NULL;
    temp -> prev = NULL;
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
void insert_at_pos(int pos, int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node -> data = x;
    new_node -> next = NULL;
    new_node -> prev = NULL;

    struct Node *temp = head; //temp will point to the node before which we have to insert our node.
    if(pos == 1 || pos == 0)
    {
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
    else
    {
        int count = 1;
        while (count < pos && temp -> next != NULL) //reach the node just before the insertion has to be done
        {
            temp = temp->next;
            count++;
        }
        if(count < pos) //node is to be inserted at the end, because if count < pos it means pos doesn't exist in linked list.
        {
            temp -> next = new_node;
            new_node -> prev = temp;
        }
        else
        {
            new_node->next = temp;
            temp->prev->next = new_node;
            new_node->prev = temp->prev;
            temp->prev = new_node;    
        }
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
    int n, data , pos;
    printf("Enter nodes to be created: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) //this part creates the linked list.
    {
        printf("Enter data: ");
        scanf("%d", &data);
        insert(data);
    }

    printf("\nEnter the position for new node: ");
    scanf("%d",&pos);

    printf("\nEnter the data to be inserted: ");
    scanf("%d",&data);
    insert_at_pos(pos, data);

    printf("\nThe linked list is: ");
    print();
}