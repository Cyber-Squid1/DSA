#include <stdio.h>

int lengthOfString(char str[]){
    int count;
    for(int i=0;str[i]!='\0';++i){
        ++count;
    }
    return count;
}
int main()
{
    char str[]="Welcome";
    printf("The length of the string is= %d",lengthOfString(str));
}