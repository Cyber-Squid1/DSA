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
void enqueue(int value){
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
void dequeue(){
    if(front==NULL)
        printf("Queue is empty.\n");
    else{
        struct node* del=front;
        front=front->next;
        free(del);
        del=NULL;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    displayQueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    displayQueue();
}