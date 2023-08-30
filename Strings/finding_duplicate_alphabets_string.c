#include <stdio.h>

int main()
{
    char word[]="findingduplicatealphabets";
    // int hash[26]={0};
    // for(int i=0;word[i]!='\0';++i){
    //     ++hash[word[i]-97];
    // }
    // for(int i=0;i<26;++i){
    //     if(hash[i]>1){
    //         printf("%c",i+97);
    //         printf(" %d\n",hash[i]);
    //     }
    // }
    int h=0,x=0;
    for(int i=0;word[i]!='\0';++i){
        x=1;
        x=x<<(word[i]-97);
        if((x&h)>0)
            printf("%c is duplicate\n",word[i]);
        else
            h=x|h;
    }
}