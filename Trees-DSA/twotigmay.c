#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
--- Notes for tree ---
1.pre order : pembacaan pre order ini dimulai dengan root - left - right . 
pembacaan selalu mulai dari parent yang paling awal terlebih dahulu
2. in order : pembacaan secara preorder ini selalu dimulai dari bagian leaf atau 
dapat kita sebut juga dengan bagian left. langkah pembacaan ini dimulai dari left - root - right
3. post order : pembacaan type ini dimulai dari cabang cabang nya terlbih dahulu, cabang pertama yang di baca atau di print itu adalah 
cabang yang paling kiri terlebih dahulu, langkah pembacaan ini dimulai dari left - right - root
*/


/*--- Starting Code ---*/
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

/* --- Easy Code --- */
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
    inorder (root -> left) ; // kunjungin left
    printf ("%d", root -> data) ; // kunjungin root
    inorder (root -> right) ; // kunjungin right
}

void postorder 
(Node* root){
    if (root == NULL) return ;
    postorder (root -> left) ;
    postorder (root -> right) ;
    printf ("%d", root -> data) ;
}

/* --- Mid Code --- */
int countJumlah (Node* root){
    if (root == NULL){
        return 0 ;
    }
    
    return 1 + countJumlah (root -> left) + countJumlah (root ->  right) ;
}




int main (){
    
    return 0 ;
}