#include <iostream>
using namespace std;

int* function1(int n){
    int *p=(int *)malloc(n*sizeof(int));
    return p;
}
int main()
{
    int *a;
    a=function1(4);
    a[0]=10;
    a[1]=10;
    a[2]=10;
    a[3]=10;
    for(int i=0;i<4;++i){
        printf("%d ",a[i]);
    }
}