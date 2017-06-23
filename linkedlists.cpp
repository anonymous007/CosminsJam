#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int x;
    node *next;
};
node *root;
void nodeInit()
{
    root=new node;
    root->next=0;
    root->x=1;
}
void insertNewNode(int val)
{
    node *iter;
    iter=root;
    if(iter!=0)
        while(iter->next!=0)
            iter=iter->next;
    iter->next=new node;
    iter=iter->next;
    iter->next=0;
    iter->x=val;
}
void printListElements()
{
    node *iter;
    iter=root;
    if(iter!=0)
        while(iter->next!=0)
            {printf("%d ",iter->x);iter=iter->next;}
    printf("%d\n",iter->x);
}
void deleteLastNode()
{
    node *iter=root;
    while(iter->next->next!=0)
        iter=iter->next;
    iter->next=NULL;
}
void deleteNode(int nodeNum)
{
    node *it=root;
    size_t i=0;
    while(i+1!=nodeNum)
    {
        if(it->next==0){printf("\nIt appears that you wanted to delete a node whose index number %d does not exist.\n", nodeNum);return;}
        it=it->next;
        ++i;
    }
    it->x=it->next->x;
    it->next=it->next->next;
}
unsigned int getSize()
{
    size_t i=1;
    node* it=root;
    while(it->next!=0){++i;it=it->next;}
    return (unsigned int) i;
}
int main()
{
    nodeInit();
    insertNewNode(3);
    insertNewNode(5);
    insertNewNode(6);
    insertNewNode(31);
    insertNewNode(35);
    insertNewNode(333);
    insertNewNode(36);
    insertNewNode(36);
    insertNewNode(36);
    insertNewNode(396);
    printf("The size of the linked list is: %u\n", getSize());
    deleteLastNode();
    printListElements();
    printf("The size of the linked list is: %u\n", getSize());
    deleteNode(3);
    printListElements();
    printf("The size of the linked list is: %u\n", getSize());
    return 0;
}
