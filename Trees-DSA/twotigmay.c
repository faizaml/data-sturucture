#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data ;
    struct Node* left ; 
    struct Node* right ;
}Node;

Node* buatNode (int data){
    Node *nodeBaru = (Node*)malloc(sizeof(Node)) ;
    nodeBaru -> data = data ;
    nodeBaru ->  left = NULL ;
    nodeBaru -> right = NULL ; 
    return nodeBaru ;
}

Node* tambahData (Node* root ,int data){
    if (root == NULL ){
        return buatNode(data) ;
    }
    
    if (data < root -> data){
        root -> left = tambahData(root -> left , data) ;
    }
    
    else if (data > root -> data){
        root -> right = tambahData (root -> right, data) ;
    }
    
    return root ;
}

void inorder (Node* root){
    if (root == NULL)return ;
    printf ("%d", root -> data) ;
    inorder (root -> left) ;
    inorder (root -> right) ;
}
int main (){
    
    return 0 ;
}