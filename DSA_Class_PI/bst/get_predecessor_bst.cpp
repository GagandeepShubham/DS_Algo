/**
  * Program to find the predecessor of a node in the BST.
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
vector <int> v;

struct node * insert(struct node *root, int data)     //function to insert a data in the BST.
{
    struct node *temp = new node();
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

void inorder(struct node *root)  //instead of printing the BST, this inorder function will store the data in the array.
{
    if(root == NULL)return;
    inorder(root -> left);
    v.push_back(root -> data);
    inorder(root -> right);
}

int find_predecessor(int data)
{
    inorder(root);
    int i;
    for(i = 0; i < v.size(); i++)
    {
        if(v[i] == data)break;       //find the data whose predecessor is to be found.
    }
    if(i - 1 < 0) return -1;         //if the data whose predecessor is to be found is the first node in the array, then it will have no predecessor.
    else return v[i - 1];            //else return the previous element.
}

int main()
{
    root = NULL;
    int i, n, data;

    cout << "Enter size of BST:";
    cin >> n;
    cout << "Enter data for BST:";
    for(i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Enter the key whose predecessor to be found: ";
    cin >> data;

    int predecessor = find_predecessor(data);
    if(predecessor == - 1)cout << "No Predecessor exists for " << data << "\n";
    else cout << "Predecessor for " << data << " is:" << predecessor << "\n";


    cout << "BST is:";
    for(int x:v) cout << x << " ";
    cout << "\n";
}
