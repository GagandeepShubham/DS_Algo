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

struct node * insert(struct node *root, int data)
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

void inorder(struct node *root)
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
        if(v[i] == data)break;
    }
    if(i - 1 < 0) return -1;
    else return v[i - 1];
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