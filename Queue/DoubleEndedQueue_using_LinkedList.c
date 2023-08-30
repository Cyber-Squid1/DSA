#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

void displayQueue(){
    struct node* tp=front;
    if(tp==NULL)
        printf("Queue is empty.\n");
    else{
        printf("The queue is: ");
        while(tp!=NULL){
            printf("%d ",tp->data);
            tp=tp->next;
        }
        printf("\n");
    }
}

void enqueueRear(int value){
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Queue is full.\n");
    else{
        temp->data=value;
        temp->next=NULL;
        if(front==NULL){
            front=temp;
            rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeueRear(){
    int x=-1;
    if(rear==NULL)
        printf("Queue is empty.");
    else{
        struct node* tp=front;
        while(tp->next!=rear)
            tp=tp->next;
        tp->next=NULL;
        x=rear->data;
        free(rear);
        rear=tp;
    }
    return x;
}
void enqueueFront(int value){
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Queue is full.");
    else{
        temp->data=value;
        temp->next=front;
        front=temp;
    }
}

int dequeueFront(){
    int x=-1;
    if(front==NULL)
        printf("Queue is empty.\n");
    else{
        struct node* del=front;
        front=front->next;
        x=del->data;
        free(del);
        del=NULL;
    }
    return x;
}

int main()
{
    enqueueRear(30);
    enqueueRear(40);
    enqueueRear(50);
    displayQueue();
    enqueueFront(20);
    enqueueFront(10);
    displayQueue();
    printf("Element dequeue rear: %d\n",dequeueRear());
    printf("Element dequeue rear: %d\n",dequeueRear());
    displayQueue();
    printf("Element dequeue front: %d\n",dequeueFront());
    printf("Element dequeue front: %d\n",dequeueFront());
    displayQueue();
}