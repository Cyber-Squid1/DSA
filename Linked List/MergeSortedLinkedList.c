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

struct node* mergeLinkedList(struct node* first,struct node* second){
    struct node* third=NULL;
    struct node* tp=NULL;
    
    if(first->data<second->data){
        third=first;
        tp=first;
        first=first->next;
        third->next=NULL;
    }
    else{
        third=second;
        tp=second;
        second=second->next;
        third->next=NULL;
    }
    while(first && second){
        if(first->data < second->data){
            tp->next=first;
            tp=first;
            first=first->next;
            tp->next=NULL;
        }
        else{
            tp->next=second;
            tp=second;
            second=second->next;
            tp->next=NULL;
        }
    }
    if(first){
        tp->next=first;
    }
    else if(second){
        tp->next=second;
    }
    return third;
}

int main()
{
    struct node *head1=malloc(sizeof(struct node));
    head1->data=2;
    head1->next=NULL;
    struct node *ptr=head1;
    ptr=add_at_end(ptr,5);
    ptr=add_at_end(ptr,10);
    ptr=add_at_end(ptr,15);
    ptr=head1;
    printf("First Linked List: ");
    while(ptr!=NULL){
        printf(" %d",ptr->data);
        ptr=ptr->next;
    }
    struct node *head2=malloc(sizeof(struct node));
    head2->data=3;
    head2->next=NULL;
    struct node *ptr2=head2;
    ptr2=add_at_end(ptr2,4);
    ptr2=add_at_end(ptr2,11);
    ptr2=add_at_end(ptr2,13);
    ptr2=head2;
    printf("\n");
    printf("Second Linked List: ");
    while(ptr2!=NULL){
        printf(" %d",ptr2->data);
        ptr2=ptr2->next;
    }
    struct node* head3=mergeLinkedList(head1,head2);
    struct node* ptr3=head3;
    printf("\n");
    printf("Merged Linked List: ");
    while(ptr3!=NULL){
        printf(" %d",ptr3->data);
        ptr3=ptr3->next;
    }
    return 0;
}