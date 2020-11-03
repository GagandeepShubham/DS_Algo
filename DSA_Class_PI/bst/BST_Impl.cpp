/**
 * Implementation of a binary search tree.
 * Functions implemented are as following:-
 * insert() - insert function takes two arguments, first is the root pointer and other is the data to be inserted in the BST
 * it compares the data with the root data and determines whether to insert data into the left subtree or the right subtree.
 * print_bst() - this function prints the BST by calling inorder function
 * inorder() - this function prints the nodes of the BST  using inorder traversal. [gives the sorted sequence for BST]
 * NOTE : declare the root globally , it will make the implementation a lot easier.
**/
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

struct node *root; //root of BST.

struct node * insert(struct node *root ,int data) //takes pointer to root and data to be inserted as an argument and recursively finds the correct positions for the data.
{
    node *temp = new node(); //allocating memory for a new node.
    temp -> left = NULL;     //assigning null to the left pointer of the node since there is no left child as of now.
    temp -> right = NULL;    //assigning null to the right pointer of the node since there is no right child as of now.
    temp -> data = data;     //assigning data to the node.
    if(root == NULL)root = temp;  //if root is null, that means it is the first node to be inserted.
    else                          //else we have to find the correct position for the node in the existing BST.
    {
        if(data < root -> data)  //if the data of the current node is lesser than the data of the root node.
        {
            root -> left = insert(root -> left, data); //call insert for the left of root since the node must be inserted in the left subtree somehwere
        }
        else if(data >= root -> data) //if the data of the current node is bigger than the data of the root node.
        {
            root -> right = insert(root -> right, data); //call insert for the right of root since the node must be inserted in the right subtree somewhere.
        }
    }
   return root;  //returns the root pointer
}

void inorder(node *root) //prints the tree in inorder format
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}
void print_bst() //calls inorder() to print the BST nodes data in a sorted sequence
{
    inorder(root);
    cout << "\n";
}
int main()
{
    root = NULL;
    int n , data;
    cout << "Enter size for BST:";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter data:";
        cin >> data;
        root = insert(root, data);
    }

    print_bst(); //prints the bst
}