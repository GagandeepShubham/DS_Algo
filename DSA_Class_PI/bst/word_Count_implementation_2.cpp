#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node
{
    string data;
    int count;
    node *left;
    node *right;
};

struct node *root;

struct node * insert(struct node *root, string data)
{
    struct node *temp = new node();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    if(root == NULL)
    {
        root = temp;
        root -> count++;
    }
    else
    {
        if(data < root -> data) root -> left = insert(root -> left, data);
        else if(data > root -> data)root -> right = insert(root -> right, data);
        else if(data == root -> data)root -> count++;
    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> data << ":" << root -> count << "\n";
    inorder(root -> right);
}
int main()
{
    root = NULL;
    int i, n;
    vector<string> v;
    string s, r = "";

    cout << "Enter the string: ";
    getline(cin , s);
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            r += '\0';
            v.push_back(r);
            r = "";
        }
        else r += s[i];
    }
    for(i = 0; i < v.size(); i++)
    {
        root = insert(root, v[i]);
    }

    inorder(root);
}