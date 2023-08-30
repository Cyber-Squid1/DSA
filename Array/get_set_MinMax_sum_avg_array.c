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
int getElementAtPosition(struct array *ap,int position){
    return ap->a[position];
}
void setElementAtPosition(struct array *ap,int value,int position){
    ap->a[position]=value;
}
int findMinElement(struct array arr){
    int minele=arr.a[0];
    for(int i=1;i<arr.length;++i){
        if(arr.a[i]<minele)
            minele=arr.a[i];
    }
    return minele;
}
int findMaxElement(struct array arr){
    int maxele=arr.a[0];
    for(int i=1;i<arr.length;++i){
        if(arr.a[i]>maxele)
            maxele=arr.a[i];
    }
    return maxele;
}
int sumOfAllElements(struct array arr){
    int sum=0;
    for(int i=0;i<arr.length;++i){
        sum=sum+arr.a[i];
    }
    return sum;
}
double averageOfElements(struct array arr){
    double sum=sumOfAllElements(arr);
    return (sum/arr.length);
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
    printf("The element at position 5 is: %d",getElementAtPosition(&arr,5));
    setElementAtPosition(&arr,0,5);
    setElementAtPosition(&arr,5,0);
    printf("\n");
    displayArray(arr);
    printf("\n");
    printf("Minimum element= %d\n",findMinElement(arr));
    printf("Maximum element= %d\n",findMaxElement(arr));
    printf("Total= %d\n",sumOfAllElements(arr));
    printf("The average is: %.2f",averageOfElements(arr));
}