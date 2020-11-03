#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *root;

struct node * insert(struct node *root, int data)
{
    struct node * temp = new node();
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> data = data;

    if(root == NULL)root = temp;
    else
    {
        if(data < root -> data)root -> left = insert(root -> left, data);
        else if(data >= root -> data)root -> right = insert(root -> right, data);
    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int find_max()
{
    struct node *temp = root;
    while(temp != NULL && temp -> right != NULL)
        temp = temp -> right;

    return temp -> data;
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
        root = insert(root, data);
    }

    cout << "BST is: ";
    inorder(root);

    int max = find_max();
    cout << "\nMaximum element in BST:" << max;

}