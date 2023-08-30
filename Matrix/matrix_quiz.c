#include <stdio.h>

int main()
{
    int i=3,j=3,Temp=0,C=10;
    int A[i][j];
    for(int x=0;x<i;++x){
        for(int y=0;y<j;++y){
            A[x][y]=0;
        }
    }
    for(int x=0;x<i;++x){
        for(int y=0;y<j;++y){
            Temp = A [x][y] + C;
            A[x][y] = A[y][x];
            A[y][x] = Temp - C;
        }
    }
    for(int x=0;x<i;++x){
        for(int y=0;y<j;++y){
            printf("%d ",A[x][y]);
        }
        printf("\n");
    }
}