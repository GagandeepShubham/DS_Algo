/**This program demonstrates the deletion of a node from begining.
 * In this program it is supposed that all the new nodes which are to be inserted 
 * are inserted at end.
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
    if(head == NULL) //it is the first node
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
void delete_from_front()
{
    struct Node *temp = head;
    head = head -> next;
    temp -> next = NULL;
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
    printf("\n");
}
int main()
{
    head = NULL;
    int n , data;
    printf("Enter the nodes to be created: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d", &data);
        Insert(data);
    }
    printf("\nThe linked list is: ");
    print();

    printf("\nAfter deleting the first node: ");
    delete_from_front();
    print();
}
