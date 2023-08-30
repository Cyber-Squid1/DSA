#include <stdio.h>

int hashFunction(int key){
    return key%10;
}

int linearProbing(int key,int i){
    return ((key%10) + i)%10;
}

void insert(int h[],int key){
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
            else if(h[linearProbing(key,x)]!=-1){}
        }
    }
}
void searchKey(int h[],int key){
    if(h[hashFunction(key)]==key){
        printf("Direct search Key %d is present\n",key);
        return ;
    }
    else if(h[hashFunction(key)]!=key && h[hashFunction(key)]!=-1){
        for(int x=1;x<10;++x){
            if(h[linearProbing(key,x)]==key){
                printf("Linear probing search Key %d is present\n",key);
                printf("x=%d\n",x);
                return ;
            }
            else if(h[linearProbing(key,x)]==-1){
                printf("linear probing search Key %d is not present\n",key);
                printf("x=%d\n",x);
                return ;
            }
            else if(h[linearProbing(key,x)]!=key && h[linearProbing(key,x)]!=-1){}
        }
    }
    else if(h[hashFunction(key)]==-1){
        printf("Direct search Key %d is not present\n",key);
        return ;
    }
}

int main()
{
    int HashTable[10];

    for(int y=0;y<10;++y)
        HashTable[y]=-1;

    insert(HashTable,25);
    insert(HashTable,87);
    insert(HashTable,93);
    insert(HashTable,10);
    insert(HashTable,35);
    insert(HashTable,47);
    insert(HashTable,14);
    
    searchKey(HashTable,93);
    searchKey(HashTable,35);
    searchKey(HashTable,85);
    searchKey(HashTable,57);
    searchKey(HashTable,22);
    for(int y=0;y<10;++y)
        printf("%d ",HashTable[y]);
    return 0;
}