#include<iostream>
using namespace std;
int main()
{
    // reference is used to assign multiple names to single memory location inside RAM
    // used in parameter passing
    int a=10;
    int &r=a;
    cout<<a<<endl;
    r++;
    cout<<r<<endl;
    cout<<a<<endl;
    return 0;
}