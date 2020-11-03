/**
 *Converting a given sorted array into a balanced binary search tree
**/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

node *root;
vector<int>v;


node * insert(int i, int j)
{
  if(i > j)return NULL;
  int mid = (i + j)/2;

  node * temp = new node();
  temp -> left = NULL; //these are necessary for the leaves in the both subtrees.
  temp -> right = NULL;//"-----------------------------------------------------"
  temp -> data = v[mid];
  temp -> left = insert(i, mid - 1); //inserting the mid from the left side of the current mid
  temp -> right = insert(mid + 1, j);//inserting the mid from the right side of the current mid

  return temp;
}
    
void inorder(node *root)
{
  if(root == NULL)return;
  inorder(root -> left);
  cout << root -> data << " ";
  inorder(root -> right);
}

void preorder(node *root)
{
  if(root == NULL)return;
  cout << root -> data << " ";
  preorder(root -> left);
  preorder(root -> right);
}


int main()
{   
  root = NULL;
  int i, n , data, k , l;
  cout << "Enter size: ";
  cin >> n;
  cout << "Enter data:";
  for(i = 0; i < n; i++) //gets the data
  {
    cin >> data;
    v.push_back(data);
  }
  sort(v.begin(), v.end()); //sort the data;

  //converting the sorted array to BST;
   root =  insert(0, v.size() - 1);
  //Printing the BST:
  cout << "The balanced BST is: ";
  inorder(root);

  cout << "\nThe order in which nodes should be inserted is:";
  preorder(root);

  cout << "\n";
}
