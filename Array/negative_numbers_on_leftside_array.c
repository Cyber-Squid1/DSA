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
void shiftNegativeElementsTOLeft(struct array* ap){
    int temp=0;
    int i=0;
    int j=(ap->length)-1;
    while(i<j){
        while(ap->a[i]<0){++i;}
        while(ap->a[j]>=0){--j;}
        if(i<j){
            temp=ap->a[i];
            ap->a[i]=ap->a[j];
            ap->a[j]=temp;
        }
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
    arr.a[0]=-5;
    arr.a[1]=4;
    arr.a[2]=23;
    arr.a[3]=20;
    arr.a[4]=-7;
    arr.a[5]=68;
    arr.a[6]=-12;
    arr.a[7]=17;
    arr.a[8]=32;
    arr.a[9]=-8;
    arr.length=10;
    printf("Before shifting.\n");
    displayArray(arr);
    shiftNegativeElementsTOLeft(&arr);
    printf("\nAfter shifting\n");
    displayArray(arr);
}