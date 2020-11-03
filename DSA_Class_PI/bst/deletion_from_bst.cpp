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
        if(data < root -> data)root -> left = insert(root -> left, data);
        else if(data >= root -> data)root -> right = insert(root -> right, data);
    }
    return root;
}

struct node *succ(struct node *root)
{
    struct node *ptr = root -> right; // you will always find the successor of the node in its right;
    if(ptr != NULL)
    {
        while(ptr -> left != NULL) //once you go to left then keep on going left , because successor of the node will be the 
            ptr = ptr -> left;     //left most node in the right subtree of the given node whose successor is to be found.
    }
    return ptr;
}
void delete_bst(struct node *root, int data)
{
    //find the location of the node:
    struct node *ptr = root, *parent;
    int flag = false, tcase;
    while(ptr != NULL && flag == false)
    {
        if(data < ptr -> data)
        {
            parent = ptr;
            ptr = ptr -> left;
        }
        else if(data > ptr -> data)
        {
            parent = ptr;
            ptr = ptr -> right;
        }
        else if(data == ptr -> data)
        {
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        cout << "Data " << data << " does'nt exists, no deletion!";
        return;
    }
    if(ptr -> left == NULL && ptr -> right == NULL)tcase = 1; //node to be deleted is a leaf.
    else 
    {
        if(ptr -> left != NULL && ptr -> right != NULL)tcase = 3; //node has both left and right child.
        else tcase = 2; //node has only one child.
    }

    //deletion
    switch(tcase)
    {
        case 1:
            if(parent -> left == ptr) parent -> left = NULL;
            else parent -> right = NULL;
            break;
        
        case 2:
            if(parent -> left == ptr) //the node to be deleted is the left child of the node.
            {
                if(ptr -> left != NULL)
                {
                    parent -> left = ptr -> left; //ptr's left child is the left child of its grandparent.
                    ptr = NULL; 
                }
                else
                {
                    parent -> left = ptr -> right; //ptr's right child is the left child of its grandparent.
                    ptr = NULL;
                }
            }
            else if(parent -> right == ptr) //the node to be deleted is the right child.
            {
                if(ptr -> left != NULL)
                {
                    parent -> right = ptr -> left; //ptr's left child is now the right child of its grandparent.
                    ptr = NULL;
                }
                else
                {
                    parent -> right = ptr -> right; //ptr's right child is now the right child of its grandparent.
                    ptr = NULL;
                }
            }    
            break;
        
        case 3:                  //when the node contains both the left child and right child.
            struct node *ptr1 = succ(ptr); //find the successor of the node to be deleted.
            int item = ptr1 -> data; //data of the successor is stored in the item.
            delete_bst(root, item); //successor is deleted from the bst.
            ptr -> data = item;   //now the node which is to be deleted, its data is replaced with the successors node, which means we
            break;                //we deleted the given node only nothing else.

    }

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

    cout << "\nEnter the data to be deleted from BST: ";
    cin >> data;
    delete_bst(root, data);

    cout << "\nThe BST is: ";
    inorder(root);
}