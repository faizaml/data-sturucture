#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Trie{
    struct Trie* abjad [26] ;
    int akhirKata ;
    char deskripsi [1000] ;
} Trie;

struct Trie* buatNode(){
    Trie* nodeBaru = (Trie*)malloc(sizeof(Trie)) ;
    
    for (int i = 0 ; i < 26 ; i++){
        nodeBaru -> abjad[i] = NULL ; // ngeset agar semua
    }
    nodeBaru -> akhirKata = 0;
    return nodeBaru ;
}

void insert (Trie* root,char* kata, char* deskripsi){
    Trie* temp = root ; // set awalan
    for (int i = 0 ; i < strlen(kata) ; i++){
        int index = kata[i] - 'a' ;
        
        if (temp -> abjad[index] == NULL){
            temp -> abjad[index] = buatNode();
        }
        temp = temp -> abjad[index] ; // untuk pindah ke node berikutnya
    }

    temp -> akhirKata = 1 ;
    strcpy (temp -> deskripsi , deskripsi) ;
}

char* search (Trie* root, char* kata){
    Trie* current = root ;
    
    for (int i = 0 ; i < strlen(kata) ;i++){
        int index = kata[i] - 'a' ;
        
        if (current -> abjad[index] == NULL){
            return NULL ;
        }
        
        current = current -> abjad[index] ;
    }

    if (current -> akhirKata == 1){
        return current -> deskripsi ;
    }
    else return NULL ; 
}

Trie* searchPref(Trie* root, char* prefix) {
    Trie* current = root;
    
    for (int i = 0; i < strlen(prefix); i++) {
        int index = prefix[i] - 'a'; // sebuah array tidak bisa di akses oleh sebuah huruf, melainkan hanya bisa diakses oleh sebuah angka
        
        if (current->abjad[index] == NULL) {
            return NULL;
        }
        
        current = current->abjad[index];
    }
    
    return current;
}
void cekKata (Trie* node,char* kataCari, int level){
    if (node -> akhirKata == 1) {
        printf ("%s", kataCari) ;
    }

    for (int i = 0 ; i < 26 ; i++){
        if (node -> abjad[i] != NULL){
            
            kataCari [level] = i + 'a' ;
            kataCari  [level + 1] = '\0' ;

            cekKata (node -> abjad [i],kataCari,level+1) ;
        }
    }
}

int cekKosong (Trie* node){
    for (int i = 0 ; i<26 ;i++){
        if (node -> abjad[i] != NULL){
            return 0 ;
        }
    }
    return 1 ;
}

void viewAll(Trie* root) {
    if (root == NULL || cekKosong(root)) {
        printf("There is no slang word yet in the dictionary.\n");
    } else {
        printf("List of all slang words in the dictionary:\n");
        
        char kataCari[1000];
        kataCari[0] = '\0';
        
        cekKata(root, kataCari, 0);
    }
    
    printf("Press enter to continue...");
    getchar();
    getchar();
}


int main (){
   
    Trie* root = buatNode () ;

    int menu ;
    printf ("----- MENU -----\n") ;
    printf ("1. Realease a new slang word\n") ;
    printf ("View all slang words starting with a certain prefix word\n") ;
    printf ("4. View all slang words\n") ;
    printf ("5. Exit\n") ;
    printf ("Choose menu : ") ;
    scanf ("%d", &menu) ;
    
    return 0 ;
}