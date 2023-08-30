#include <stdio.h>

void toUpperCase(char str[]){
    for(int i=0;str[i]!='\0';++i){
        str[i]=str[i]-32;
    }
    printf("The string in upper case is: %s\n",str);
}
void toLowerCase(char str[]){
    for(int i=0;str[i]!='\0';++i){
        str[i]=str[i]+32;
    }
    printf("The string in lower case is: %s",str);
}
int main()
{
    char str1[]="welcome";
    char str2[]="HELLO";
    toUpperCase(str1);
    toLowerCase(str2);
}