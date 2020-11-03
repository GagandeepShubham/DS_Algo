/**
 * Searching a node in a Binary search tree, if found then print a message saying node found else print an appropriate message.
 * Following functions are implemented:-
 * insert() - this function takes two arguments  - a root pointer, and a data value and it then creates a new node and insert the data
 * in appropriate position in the BST.
 * search_bst() - this function takes two arguments -  a root pointer, and a data value and it then search the bst for the data value given
 * recursively.
**/
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *root;

node * insert(node * root, int data) //insert a node in the BST
{
    node * temp = new node();
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> data = data;
    if(root == NULL)root = temp;    //if the node just created is the first node to be inserted.
    else
    {
        if(data < root -> data)
        {
            root -> left = insert(root -> left, data); //if node just created is smaller than the root node then insert in left subtree
        }
        else if(data >= root -> data)
        {
            root -> right = insert(root -> right, data);  //if node just created is larger than the root node then insert in right subtree.
        }
    }
   return root;           //return root.
}

struct node * search_data(struct node *root , int data)
{
    struct node *temp;
    if(root == NULL || root -> data == data)temp = root;      //if the data to be searched is found or the tree doesn't contain that data.
    else if(root -> data > data)temp = search_data(root -> left, data); //if data to be searches is lesser than the root data then search in LST.
    else if(root -> data < data) temp = search_data(root -> right, data); //if data to be searched is greater than the root data then search in RST.
    return temp;  //return pointer to the node.
}

int main()
{
    root = NULL;
    int i, n, data;
    cout << "Enter size for BST:";
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Enter data to search:";
    cin >> data;
    struct node *temp = search_data(root, data);
    if(temp) 
    {
        cout << "Search Successfull!\n";
        cout << "Data " << data << " found!";
    }
    else cout << "Data " << data << " is not present in BST!";
}
