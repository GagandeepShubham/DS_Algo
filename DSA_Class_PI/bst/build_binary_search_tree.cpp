/**
 * program to implement the binary search tree.
**/

#include<iostream>
#include<vector>
using namespace std;

struct tnode
{
    int key;
    tnode *left;
    tnode *right;
};

tnode *root = NULL;
vector<int> v;

void inorder(tnode *node) //prints the BST in inorder.
{
    if(node == NULL)return;
    inorder(node -> left);
    cout << node -> key << " ";
    v.push_back(node -> key); //just for future use if, we wanted the BST nodes.
    inorder(node -> right);
}

tnode * search(tnode * node, int data) //searches a given node in the BST
{
    if(node == NULL || node -> key == data)return node;
    else if(node -> key > data) return search(node -> left, data);
    else return search(node -> right, data);
} 

int minimum(tnode *node)
{
    while(node != NULL && node -> left != NULL) //finds the min element
        node = node -> left;
    return node -> key;
}

int maximum(tnode *node) //finds the max element
{
    while(node != NULL && node -> right != NULL)
        node = node -> right;
    return node -> key;
}


void predecessor(tnode *node, int data) //finds the predecessor of the given key.
{

    if (data == minimum(root))
    {
        cout << "No predecessor for " << data << "\n";
        return;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == data)
        {
            cout << "Predecessor of " << data << " is:" << v[i-1];
            break;
        }
    }
}

void successor(tnode *node, int data) //finds the successor of the given key.
{
    if(data == maximum(root))
    {
        cout << "No successor for " << data << "\n";
        return;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == data)
        {
            cout << "Successor of " << data << " is:" << v[i+1] << "\n";
            break;
        }
    }
}

tnode * getnode(int data) //allocates memory and assigns data to the node.
{
    tnode *temp = new tnode();
    temp -> key = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

tnode* addtree(tnode *node, int data) //adding the nodes to the BST
{
    if(node == NULL)return getnode(data); //if the node is new then allocate memory and assign data
    if(node -> key < data)node -> right = addtree(node -> right, data);
    else if(node -> key > data)node -> left = addtree(node -> left, data);
    return node;
}

int main()
{
    root = addtree(root, 15); //creating the root node
    addtree(root, 6); // adding the nodes in the tree one by one.
    addtree(root, 18);
    addtree(root, 3);
    addtree(root, 7);
    addtree(root, 17);
    addtree(root, 20);
    addtree(root, 2);
    addtree(root, 4);
    addtree(root, 13);
    addtree(root, 9);
    
    cout << "inorder:";
    inorder(root);
    cout << "\n";

    tnode *temp = search(root, 2);
    if(temp == NULL)cout << 2 << " is not present in BST\n";
    else cout << 2 << " is present in BST\n";

    temp = search(root, 500);
    if(temp == NULL)cout << 500 << " is not present in BST\n";
    else cout << 500 << " is present in BST\n";

    cout << "The minimum element in BST:" << minimum(root) << "\n";
    //prints the minimum element in the BST

    cout << "The maximum element in BST:" << maximum(root) << "\n";
    //prints the maximum element in the BST

    predecessor(root, 9); //find the predecessor of key 9
    cout << "\n";
    successor(root, 9); //find the successor of the key 9.

}
