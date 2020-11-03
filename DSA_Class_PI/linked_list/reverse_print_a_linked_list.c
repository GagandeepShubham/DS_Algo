/**
 * This program creates a linked list.
 * It will print the linked list in reverse.
 * NOTE: it doesn't actually reverse it, it just print it in the reverse.
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
    temp -> next = NULL;
    if(head == NULL) head = temp;
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

void print_reverse(struct Node *p)
{
    if(p -> next != NULL)
    {
        print_reverse(p -> next);
    }
    printf("%d ", p -> data);
}
int main()
{
    head = NULL;
    int n , data;
    printf("Enter the nodes to be created:");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }

    printf("\nThe linked list from head to tail: ");
    print(); //prints the linked list in original order.

    printf("\nThe linked from tail to head: ");
    print_reverse(head);


}