/**
 * This program is implemented from the course lecture slide.
 * The word counting problem using c++
**/
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#define deb(x) cout << #x << ":" << x << "\n";
using namespace std;

struct tnode
{
    string word;
    int count;
    tnode *left;
    tnode *right;
};

tnode * addtree(tnode *node, string temp)
{
    int cond; //for strcmp
    /* cout << temp << "\n"; */
    if(node == NULL)
    {
        //cout << "entered here";
        //deb("entered here");
        node = new tnode();
        node -> word = temp;
        node -> count = 1;
        node -> left = NULL;
        node -> right = NULL;
    }
    else if(node -> word == temp)
    {
        //deb("got here");
        node -> count++;
    }
    else if(node -> word > temp)
    {
        node -> left = addtree(node -> left, temp);
        //deb("added in left");
    }
    else 
    {
        node -> right = addtree(node -> right, temp);
        //deb("added in right");
    }
    return node;
}

void treeprint(tnode *node) //print the nodes of the tree
{
    if(node == NULL)return;
    treeprint(node -> left);
    cout << node -> word << ":" << node -> count << "\n";
    treeprint(node -> right);
}
int main()
{
    tnode *root = NULL;
    vector<char> v; //to store the word as it comes.
    cout << "Enter a sentence:";
    string s, temp;
    getline(cin, s); //getting the string;
    int i;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            temp += '\0';
            root = addtree(root, temp); //adding the word to the BST.
            temp = "";
        }
        else temp += s[i]; //each time a character will be added to the string
        if(i == s.size() - 1)
        {
            temp += '\0';
            root = addtree(root, temp);
        } 
    }

    treeprint(root);
    

}
