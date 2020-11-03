/** Deletion of a node from a Binary search tree.
  * While deletion there can be three cases
  * case1: if the node to be deleted is a leaf node. (easy deletion)
  * case2: if the node to be deleted has one child.  (you have to take care of the child node), make connection of child with grand parent
  * case3: if the node to be deleted has both child. (you have to take care of both the child), find the inorder successor.
**/ 
#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

struct node *root;

struct node * insert(struct node *root, int data)  //inserting a node in the Binary search tree
{
    struct node *temp = new node();             //create a new node
    temp -> left = NULL;                        //assign the left child value Null
    temp -> right = NULL;                       //assign the right child value Null
    temp -> data = data;                        //assign the data to the node
    if(root == NULL)root = temp;                //if the root is null then it means the newly created node is first node of the tree.
    else
    {
        if(data < root -> data)root -> left = insert(root -> left, data);  //if node created has smaller data than root,then insert it in left subtree of root.
        else if(data >= root -> data)root -> right = insert(root -> right, data); //if node created has larger data than root, then insert it in right subtree of root.
    }
    return root;   //return the root.
}

struct node *succ(struct node *root)   //function to find the inorder successor of the given node
{
    struct node *ptr = root -> right; // you will always find the successor of the node in its right;
    if(ptr != NULL)
    {
        while(ptr -> left != NULL) //once you go to left then keep on going left , because inorder successor of a node is the smallest node in its
            ptr = ptr -> left;     //right subtree.
    }
    return ptr;                    //return the pointer to the inorder successor
}
void delete_bst(struct node *root, int data)
{
    //find the location of the node:
    struct node *ptr = root, *parent;   //ptr is a pointer to the node which is to be deleted(we have to find where it is), parent pointer is a pointer to the parent
                                        //- of that node
    int flag = false, tcase;            //the flag will be true when we find the node which is to be deleted
    while(ptr != NULL && flag == false)
    {
        if(data < ptr -> data)          //data is lesser than current ptr data
        {
            parent = ptr;               //parent gets the address which current ptr is holding
            ptr = ptr -> left;          //ptr moves to left
        }
        else if(data > ptr -> data)     //if data is more than the current ptr data
        {
            parent = ptr;               //parent gets the address which current ptr is holding
            ptr = ptr -> right;         //ptr moves to right
        }
        else if(data == ptr -> data)    //if data matches with the data of the current data, then we have found the node to be deleted.
        {
            flag = true;                //make flag true
            break;                      //exit while loop
        }
    }
    if(!flag)                           //flag will remaing false only if the node to be deleted is not present in BST
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

void inorder(struct node *root)  //print the BST by inorder traversal. [it will give increasing sorted order for BST]
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
    for(i = 0; i < n; i++)          //insert data in the BST
    {
        cin >> data;
        root = insert(root, data);
    }

    cout << "BST is: ";
    inorder(root);         //print the current BST

    cout << "\nEnter the data to be deleted from BST: ";
    cin >> data;
    delete_bst(root, data);

    cout << "\nThe BST is: ";
    inorder(root);          //print the BST after the deletion of the node
}
