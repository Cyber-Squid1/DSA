#include <stdio.h>
#include <stdlib.h>

int findMaxElement(int *a){
    int max=a[0];
    for(int i=0;i<10;++i){
        if(max<a[i])
            max=a[i];
    }
    return max;
}
void countSort(int *a){
    int x=0,y=0;
    int max=findMaxElement(a);
    int *countArray=calloc(max+1,sizeof(int));
    for(int i=0;i<10;++i)
        ++countArray[a[i]];
    
    for(int i=0;i<10;++i)
        a[i]=0;
    
    while(x!=max+1){
        if(countArray[x]==0)
            ++x;
        else if(countArray[x]!=0){
            a[y]=x;
            --countArray[x];
            ++y;
        }
    }
    printf("Sorted array is: ");
    for(int i=0;i<10;++i){
        printf("%d ",a[i]);
    }
}

int main()
{
    int *array=calloc(10,sizeof(int));
    array[0]=6;
    array[1]=3;
    array[2]=9;
    array[3]=10;
    array[4]=15;
    array[5]=6;
    array[6]=8;
    array[7]=12;
    array[8]=3;
    array[9]=6;
    printf("Unsorted array is: ");
    for(int i=0;i<10;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
    countSort(array);
}