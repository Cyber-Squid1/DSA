#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node* add_at_end(struct node *head,int value)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    
    head->next=temp;
    return temp;
}

struct node* reverseLinkedList(struct node* head){
    struct node* p=head;
    struct node* q=NULL;
    struct node* r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=2;
    head->next=NULL;
    struct node *ptr=head;
    ptr=add_at_end(ptr,5);
    ptr=add_at_end(ptr,10);
    ptr=add_at_end(ptr,15);
    ptr=add_at_end(ptr,1);
    ptr=add_at_end(ptr,47);
    ptr=head;
    printf("Before: ");
    while(ptr!=NULL){
        printf(" %d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    head=reverseLinkedList(head);
    ptr=head;
    printf("AFter: ");
    while(ptr!=NULL){
        printf(" %d",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}