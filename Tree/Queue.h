// Circular queue for creating binary tree
#include <stdio.h>
#include <stdlib.h>
struct treenode{
    struct treenode* left;
    int data;
    struct treenode* right;
};

struct queue{
    int size;
    int front;
    int rear;
    struct treenode **a;
};

void create(struct queue* q,int size){
    q->size=size;
    q->front=0;
    q->rear=0;
    q->a=(struct treenode **)malloc(size*(sizeof(struct treenode*)));
}

void enqueue(struct queue* q,struct treenode* nodep){
    if( (q->rear+1)%q->size == q->front )
        printf("Queue is full.\n");
    else{
        q->rear=((q->rear)+1)%q->size;
        q->a[q->rear]=nodep;
    }
}
struct treenode* dequeue(struct queue* q){
    struct treenode* x=NULL;
    if( q->front == q->rear )
        printf("Queue is empty.\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];
        q->a[q->front]=NULL;
    }
    return x;
}
int isEmpty(struct queue q){
    return q.front==q.rear;
}