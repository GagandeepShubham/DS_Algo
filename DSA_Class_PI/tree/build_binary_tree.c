/**
 * building a binary tree in c
 * in this program we will use a function named talloc() to dynamically allocate the memory
 * to tnode, without writing the long malloc line everytime we create a node.
 * this is a lot easier in c++, we can just use new tnode(); to allocate the memory to a 
 * tree node.
**/
#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    char *word;
    struct tnode *left;
    struct tnode *right;
};

struct tnode * talloc()  //allocates memory for the node
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

void preorder(struct tnode *root)
{
    if(root == NULL)return;
    printf("%s",root -> word);
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(struct tnode *root)
{
    if(root == NULL)return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%s", root -> word);
}

void inorder(struct tnode *root)
{
    if(root == NULL)return;
    inorder(root -> left);
    printf("%s", root -> word);
    inorder(root ->right);
}

int main()
{
    struct tnode *a = talloc();
    struct tnode *b = talloc();
    struct tnode *c = talloc();
    struct tnode *d = talloc();
    struct tnode *e = talloc();
    struct tnode *f = talloc();
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

    printf("Preorder:");
    preorder(a);

    printf("\nPostorder:");
    postorder(a);
     
    printf("\nInorder:");
    inorder(a);
}