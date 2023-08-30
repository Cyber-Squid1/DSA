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
int checkIfSorted(struct array *ap){
    for(int i=0;i<(ap->length)-1;++i){
        if(ap->a[i]>ap->a[i+1])
            return 0;
    }
    return 1;
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
    arr.a[7]=1;
    arr.length=8;
    checkIfSorted(&arr) ? printf("The array is SORTED.") : printf("The array is NOT SORTED");
}