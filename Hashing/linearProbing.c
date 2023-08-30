#include <stdio.h>
#include <stdlib.h>

int hashFunction(int key){
    return key%10;
}

int linearProbing(int key,int i){
    return ((key%10) + i)%10;
}

void insert(int *h,int key){
    if(h[hashFunction(key)]==-1){
        h[hashFunction(key)]=key;
        return ;
    }
    else if(hashFunction(key)!=-1){
        for(int x=1;x<10;++x){
            if(h[linearProbing(key,x)]==-1){
                h[linearProbing(key,x)]=key;
                break;
            }
            else if(h[linearProbing(key,x)]!=-1)
                ++x;
        }
    }
}

int main()
{
    int *HashTable=malloc(10*sizeof(int));

    for(int y=0;y<10;++y)
        HashTable[y]=-1;

    insert(HashTable,25);
    insert(HashTable,87);
    insert(HashTable,93);
    insert(HashTable,10);
    insert(HashTable,35);
    insert(HashTable,47);
    insert(HashTable,14);
    for(int y=0;y<10;++y)
        printf("%d ",HashTable[y]);
    return 0;
}