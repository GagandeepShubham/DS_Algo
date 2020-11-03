/**
 * Program to build binary search tree.
 * Nodes are inserted by hard coding.
**/

#include<stdio.h>
#include<stdlib.h>

struct tnode
{
    int key;
    struct tnode *left;
    struct tnode *right;
};

void inorder(struct tnode *node)
{
    if(node == NULL)return;
    inorder(node -> left);
    printf("%d ", node -> key);
    inorder(node -> right);
}


void minimum(struct tnode *node)
{
    while(node != NULL && node -> left != NULL)
        node = node -> left;
    printf("The minimum element in BST is %d", node -> key);
}

void maximum(struct tnode *node)
{
    while(node != NULL && node -> right != NULL)
        node = node -> right;
    printf("The maximum element in BST is %d", node -> key);
}

struct tnode *search(struct tnode *node, int data) //to search a key in the BST
{
    if(node == NULL || node -> key == data)return node;
    else if(node -> key < data)return search(node -> right, data);
    else return search(node -> left, data);
}

struct tnode *getnode(int data)
{
    struct tnode *temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp -> key = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp; 
}
struct tnode * addtree(struct tnode *node, int data)
{
    if(node == NULL)return getnode(data); //create the node with the given data.
    if(node -> key > data) node -> left = addtree(node -> left, data);
    else if(node -> key < data)node -> right = addtree(node -> right, data);
    return node;
}

int main()
{
    //create a root node
    struct tnode *root = NULL;
    root = addtree(root, 12);
    addtree(root, 5);
    addtree(root,1);
    addtree(root,3);
    addtree(root,11);
    addtree(root,14);
    addtree(root, 2);
    addtree(root, 19);
    addtree(root, 13);
    addtree(root, 9);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    struct tnode *temp = search(root, 2);
    if(temp == NULL)printf("\nThe key %d is not present in BST\n", 2);
    else printf("The key %d is present.\n");

    temp = search(root, 500);
    if(temp == NULL)printf("The key %d is not present in BST.\n", 500);
    else printf("The key %d is present.\n");

    minimum(root); //prints the minimum element in the BST.
    printf("\n");

    maximum(root); //prints the maximum element in the BST.
    printf("\n");
}
