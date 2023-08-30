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
                printf("%d ",m.A[index]);
            }
            else if(j>i){
                int index=(j*(j-1)/2)+(i-1);
                printf("%d ",m.A[index]);
            }
        }
        printf("\n");
    }
}
int main()
{
    struct matrix m;
    m.n=4;
    setElementRowMajor(&m,1,1,0);
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
}