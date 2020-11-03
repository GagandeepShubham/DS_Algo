//allocate the memory for a tree node
#include<iostream>
#include<string>
using namespace std;

struct tnode
{
    string word;
    struct tnode *left;
    struct tnode *right;
};

int main()
{
    tnode *node = new tnode();
    node -> left = NULL;
    node -> right = NULL;
    node -> word = "gagan";

    cout << "welcome " << node -> word << "\n";
}