#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
void isEmpty(struct node* top){
    if(top==NULL)
        printf("The stack is empty.");
}
                                /* here stack full condition becomes true when heap memory is completely full  */
void isFull(){
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL)
        printf("Stack is full.");
}
struct node* push(struct node* top,int value){
    struct node* temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack overflow.");
        return top;
    }
    else{
        temp->data=value;
        temp->next=top;
        top=temp;
        return top;
    }
}
struct node* pop(struct node* top){
    if(top==NULL){
        printf("Stack underflow.\n");
        return top;
    }
    else{
        struct node* temp=top;
        top=top->next;
        printf("%d ",temp->data);
        free(temp);
        return top;
    }
}
int peek(struct node* top,int position){
    struct node* tp=top;
    for(int i=0;tp!=NULL && i<position-1;++i){
        tp=tp->next;
    }
    if(tp!=NULL)
        return tp->data;
    else
        return -1;
}
int main()
{
    struct node* top=NULL;
    top=push(top,10);
    top=push(top,20);
    top=push(top,30);
    top=push(top,40);
    top=push(top,50);
    top=push(top,60);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    // top=pop(top);
    printf("Data at position 3 is: %d",peek(top,3));
}