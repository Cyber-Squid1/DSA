#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term{
    int coeff;
    int expo;
};

struct poly{
    int n;
    struct term *t;
};

int main()
{
    int x=0,sum=0;
    struct poly p;
    printf("Enter size of polynomial: ");
    scanf("%d",&p.n);
    p.t=malloc(p.n*sizeof(struct term));
    printf("Enter polynomial terms: ");
    for(int i=0;i<p.n;++i){
        printf("Enter coefficient for term %d:",i+1);
        scanf("%d",&p.t[i].coeff);
        printf("Enter exponent for term %d:",i+1);
        scanf("%d",&p.t[i].expo);
    }
    
    printf("\n");
    printf("Enter value of x: ");
    scanf("%d",&x);
    for(int i=0;i<p.n;++i){
        sum+=p.t[i].coeff * pow(x,p.t[i].expo);
    }
    printf("The value of polynomial for x=%d is %d",x,sum);
}