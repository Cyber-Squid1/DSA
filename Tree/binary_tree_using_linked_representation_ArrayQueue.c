#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct treenode* root=NULL;

void createTree(){
    int value=0;
    struct queue q;
    struct treenode* tp=NULL;
    create(&q,10);
    printf("Enter value for root element: ");
    scanf("%d",&value);
    root=malloc(sizeof(struct treenode));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        tp=dequeue(&q);
        printf("Enter value for left node of %d: ",tp->data);
        scanf("%d",&value);
        if(value!=-1){
            struct treenode* temp=malloc(sizeof(struct treenode));
            temp->data=value;
            temp->left=NULL;
            temp->right=NULL;
            tp->left=temp;
            enqueue(&q,temp);
        }
        printf("Enter value for right node of %d: ",tp->data);
        scanf("%d",&value);
        if(value!=-1){
            struct treenode* temp=malloc(sizeof(struct treenode));
            temp->data=value;
            temp->left=NULL;
            temp->right=NULL;
            tp->right=temp;
            enqueue(&q,temp);
        }
    }
}

void preorderTraversal(struct treenode* tp){
    if(tp!=NULL){
        printf("%d ",tp->data);
        preorderTraversal(tp->left);
        preorderTraversal(tp->right);
    }
}
void inorderTraversal(struct treenode* tp){
    if(tp!=NULL){
        inorderTraversal(tp->left);
        printf("%d ",tp->data);
        inorderTraversal(tp->right);
    }
}
void postorderTraversal(struct treenode* tp){
    if(tp!=NULL){
        postorderTraversal(tp->left);
        postorderTraversal(tp->right);
        printf("%d ",tp->data);
    }
}
void levelorderTraversal(struct treenode* tp){
    struct queue tq;
    create(&tq,20);
    printf("%d ",tp->data);
    enqueue(&tq,tp);
    while(!isEmpty(tq)){
        tp=dequeue(&tq);
        if(tp->left){
            printf("%d ",tp->left->data);
            enqueue(&tq,tp->left);
        }
        if(tp->right){
            printf("%d ",tp->right->data);
            enqueue(&tq,tp->right);
        }
    }
}

void binarySearchTree(struct treenode* tp,int key){
    if(tp==NULL)
        printf("Element not found.\n");
    else if(key==tp->data)
        printf("ELement found.\n");
    else if(key<tp->data)
        binarySearchTree(tp->left,key);
    else if(key>tp->data)
        binarySearchTree(tp->right,key);
}
// Below function returns the pointer to the node at which element as found
struct treenode* binarySearch(struct treenode* tp,int key){
    if(tp==NULL)
        return NULL;
    else if(key==tp->data)
        return tp;
    else if(key<tp->data)
        return binarySearch(tp->left,key);
    else if(key>tp->data)
        return binarySearch(tp->right,key);

    // Iterative code for binary search in tree
    /*
    while(tp!=NULL){
        if(key==tp->data)
            return tp;
        else if(key<tp->data)
            tp=tp->left;
        else if(key>tp->data)
            tp=tp->right;
    }
    return NULL;
    */
}

// Inserting in binary search tree
void insertBST(struct treenode* tp,int key){
    struct treenode* tail=NULL;
    while(tp!=NULL){
        tail=tp;
        if(key==tp->data)
            return ;
        else if(key<tp->data)
            tp=tp->left;
        else if(key>tp->data)
            tp=tp->right;
    }
    struct treenode* temp=malloc(sizeof(struct treenode));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if(key<tail->data)
        tail->left=temp;
    else
        tail->right=temp;
}

struct treenode* recursiveInsertBST(struct treenode* tp,int key){
    if(tp==NULL){
        struct treenode* temp=malloc(sizeof(struct treenode));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        return temp;

    }
    if(key<tp->data)
        tp->left=recursiveInsertBST(tp->left,key);
    else if(key>tp->data)
        tp->right=recursiveInsertBST(tp->right,key);
    return tp;
}

void createBinarySearchTree(struct treenode* tp,int key){
    struct treenode* tail=NULL;
    if(root==NULL){
        struct treenode* temp=NULL;
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return ;
    }
    while(tp!=NULL){
        tail=tp;
        if(key<tp->data)
            tp=tp->left;
        else if(key>tp->data)
            tp=tp->right;
        else
            return ;
    }

    struct treenode* temp=malloc(sizeof(struct treenode));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;

    if(key<tail->data)
        tail->left=tp;
    else if(key>tail->data)
        tail->right=tp;
}

struct treenode* inorderPredecessor(struct treenode* tp){
    while(tp &&tp->right!=NULL)
        tp=tp->right;
    return tp;
}

struct treenode* inorderSuccessor(struct treenode* tp){
    while(tp &&tp->left!=NULL)
        tp=tp->left;
    return tp;
}

int heightBST(struct treenode* tp){
    int x,y;
    if(tp==NULL)
        return 0;
    x=heightBST(tp->left);
    y=heightBST(tp->right);
    return x>y?x+1:y+1;
}

struct treenode* deleteFromBST(struct treenode* tp,int key){
    struct treenode* r=root;
    if(tp==NULL)
        return NULL;
    if(tp->left==NULL && tp->right==NULL){
        if(tp==root)
            root=NULL;
        free(tp);
        return NULL;
    }
    if(key<tp->data)
        tp->left=deleteFromBST(tp->left,key);
    else if(key>tp->data)
        tp->right=deleteFromBST(tp->right,key);
    else{
        if(height(tp->left) > heightBST(tp->right)){
            struct treenode* x=inorderPredecessor(x->left);
            tp->data=x->data;
            x->left=deleteFromBST(tp->left,x->data);
        }
        else{
            struct treenode* x=inorderSuccessor(x->right);
            tp->data=x->data;
            x->right=deleteFromBST(tp->right,x->data);
        }
    }
    return tp;
}

int main()
{
    // createTree();
    // printf("\nPreorder traversal of tree before insert: ");
    // preorderTraversal(root);
    // printf("\nInorder traversal of tree: ");
    // inorderTraversal(root);
    // printf("\nPostorder traversal of tree: ");
    // postorderTraversal(root);
    // printf("\nLevel order traversal of tree: ");
    // levelorderTraversal(root);

    // binarySearchTree(root,32);
    // binarySearchTree(root,25);
    // insertBST(root,62);
    // printf("\nPreorder traversal of tree after insert: ");
    // preorderTraversal(root);
    createBinarySearchTree(root,30);
    createBinarySearchTree(root,20);
    createBinarySearchTree(root,40);
    createBinarySearchTree(root,25);
    createBinarySearchTree(root,10);
    createBinarySearchTree(root,35);
    createBinarySearchTree(root,50);
    printf("PreorderTraversal: ");
    preorderTraversal(root);
    /* To generate a tree from traversals i.e.(Preorder,Postorder,Inorder) we need either combination of PREorder+INorder  or POSTorder+INorder to generate a unique tree.*/
}