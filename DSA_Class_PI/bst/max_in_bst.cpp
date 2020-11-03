//Program to find the maximum element in a binary search tree.

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *root;

struct node * insert(struct node *root, int data)  //insert a node into a BST.
{
    struct node * temp = new node();   //create a node.
    temp -> left = NULL;
    temp -> right = NULL; 
    temp -> data = data;               //assign data to the node.
 
    if(root == NULL)root = temp;       //if the node created is the first node.
    else
    {
        if(data < root -> data)root -> left = insert(root -> left, data);
        else if(data >= root -> data)root -> right = insert(root -> right, data);
    }
    return root;
}

void inorder(struct node *root)  //print the BST using inorder traversal
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int find_max()          //find the max element in the BST
{
    struct node *temp = root;
    while(temp != NULL && temp -> right != NULL)  //keep on going right until you get a node whose right is NULL
        temp = temp -> right;

    return temp -> data;       //return the data of the rightmost node.
}

int main()
{
    root = NULL;
    int i, n , data;
    cout << "Enter size for BST:";
    cin >> n;
    cout << "Enter data: ";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);      //insert a node with given data in the BST.
    }

    cout << "BST is: ";
    inorder(root);

    int max = find_max();
    cout << "\nMaximum element in BST:" << max;  //print the maximum element

}
