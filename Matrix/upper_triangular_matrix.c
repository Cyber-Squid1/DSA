#include <stdio.h>

struct matrix{
    int A[20];
    int n;
};
void setElement(struct matrix* m,int i,int j,int value){
    if(j>=i){
        int index=(j*(j-1)/2)+(i-1); // column major mapping
        m->A[index]=value;
    }
}
int getElement(struct matrix m,int i,int j){
    if(j>=i){
        int index=(j*(j-1)/2)+(i-1);
        return m.A[index];
    }
    return 0;
}
void printMatrix(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;++i){
        for(j=1;j<=m.n;++j){
            if(j>=i){
                int index=(j*(j-1)/2)+(i-1);
                printf("%d ",m.A[index]);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n=4;
    setElement(&m,1,1,10);
    setElement(&m,1,2,9);
    setElement(&m,2,2,8);
    setElement(&m,1,3,7);
    setElement(&m,2,3,6);
    setElement(&m,3,3,5);
    setElement(&m,1,4,4);
    setElement(&m,2,4,3);
    setElement(&m,3,4,2);
    setElement(&m,4,4,1);
    printMatrix(m);
    printf("\n");
    for(int x=0;x<10;++x){
        printf("%d ",m.A[x]);
    }
}