#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int A[10];
    int n;
};

void setElement(struct matrix* m,int i,int j,int value){
    if(i==j){
        m->A[i-1]=value;
    }
}

int getElment(struct matrix m,int i,int j){
    if(i==j){
        return m.A[i-1];
    }
    return 0;
}
void printMatrix(struct matrix m){
    int i,j;
    for(i=0;i<m.n;++i){
        for(j=0;j<m.n;++j){
            if(i==j)
                printf("%d ",m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n=5;
    setElement(&m,1,1,5);
    setElement(&m,2,2,4);
    setElement(&m,3,3,3);
    setElement(&m,4,4,2);
    setElement(&m,5,5,1);
    printMatrix(m);
}