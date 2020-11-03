/**
 * word counting problem, it counts the occurences of the words occured in the tree.
 * remember: strcmp returns 0 if both the strings given as arguments matches exactly
 * strcmp returns -1 if the first argument's first char is lesser than the second argument's second character.
 * else stcmp will return 1.
**/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100
#define BUFSIZE 100
char buf[BUFSIZE]; //buffer for ungetch

struct tnode
{
    char *word; //points to the text
    int count; // the count of the words
    struct tnode *left;
    struct tnode *right;
};

int bufp = 0; //next free position in buffer.
int getch() //get a possibly pushed back character
{
    return(bufp > 0)? buf[--bufp]:getchar();
}
void ungetch(int c)
{
    //push character back on input
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}

struct tnode *talloc()
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
//make a duplicate of s
char * strduplicate(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1); // +1 of '\0'
    if(p != NULL)
        strcpy(p, s);
    return p;
}

void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p -> left);
        printf("%d %s\n", p -> count, p -> word);
        treeprint(p -> right);
    }
}

struct tnode *addtree(struct tnode *p, char *word)
{
    /**
     * cond will have 0 , if in strcmp(), the word matches with p -> word
     * cond will have -1, if in strcmp(), the first alphabet of word is smaller than first alphabet
     * of p -> word.
     * else cond will have 1.
    **/
    int cond; 
    if(p == NULL) //a new word has arrived
    {
        p = talloc();
        p -> word = strduplicate(word);
        p -> count = 1;
        p -> left = p -> right = NULL;
    }
    else if((cond = strcmp(word, p -> word)) == 0) //if word already exists increment count
    {
        p -> count++;
    }
    else if(cond < 0) //else continue searching tree
    {
        p -> left = addtree(p -> left, word); //when the word is lesser than root word
    }
    else p -> right = addtree(p -> right, word); //when the word is greater than root word.
    return p;
}
int getword(char *word, int lim)
{
    int c; char *w = word; //will hold the base address of the word
    while(isspace(c= getch())); //skip space

    if(c != EOF) *w++ = c; //assigning the character of the word to the word array.
    if(!isalpha(c))  //if c is not an alphabet then your word is over.
    {                //isalpha returns non-zero for a-z,A-Z
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++) //other wise keep on getting the alphabets.(see w is being incremented to get a character)
    {
        if(!isalnum(*w = getch())) //getting the characters until and unless its not a digit and storing them at w.
        {
            ungetch(*w); //if the character is a digit, then ungetch() it.
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int main()
{
    char word[MAXWORD]; //to store the word
    struct tnode *root;
    root = NULL;
    printf("Enter the sentence: ");
    while(getword(word, MAXWORD) != EOF) //read words until ctrl - z and enter is pressed.
    {
        if(isalpha(word[0])) //if the first letter is an alphabet
            root = addtree(root, word); //add word ,update count
    }
    treeprint(root); //prints word and counts using inorder traversal. 
    return 0;
}