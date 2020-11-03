/**
 * Implementation of AVL trees also known as height balanced binary search trees.
**/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
};

node *root = NULL;

int height(node *temp)     //returns the height of the node
{
    if(temp == NULL)return 0;
    else return temp -> height;
}

int get_Balance_Factor(node *temp)  //returns the balance factor of the node.
{
    if(temp == NULL)return 0;
    else return height(temp -> left) - height(temp -> right);
}

node * Left_Rotation(node *y)
{
    node *x = y -> right; //x points to the right child of the node y which is to be rotated
    node *t = x -> left;   // t points to the left child of the node x

    //Perform Rotation
    x -> left = y;    // y now becomes the left child of the node x
    y -> right = t;   // t was cutoff due to above operation so t was made right child of y instead, property still preserved

    x -> height = max(height(x -> left), height(x -> right)) + 1;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
}

node * insert(node *root, int data)
{
    node *temp = new node();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;

    if(root == NULL)root = temp;
    else
    {
        if(data < root -> data)root -> left = insert(root -> left, data);
        else if(data > root -> data)root -> right = insert(root -> right, data);
    }

    root -> height = 1 + max(height(root -> left), height(root -> right)); //updating the height of the root

    int balance_factor = get_Balance_Factor(root); //getting the balance factor of the current node;

    //checking for imbalance in the tree after the insertion of the node. 
    if(balance_factor > 1 && data < root -> left -> data) // LL imbalance
        return Right_rotation(root);

    if(balance_factor > 1 && data > root -> left -> data) // LR imbalance
    {
        root->left = Left_rotation(root->left);
        return Right_rotation(root);
    }
    if(balance_factor < -1 && data > root -> right -> data) // RR imbalance
        return Left_rotation(root);

    if(balance_factor < -1 && data < root -> right -> data) // RL imbalance
    {
        root->right = Right_rotation(root->right);
        return Left_rotation(root);
    }
}
int main()
{
    int i, n, data;
    cout << "Enter size for BST(n): ";
    cin >> n;
    cout << "Enter data:";

    for(i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }
}
