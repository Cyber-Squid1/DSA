#include <stdio.h>
struct matrix{
    int A[10];
    int n;
};
void setElementRowMajor(struct matrix* m,int i,int j,int value){
    if(i>=j){
        int index=(i*(i-1)/2)+(j-1); // row major mapping
        m->A[index]=value;
    }
}
void setElementColumnMajor(struct matrix* m,int i,int j,int value){
    if(i>=j){
        int index=((m->n)*(j-1)) - ((j-2)*(j-1)/2) + (i-j); // column major mapping
        m->A[index]=value;
    }
}
int getElement(struct matrix m,int i,int j){
    if(i>=j){
        int index=(i*(i-1)/2)+(j-1);
        return m.A[index];
    }
    return 0;
}
void printMatrix(struct matrix m){
    int i,j;
    for(i=1;i<=m.n;++i){
        for(j=1;j<=m.n;++j){
            if(i>=j){
                int index=(i*(i-1)/2)+(j-1);
                // int index=((m.n)*(j-1)) - ((j-2)*(j-1)/2) + (i-j);
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
    setElementRowMajor(&m,1,1,10);
    setElementRowMajor(&m,2,1,9);
    setElementRowMajor(&m,2,2,8);
    setElementRowMajor(&m,3,1,7);
    setElementRowMajor(&m,3,2,6);
    setElementRowMajor(&m,3,3,5);
    setElementRowMajor(&m,4,1,4);
    setElementRowMajor(&m,4,2,3);
    setElementRowMajor(&m,4,3,2);
    setElementRowMajor(&m,4,4,1);

    printMatrix(m);
    printf("\n");
    for(int x=0;x<10;++x){
        printf("%d ",m.A[x]);
    }
    printf("\n");
    setElementColumnMajor(&m,1,1,10);    
    setElementColumnMajor(&m,2,1,9);
    setElementColumnMajor(&m,2,2,8);
    setElementColumnMajor(&m,3,1,7);
    setElementColumnMajor(&m,3,2,6);
    setElementColumnMajor(&m,3,3,5);
    setElementColumnMajor(&m,4,1,4);
    setElementColumnMajor(&m,4,2,3);
    setElementColumnMajor(&m,4,3,2);
    setElementColumnMajor(&m,4,4,1);
    printMatrix(m);
    printf("\n");
    for(int x=0;x<10;++x){
        printf("%d ",m.A[x]);
    }
}