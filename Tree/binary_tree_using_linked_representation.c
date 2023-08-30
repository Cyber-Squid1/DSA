#include <stdio.h>
#include <stdlib.h>

struct treenode{
    struct treenode* left;
    int data;
    struct treenode* right;
};
struct treenode* root=NULL;

struct queuenode{
    struct treenode* nodep;
    struct queuenode* next;
};
struct queuenode* head=NULL;
struct queuenode* front=NULL;
struct queuenode* rear=NULL;

void enqueue(struct treenode* treep){
    struct queuenode* temp=malloc(sizeof(struct queuenode));
    if(temp==NULL)
        printf("Queue is full.\n");
    else{
        temp->nodep=treep;
        temp->next=NULL;
        if(front==NULL){
            front=temp;
            rear=temp;
            head=front;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
}

struct treenode* dequeue(){
    struct treenode* tn;
    if(front==NULL)
        printf("Queue is empty.\n");
    else{
        tn=front->nodep;
        front=front->next;
    }
    return tn;
}

void addNodeToTree(){
    struct treenode* tp=dequeue();
    int rvalue=0,lvalue=0;
    printf("Enter value of left node: ");
    scanf("%d",&lvalue);
    printf("Enter value of right node: ");
    scanf("%d",&rvalue);
    if(lvalue!=-1){
        struct treenode* ltemp=malloc(sizeof(struct treenode));
        ltemp->data=lvalue;
        ltemp->left=NULL;
        ltemp->right=NULL;
        enqueue(ltemp);
    }
    if(rvalue!=-1){
        struct treenode* rtemp=malloc(sizeof(struct treenode));
        rtemp->data=rvalue;
        rtemp->left=NULL;
        rtemp->right=NULL;
        enqueue(rtemp);
    }
}

int main()
{
    root->data=36;
    root->left=NULL;
    root->right=NULL;
    enqueue(root);
    addNodeToTree();
}