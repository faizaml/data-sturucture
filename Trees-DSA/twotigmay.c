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

/* --- hitung ada berapa jumlah node dalam sebuah tree*/
int countJumlah (Node* root){
    if (root == NULL){
        return 0 ;
    }
    return 1 + countJumlah (root -> left) + countJumlah (root ->  right) ;
}

/* menghitung kedalaman sebuah tree, (ada di level berapa trees tersebut)*/

int max (int a , int b){
    if (a > b) return a ;
    else return b ;
}

int height (Node* root){
    if (root == NULL)return 0 ;
    /*kenapa 0, karea root tidak memiliki value*/
    
    int leftHeight = height (root -> left) ;
    int rightHeight = height (root -> right) ;

    return 1 + max (leftHeight,rightHeight) ;
}

/* Penjelasan untuk Code mencari kedalaman levelya
1. pada step awal kita harus cek, apakah root ada atau tidak. jika roo t tidak ada maka kita akan me return  nilainya menjadi ZERO/0
2. setelah itu kita mengecek bagian kiri dari root awal. setelah masuk kedalam value yang ada di kiri, kita harus cek lagi, apakah nilai kiri it null atau tidak, jika tidak null maka kita mengecek cabang cabang nya ,mulai dari kiri lalu nanti ke kanan
3. setelah bagian kiri selesai, lalu kita cek bagian kanannya bagaimana, cara dan prosesnya sama dengan bagian yang kiri*/


// --- Find Minimum ---

struct Node* findMin (Node* root){
    if (root == NULL) return NULL ;
    
    while (root -> left != NULL) root = root -> left ;
    
    return root ;
}


int main (){
    
    return 0 ;
}