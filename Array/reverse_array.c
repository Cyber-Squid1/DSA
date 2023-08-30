#include <stdio.h>
#include <stdlib.h>

struct array{
    int *a;
    int size;
    int length;
};
void displayArray(struct array arr){
    printf("The array is: ");
    for(int i=0;i<arr.length;++i){
        printf("%d ",arr.a[i]);
    }
}
void swap(int *x,int *y){
    int *temp=x;
    y=x;
    y=temp;
}
void reverseArray(struct array *ap){
    int temp=0;
    for(int i=0,j=ap->length-1;i<j;++i,--j){
        temp=ap->a[i];
        ap->a[i]=ap->a[j];
        ap->a[j]=temp;
    }
}
int main()
{
    struct array arr;
    arr.length=0;
    // printf("Enter size of array: ");
    // scanf("%d",&arr.size);
    arr.size=10;
    arr.a=(int *)malloc(arr.size*sizeof(int));
    arr.a[0]=0;
    arr.a[1]=1;
    arr.a[2]=2;
    arr.a[3]=3;
    arr.a[4]=4;
    arr.a[5]=5;
    arr.a[6]=6;
    arr.a[7]=7;
    arr.a[8]=8;
    arr.a[9]=9;
    arr.length=10;
    printf("Before reversing\n");
    displayArray(arr);
    reverseArray(&arr);
    printf("\nAfter reversing\n");
    displayArray(arr);
}