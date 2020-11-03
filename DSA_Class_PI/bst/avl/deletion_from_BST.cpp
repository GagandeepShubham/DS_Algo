/** Deleting a node from an AVL tree than rebalancing it if imbalance occurs **/
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
  int height;
};

node *root;

int height(node *root)
{
  if(root == NULL)return 0;
  else return root -> height;
}

int get_Balance_factor(node *root)
{
  if(root == NULL)return 0;
  else return height(root -> left) - height(root -> right);
}

node * Left_rotation(node *y)
{
   node *x = y -> right; // x points to the right child of the y
   node *t = x -> left; // t will point to the left child of x

   //Perform Rotations
   x -> left = y; //making the node y , the left child of node x
   y -> right = t;// t was cutoff after y came in its place so, now making t the right child of y

   //updating the heights
   y -> height =  max(height(y -> left), height(y -> right));
   x -> height =  max(height(x -> left), height(x -> right));

   return x; //returning the new root;
}

node * Right_rotation(node *y)
{
   node *x = y -> left; //x now points to the left child of y
   node *t = x -> right; // t now points to the right child of node x.

   //Perform the rotation
   x -> right = y; // making y the right child of the node x
   y -> left = t; //t was cutoff after y came in its place so, adjustting t.

   //updating the heights
   y -> height =  max(height(y -> left), height(y -> right));
   x -> height =  max(height(x -> left), height(x -> right));

   return x; //returning the new node.
}

node * insert(node *root, int data)
{
   node *temp = new node(); //creating the new node for insertion
   temp -> data = data;
   temp -> right = NULL;
   temp -> left = NULL;
   temp -> height = 0;   

   if(root == NULL)root = temp;
   else
   {
        if(data < root -> data)root -> left = insert(root -> left, data);
        else if(data > root -> data)root -> right = insert(root -> right, data);
        else return root;
   }

   //update height of the node
   root -> height = 1 + max(height(root -> left), height(root -> right));

   //get the balance factor
   int bf = get_Balance_factor(root);

   //check for the imbalance
   if(bf > 1 && data < root -> left -> data) //LL imbalance
        return Right_rotation(root);

   if(bf > 1 && data > root -> left -> data) // LR imbalance
   {   root -> left = Left_rotation(root -> left);
       return Right_rotation(root);
   }

   if(bf < -1 && data > root -> right -> data) //RR imbalance
        return Left_rotation(root);

   if(bf < -1 && data < root -> right -> data) // RL imbalance
   {    root -> right = Right_rotation(root -> right);
        return Left_rotation(root);
   }
   
   return root;
}

node * min_node(node *root) //finding the minimum node.
{
   node *temp = root;
   while(temp -> left != NULL)
        temp = temp -> left;

   return temp;
}

//Delete the node from the AVL tree.
node * delete_Node(node *root, int data)
{
    if(root == NULL)return root;
    
    if(data < root -> data)root -> left = delete_Node(root -> left, data); //key to be deleted in LST
    else if(data > root -> data)root -> right = delete_Node(root -> right, data); //key to be deleted in RST
    else //key to be deleted is the current node we are on
    {
        node *temp;
        if(root -> left == NULL || root -> right == NULL) // either one of the child is NULL
        {
          if(root -> left == NULL)temp = root -> right; //if left child is NULL 
          else if(root -> right == NULL)temp = root -> left; //if right child is NULL

          if (temp == NULL)  //if both left child and right child are NULL
          {
            temp = root; //simply make the temp point to that node which is to be deleted
            root = NULL; //assign null to it
          }
          else //there is one child
          {
            *root = *temp; //the non empty child's content(the subtree of the child of the node which is to be deleted). 
            free(temp); //free the temp because it is now redundant(it is not needed because we put all the content of temp in the root , so this is now kind of duplicate value);
          }
        }
        else //if the node to be deleted has both child
        {
          temp = min_node(root -> right); //finding the inorder successor of the node, thats why we are finding the min_node in the right of the node to be deleted.
          root -> data = temp -> data; //assign the data of the inorder successor to the node which is to be deleted.
          root -> right = delete_Node(root -> right, temp -> data); //delete the node having the data of inordersuccessor in the right subtree , because it is now duplicate.
        }
    }

    if(root == NULL)return root;

    //update height of current node
    root -> height =  1 + max(height(root -> left), height(root -> right));

    int bf = get_Balance_factor(root);

    //if the node becomes unbalanced

    //LL case
    //balance factor of root->left will be >= 0 , when root -> left's height(root -> left's LST) >= height(root -> left's RST)
    if(bf > 1 && get_Balance_factor(root -> left) >= 0)
        return Right_rotation(root);

    //LR case
    //balance factor of root-> left will be less than 0 when root -> left's  RST will have greater height than root -> left's LST.
    if(bf > 1 && get_Balance_factor(root -> left) < 0) 
    { 
        root -> left = Left_rotation(root -> left);
        return Right_rotation(root);
    }

    //RR case
    //balance factor of root -> right will be <= 0, when root -> right's RST's height >= root -> right's LST's height.
    if(bf < -1 && get_Balance_factor(root -> right) <= 0) 
        return Left_rotation(root);
    
    //RL case
    //balance factor of root -> right will be greater than 0, when root -> right's RST's height > root -> right's LST's height.
    if(bf < -1 && get_Balance_factor(root -> right) > 0)
    {
      root -> right = Right_rotation(root -> right);
      return Left_rotation(root);
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
  int i, n, data;
  cout << "Enter the size for the BST: ";
  cin >> n;
  cout << "Enter the data: ";
  for(i = 0 ; i < n;i++)
  {
    cin >> data;
    root = insert(root, data);
  }
  cout << "The current AVL tree is: ";
  preorder(root);

  cout << "\nEnter data to be deleted from AVL tree: ";
  cin >> data;
  root = delete_Node(root, data);

  cout << "After deletion of the node,tree is: ";
  preorder(root);
  cout << "\n";

  cout << "\nThe inorder of the BST: ";
  inorder(root);
  cout << "\n";
}
