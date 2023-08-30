#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct treenode{
    struct treenode* left;
    int data;
    struct treenode* right;
};

struct queuenode{
    struct treenode* qnodedata; // aka treenode pointer
    struct queuenode* next;
};
struct queuenode* qhead=NULL;
struct queuenode* qfront=NULL;
struct queuenode* qrear=NULL;

void enqueue_treenode(struct treenode* tn){
    struct queuenode* temp=malloc(sizeof(struct queuenode));
    if(temp==NULL)
        printf("Queue is full.");
    else{
        temp->qnodedata=tn;
        temp->next=NULL;
        if(qhead==NULL){
            qfront=temp;
            qrear=temp;
            qhead=qfront;
        }
        else{
            qrear->next=temp;
            qrear=temp;
        }
    }
}

struct treenode* dequeue_treenode(){
    struct treenode* tnode;
    if(qfront==NULL)
        printf("Queue is empty.");
    else{
        tnode=qfront->qnodedata;
        qfront=qfront->next;
    }
    return tnode;
}

void addNodeToTree(){
    struct treenode* DequeueNode=dequeue_treenode();
    int lvalue=0,rvalue=0;
    printf("Enter value of left child of %d: ",DequeueNode->data);
    scanf("%d",&lvalue);
    printf("Enter value of right child of %d: ",DequeueNode->data);
    scanf("%d",&rvalue);
    if(lvalue!=-1){
        struct treenode* ltemp=malloc(sizeof(struct treenode));
        ltemp->left=NULL;
        ltemp->data=lvalue;
        ltemp->right=NULL;
        DequeueNode->left=ltemp;
        enqueue_treenode(ltemp);
    }
    else if(rvalue!=-1){
        struct treenode* rtemp=malloc(sizeof(struct treenode));
        rtemp->left=NULL;
        rtemp->data=rvalue;
        rtemp->right=NULL;
        DequeueNode->right=rtemp;
        enqueue_treenode(rtemp);
    }
}

void inorderTraversal(struct treenode* tp){
    if(tp!=NULL){
        inorderTraversal(tp->left);
        printf("%d ",tp->data);
        inorderTraversal(tp->right);
    }
}

int main()
{
    struct treenode* root=malloc(sizeof(struct treenode));
    root->data=30;
    root->left=NULL;
    root->right=NULL;
    enqueue_treenode(root);
    addNodeToTree();
    addNodeToTree();
    addNodeToTree();
    addNodeToTree();
    inorderTraversal(root);
}