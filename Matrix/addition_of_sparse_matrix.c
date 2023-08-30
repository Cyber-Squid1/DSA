#include <stdio.h>
#include<string.h>
int main()
{
    int x=1,i=1,j=1;
    int A[6][3]={5,1,2,3,3,5,
                6,4,2,2,4,1,
                5,6,7,2,5,4};
    int B[7][3]={5,2,2,3,3,4,5,
                6,2,5,3,6,4,1,
                6,3,5,2,7,9,8};
    int C[9][3];
    C[0][0]=5;
    C[0][1]=6;
    C[0][2]=9;
    while(i!=5 || j!=6){
        if(A[i][0] < B[j][0]){
                C[x][0]=A[i][0];
                C[x][1]=A[i][1];
                C[x][2]=A[i][2];
                ++i;
                ++x;
        }
        else if(A[i][0] > B[j][0]){
            C[x][0]=B[j][0];
            C[x][1]=B[j][1];
            C[x][2]=B[j][2];
            ++j;
            ++x;
        }
        else if(A[i][0] == B[j][0]){
            if(A[i][1] < B[j][1]){
                C[x][0]=A[i][0];
                C[x][1]=A[i][1];
                C[x][2]=A[i][2];
                ++i;
                ++x;
            }
            else if(A[i][1] > B[j][1]){
                C[x][0]=B[j][0];
                C[x][1]=B[j][1];
                C[x][2]=B[j][2];
                ++j;
                ++x;
            }
            else if(A[i][1] == B[j][1]){
                C[x][0]=A[j][0];
                C[x][1]=A[j][1];
                C[x][2]=A[i][2]+B[j][2];
                ++j;
                ++i;
                ++x;
            }
        }
    }
    for(int p=0;p<3;++p){
        for(int q=0;q<9;++q){
            printf("%d ",C[p][q]);
        }
        printf("\n");
    }
    
}