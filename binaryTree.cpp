#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


struct node{
    unsigned int value;
    struct node* left;
    struct node* right;
};

struct node* bTree;
struct node* root=bTree;
struct node* newNode(unsigned int value)
{
    struct node *result=NULL;
    result=new(node);
    result->value=value;
    result->left=NULL;
    result->right=NULL;
    return result;
}

void insertNewNode(unsigned int value)
{
    if(root==NULL)
    {
        root=newNode(value);
        return;
    }
    if(root->value > value)
    {
        root=root->left;
        insertNewNode(value);
    }else{
        root=root->right;
        insertNewNode(value);
    }
}

void printBinaryTree(node* b)
{
    struct node* i=b;
    if(i->value>=0&&i!=NULL){
        cout<<i->value<<"\n";
        printBinaryTree(i->left);
        printBinaryTree(i->right);
    }
}

void initTree(node* root)
{
    if(root==NULL)
    {
        root=new node;
        root->value=0;
        root->left=NULL;
        root->right=NULL;
    }
}
void deleteTree(struct node* i)
{
    if(i->left!=NULL)deleteTree(i->left);
    if(i->right!=NULL)deleteTree(i->right);
    if(i!=NULL)
    {
        delete(i);
        i=NULL;
    }
}


int main()
{
    root=newNode(60);
    root->left=newNode(20);
    root->right=newNode(62120);
    root->left->right=newNode(25);
    root->left->left=newNode(13);

    printBinaryTree(root);
    deleteTree(root);

    return 0;
}