/**
 * program to build a binary tree.
**/
#include<iostream>
#include<string>
using namespace std;

struct tnode
{
    string word;
    tnode * left;
    tnode *right;
};

//tnode *root = NULL;

void preorder(tnode *root)
{
    if(root == NULL)return;
    cout << root -> word;
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(tnode *root)
{
    if(root == NULL)return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> word;
}

void inorder(tnode *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    cout << root -> word;
    inorder(root -> right);
}

int main()
{
    tnode *a = new tnode(); //root node
    tnode *b = new tnode();
    tnode *c = new tnode();
    tnode *d = new tnode();
    tnode *e = new tnode();
    tnode *f = new tnode();

    if(a && b && c && d && e && f)
    {
        a -> word = "a"; //root node
        a -> left = b;
        a -> right = c;
        b -> word = "b";
        b -> left = NULL;
        b -> right = NULL;
        c -> word = "c";
        c -> left = d;
        c -> right = e;
        d -> word = "d";
        d -> left = NULL;
        d -> right = f;
        e -> word = "e";
        e -> left = NULL;
        e -> right =NULL;
        f -> word = "f";
        f -> left = NULL;
        f -> right =NULL;
    }
    cout << "Preorder:";
    preorder(a);

    cout << "\nPostorder:";
    postorder(a);
     
    cout << "\nInorder:";
    inorder(a);
}