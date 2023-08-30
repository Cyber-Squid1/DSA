#include <stdio.h>
#include <stdlib.h>
/*  
    if parent node is at index i in an array then:
        right child is at index 2*i
        left child is at index (2*i)+1
    
    if a child node is a index i in an array then:
        parent is at node greatestIntegerFunction(i/2)
*/