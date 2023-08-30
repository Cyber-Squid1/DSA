#include <stdio.h>
#include <stdlib.h>
int x=0;
struct node{
    int data;
    struct node* next;
};

struct node* insertSortedChainHashNode(struct node* head,int value){
    struct node* temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(head == NULL || value < head->data){
        temp->next=head;
        head=temp;
    }
    else{
        struct node* tp=head;
        while(tp->next!=NULL && tp->next->data < value)
            tp=tp->next;
        temp->next=tp->next;
        tp->next=temp;
    }
    return head;
}

void searchHashTable(struct node* search,int key){
    while (search!=NULL)
    {
        if(key==search->data){
            x=1;
            printf("Key %d found",key);
            return;
        }
        search=search->next;
    }
    x=0;
    printf("Key %d not found",key);
}
