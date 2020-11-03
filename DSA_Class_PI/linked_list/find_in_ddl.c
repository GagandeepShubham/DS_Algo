/**
 * This program takes a key from user and finds the position in the linked list.
 * if the key doesn't exists in the linked (list then print an appropriate message.
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
    if(head == NULL) head = temp;
    else
    {
        struct Node *temp1 = head;
        while (temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp;
        temp -> prev = temp1;
    }
}
int find_key(int key)
{
    int position = 1; //counting the nodes from 1.
    struct Node *temp = head;
    while(temp -> data != key)
    {
        temp = temp -> next;
        position++;
    }
    if(temp == NULL)position = -1;
    return position;
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
    int n, data, key, pos;
    printf("Enter the nodes to be created in the linked list:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter data:");
        scanf("%d", &data);
        insert(data);
    }
    printf("\nThe linked list is:");
    print(); //displays the linked list.

    printf("\nEnter the key to be searched:");
    scanf("%d", &key);
    pos = find_key(key);
    if (pos < 0)
    {
        printf("The key doesn't exist in linked list!\n");
    }
    else
    {
        printf("\nThe key is present at position: %d", pos);
    }
    
}