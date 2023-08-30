#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
void printLinkedList(struct node* head){
    printf("The linked list is:");
    struct node* tp=head;
    while(tp!=NULL){
        printf(" %d",tp->data);
        tp=tp->next;
    }
}
int checkIfSorted(struct node* head){
    int x=-20000;
    struct node* tp=head;
    while(tp!=NULL){
        if(tp->data<x)
            return 0;
        x=tp->data;
        tp=tp->next;
    }
    return 1;
}
struct node* addToEmpty(struct node* head,int value){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addAtEnd(struct node* head,int value){
    struct node* temp=malloc(sizeof(struct node));
    struct node*tp=head;
    temp->data=value;
    temp->next=NULL;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    return head;
}
struct node* createEntreLinkedList(struct node* head){
    int n=0,value=0;
    printf("Enter number of nodes in the linked list: ");
    scanf("%d",&n);
    printf("Enter value of node 1: ");
    scanf("%d",&value);
    head=addToEmpty(head,value);
    for(int i=1;i<n;++i){
        printf("Enter value of node %d: ",i+1);
        scanf("%d",&value);
        head=addAtEnd(head,value);
    }
    return head;
}

int main()
{
    struct node* head=NULL;
    head=createEntreLinkedList(head);
    printLinkedList(head);
    checkIfSorted(head) ? printf("\nThe linked list is SORTED") : printf("\nThe linked list is NOT SORTED");
}