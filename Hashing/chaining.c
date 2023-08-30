#include "chain.h"
#include<stdio.h>
#include<stdlib.h>

int hash(int key){
    return key%10;
}

void insert(struct node* h[],int key){
    int index=hash(key);
    h[index]=insertSortedChainHashNode(h[index],key);
}

int main()
{
    struct node* HashTable[10];
    struct node* temporaryPointer;

    for(int i=0;i<10;++i)
        HashTable[i]=NULL;
    
    insert(HashTable,22);
    insert(HashTable,42);
    insert(HashTable,62);
    insert(HashTable,78);
    insert(HashTable,25);
    insert(HashTable,95);
    insert(HashTable,8);
    insert(HashTable,14);
    insert(HashTable,77);
    insert(HashTable,23);
    insert(HashTable,14);
    insert(HashTable,16);
    insert(HashTable,96);
    insert(HashTable,74);
    insert(HashTable,28);
    insert(HashTable,69);
    insert(HashTable,71);
    insert(HashTable,10);
    insert(HashTable,89);
    insert(HashTable,50);

    searchHashTable(HashTable[hash(22)],22);
    return 0;
}