/**Program to find minimum element in a BST **/

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
    struct node *temp = new node();
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> data = data;
    if(root == NULL)root = temp;
    else
    {
        if(data < root -> data) root -> left = insert(root -> left, data);  //if data to be inserted is lesser than root data then insert in LST of root.
        else if(data >= root -> data) root -> right = insert(root -> right, data); //if data to be inserted is greater than root data then insert in RST of root.
    }
   return root; 
}

int find_min()
{
    struct node *temp = root;
    while(temp != NULL && temp -> left != NULL)   //go to the leftmost node.
        temp = temp -> left;
    
    return temp -> data;
}
void inorder(struct node *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}
int main()
{
    root = NULL;
    int i, n , data;
    cout << "Enter total size for BST:";
    cin >> n;
    
    for(i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "BST is: ";
    inorder(root);

    int min = find_min();
    cout << "\nMinimum element in BST:" << min << "\n";
}
