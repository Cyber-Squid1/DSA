#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *a;
};

void enqueue(struct queue* q,int value){
    if( (q->rear+1)%q->size == q->front )
        printf("Queue is full.\n");
    else{
        q->rear=(q->rear+1)%q->size;
        q->a[q->rear]=value;
    }
}
void dequeue(struct queue* q){
    int x=-1;
    if( q->front == q->rear )
        printf("Queue is empty.\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->a[q->front];
        q->a[q->front]=0;
        printf("Element dequeued is: %d\n",x);
    }
}
void front(struct queue* q){
    int x=-1;
    if(q->front == q->rear)
        printf("Queue is empty.\n");
    else
        printf("The element in front is: %d\n",q->a[(q->front)+1]);
}
void rear(struct queue* q){
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is empty.\n");
    else
        printf("The element at rear is: %d\n",q->a[q->rear]);
}
int main()
{
    struct queue q;
    printf("Enter size of queue: ");
    scanf("%d",&q.size);
    q.a=(int *)calloc(q.size,sizeof(int));
    q.front=-1;
    q.rear=-1;
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,60);
    enqueue(&q,70);
    enqueue(&q,80);
    front(&q);
    rear(&q);
}