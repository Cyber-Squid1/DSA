#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack{
    int size;
    int *arr;
    int top;
};
bool isEmpty(struct stack* s){
    if(s->top==-1)
        return true;
    return false;
}
bool isFull(struct stack* s){
    if(s->top==s->size-1)
        return true;
    return false;
}
void push(struct stack* s,int value){
    if(s->top==s->size-1)
        printf("Stack overflow.\n");
    else{
        ++(s->top);
        s->arr[s->top]=value;
    }
}
int pop(struct stack* s){
    int x=-1;
    if(s->top==-1)
        printf("Stack underflow.\n");
    else{
        x=s->arr[s->top];
        --(s->top);
    }
    return x;
}
int peek(struct stack* s,int posfromtop){
    int i=s->top,x=-1;
    for(i;posfromtop>1;--i,--posfromtop){}
    x=s->arr[i];
    return x;
}
int stackTop(struct stack* s){
    int x=-1;
    if(s->top==-1){
        printf("The stack is empty.");
        return x;
    }
    x=s->arr[s->top];
    return x;
}
int main()
{
    struct stack s;
    printf("Enter size of stack: ");
    scanf("%d",&s.size);
    s.arr=(int *)malloc(s.size*sizeof(int));
    s.top=-1;
    // isEmpty(&s) ? printf("Stack is EMPTY.\n") : printf("Stack is NOT EMPTY.\n");
    // isFull(&s) ? printf("Stack is FULL.\n") : printf("Stack is NOT FULL.\n");
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    push(&s,60);
    // printf("%d ",pop(&s));
    // printf("%d ",pop(&s));
    // printf("%d ",pop(&s));
    // printf("%d ",pop(&s));
    // printf("%d ",pop(&s));
    // printf("%d ",pop(&s));
    printf("\n");
    printf("The element at position 3 is: %d\n",peek(&s,3));
    printf("Element on top of stack is: %d",stackTop(&s));
}