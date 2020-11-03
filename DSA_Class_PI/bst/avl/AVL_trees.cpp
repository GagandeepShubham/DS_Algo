#include<iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
  int height;
};

struct node *root;
int height(node *root) //to get the height of the subtree
{
  if(root == NULL)return 0;
  else return root -> height;
}

int get_Balance_Factor(node *root) //to get the balance factor
{
  if(root == NULL)return 0;
  else return height(root -> left) - height(root -> right);
}

node * Right_rotate(node *y)
{
  node *x = y -> left; //x is now pointing to the y's left child
  node *t = x -> right; // t is now pointing to the x's right child if any

  //Perfroming rotation
  x -> right = y; //y is now right child of the node x;
  y -> left = t; // t was cutoff from the right of x so, now t will be the left child of the node y

  //Update height
  y -> height = max(height(y -> left), height(y -> right));
  x -> height = max(height(x -> left), height(x -> right));

  //return the new root;
  return x;
}

node * Left_rotate(node *y)
{
  node *x = y -> right; //x now points to the right child of the node y
  node *t = x -> left; // t now points to the left child of the node x if any.

  //Perform rotation
  x -> left = y; // y is now left child of x
  y -> right = t; //t was cutoff because y came in its place so, now preserving BST property t is right child of y

  //Update heights
  y -> height = max(height(y -> left), height(y -> right));
  x -> height = max(height(x -> left), height(x -> right));
    
  //return the new root;
  return x;
}

node * insert(node *root, int data) //to insert a node into existing AVL tree
{
  node *temp = new node();
  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  temp -> height = 0;
  if(root == NULL)root = temp;
  else
  {
    if(data < root -> data) root -> left = insert(root -> left, data);
    else if(data > root -> data)root -> right = insert(root -> right,data);
    else return root;
  }
    
  root -> height = 1 + max(height(root -> left), height(root -> right)); //updating the height of the root; 
  int balance_factor = get_Balance_Factor(root); //getting the balance factor after the insertion.
    
  if(balance_factor > 1 && data < root -> left -> data) //LL imbalance
        return Right_rotate(root);
  
  if(balance_factor > 1 && data > root -> left -> data) //LR imalance
  {
        root -> left = Left_rotate(root -> left);
        return Right_rotate(root);
  }

  if(balance_factor < -1 && data > root -> right -> data) //RR imbalance
        return Left_rotate(root);

  if(balance_factor < -1 && data < root -> right -> data) //RL imbalance
  {
        root -> right = Right_rotate(root -> right);
        return Left_rotate(root);
  }
    
  return root;
}
void preorder(node *root)
{
  if(root == NULL)return;
  cout << root -> data << " ";
  preorder(root -> left);
  preorder(root -> right);
}

void inorder(node *root)
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
  cout << "Enter size of AVL Tree(n): ";
  cin >> n;
  cout << "Enter data for AVL Tree: ";
  for(i = 0; i < n; i++)
  {
    cin >> data;
    root = insert(root, data);
  }

  cout << "Preorder of the AVL tree is: ";
  preorder(root);

  cout << "\nInorder of the AVL tree is: ";
  inorder(root);
  cout << "\n";
}
