#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
    unsigned int value;
    struct node* left;
    struct node* right;
};

struct node* bTree;
struct node* root=bTree;
struct node* newNode(unsigned int val)
{
    struct node* k=new(struct node);
    k->value=val;
    k->left=NULL;
    k->right=NULL;
    return k;
}

void printBtree(struct node* i)
{
    if(i->left!=NULL)printBtree(i->left);
    
    if(i->right!=NULL)printBtree(i->right);
    
    if(i!=NULL)cout<<i->value<<'\n';
}

bool findValue(unsigned int val, struct node* i){
    struct node* p=i;
    if(p==NULL)
        return 0;
    if(p->value==val)
    return 1;
    else if(p->value > val)
        findValue(val, p->left);
    else
        findValue(val, p->right);
}


void deleteTree(struct node* i)
{
    if(i->left!=NULL)
        deleteTree(i->left);
    
    if(i->right!=NULL)
        deleteTree(i->right);

    if(i!=NULL)
    {
        delete(i);
        i=NULL;
    }
}

int main()
{
    root=newNode(90);
    root->left=newNode(20);
    root->right=newNode(95);
    root->left->right=newNode(53);
    root->left->left=newNode(19);
    root->right->left=newNode(92);
    root->right->right=newNode(101);

    printf("Value %d %s", 92, findValue(92,root)==1?"Has been found!\n":"Has not been found!\n");
    printf("Value %d %s", 93, findValue(93,root)==1?"Has been found!\n":"Has not been found!\n");
    
    printBtree(root);
    return 0;
}