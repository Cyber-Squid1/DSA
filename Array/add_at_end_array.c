#include <stdio.h>
#include <stdlib.h>

struct array{
    int *a;
    int size;
    int length;
};
void displayArray(struct array arr){
    printf("The arra is: ");
    for(int i=0;i<arr.length;++i){
        printf("%d ",arr.a[i]);
    }
}
void addAtEnd(struct array* ap,int value){
    ap->a[ap->length]=value;
    (ap->length)++;
}
int main()
{
    struct array arr;
    arr.length=0;
    // printf("Enter size of array: ");
    // scanf("%d",&arr.size);
    arr.size=4;
    arr.a=(int *)malloc(arr.size*sizeof(int));
    arr.length=arr.size;
    arr.a[0]=10;
    arr.a[1]=10;
    arr.a[2]=10;
    arr.a[3]=10;
    addAtEnd(&arr,20);
    displayArray(arr);
    printf("\nLength %d",arr.length);
}