/**
 * This program performs linear search to find a given key in the linked list.
 * if the key is not found then an appropriate message will be displayed.
 * IF the key is found then position based on 0 indexing will be displayed.
 * The linked list is created in this program by inserting the nodes at the end of the program.
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

int search_key(int key)
{
    int pos = 0;
    struct Node *temp = head;
    while(temp -> next != NULL)
    {
        if(temp -> data == key)break;
        else
        {
            pos++;
            temp = temp -> next;
        }
    }
    if(pos < 0)return -1;
    else return pos;
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
    int n, data, key;
    printf("Enter nodes to be created:");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);
        Insert(data);
    }

    printf("\nThe linked list is:");
    print();

    printf("\nEnter the key to be searched: ");
    scanf("%d", &key);

    int pos = search_key(key); // if -1 is returned then it means key is not in the linked list.
    if(pos < 0)
        printf("\nThe key is not present in the linked list");
    else
    {
        printf("\nThe key: %d is found at position: %d", key, pos);
    }
    
}