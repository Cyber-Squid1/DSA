#include <stdio.h>

int main()
{
    char a[]="medical";
    char b[]="deckmal";
    int hash[26]={0},i;
    for(i=0;a[i]!='\0';++i){
        ++hash[a[i]-97];
    }
    for(i=0;b[i]!='\0';++i){
        --hash[b[i]-97];
        if(hash[a[i]-97]<0){
            printf("Not anagram.");
            break;
        }
    }
    if(b[i]=='\0')
        printf("It is anagram");
}