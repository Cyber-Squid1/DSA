#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addToEmpty(struct node* head,int value){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=value;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addAtEnd(struct node* head,int value){
    struct node* tp=head;
    struct node* temp=malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=value;
    temp->prev=NULL;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
struct node* createEntireList(struct node* head){
    int n=0,value=0;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    if(n==0)
        return head;
    printf("Enter value for node 1: ");
    scanf("%d",&value);
    head=addToEmpty(head,value);
    for(int i=1;i<n;++i){
        printf("Enter value for node %d: ",i+1);
        scanf("%d",&value);
        head=addAtEnd(head,value);
    }
    return head;
}
void printDoublyLinkedList(struct node* tp){
    // Printing linked list using Recursion
    if(tp!=NULL){
        printf("%d ",tp->data);
        printDoublyLinkedList(tp->next);
    }

    // Printing linked list using Loop(Iteration)
    // while(tp!=NULL){
    //     printf("%d ",tp->data);
    //     tp=tp->next;
    // }
}
int findMaxElement(struct node* head){
    struct node* tp=head;
    int maxele=tp->data;
    while(tp!=NULL){
        if(maxele<tp->data)
            maxele=tp->data;
        tp=tp->next;
    }
    return maxele;
}
int main()
{
    struct node* head=NULL;
    head=createEntireList(head);
    struct node* ptr=head;
    printf("The doubly Linked List is: ");
    printDoublyLinkedList(head);
    int maxelement=findMaxElement(head);
    printf("\nThe maximum element of the linked list is: %d",maxelement);
}