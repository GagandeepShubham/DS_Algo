/**
 * Finds the successor of the data provided only if it exists else print an appropriate message.
 * Followings are the functions used:
 * insert() - takes two args, first - pointer to root, second - data to be inserted, and then goes on to find the appropriate position.
 * find_successor() - takes an argument data which , in turn call inorder function, then returns the successor of the data.
 * inorder() - instead of printing the nodes directly , it will store the data in the vector.
**/
#include<iostream>
#include<vector>
using namespace std;

struct node 
{
    int data;
    node *left;
    node *right;
};

struct node *root;
vector<int> v;

struct node * insert(struct node *root , int data)
{
    struct node *temp = new node();
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> data = data;
    if(root == NULL)root = temp;
    else
    {
        if(data < root -> data) root -> left = insert(root -> left, data);
        else if(data >= root -> data) root -> right = insert(root -> right, data);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    v.push_back(root -> data);
    inorder(root -> right);   
}

int find_successor(int data)
{
    int i;
    inorder(root);
    for(i = 0; i < v.size(); i++)
    {
        if(v[i] == data)break;
    }
    if(i + 1 == v.size())return -1;
    else return v[i + 1];
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


    cout << "Enter key whose successor is to be found:";
    cin >> data;

    int successor = find_successor(data);
    if(successor == -1)cout << "Successor for " << data << " doesn't exist!\n";
    else cout << "Successor is: " << successor << "\n";

    cout << "The BST is :";
    for(int x:v)cout << x << " ";
}