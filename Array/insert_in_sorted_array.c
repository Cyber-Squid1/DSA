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
void insertInSortedArray(struct array* ap,int value){
    int i=(ap->length)-1;
    while(value<ap->a[i]){
        ap->a[i+1]=ap->a[i];
        --i;
    }
    ap->a[i+1]=value;
    ++(ap->length);
}
int main()
{
    struct array arr;
    arr.length=0;
    // printf("Enter size of array: ");
    // scanf("%d",&arr.size);
    arr.size=10;
    arr.a=(int *)malloc(arr.size*sizeof(int));
    arr.a[0]=4;
    arr.a[1]=17;
    arr.a[2]=25;
    arr.a[3]=29;
    arr.a[4]=45;
    arr.a[5]=68;
    arr.a[6]=72;
    arr.a[7]=91;
    arr.length=8;
    insertInSortedArray(&arr,35);
    displayArray(arr);
}