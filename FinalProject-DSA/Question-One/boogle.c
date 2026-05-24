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

void search (Trie* root, char* kata){
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
        int index = prefix[i] - 'a';
        
        if (current->abjad[index] == NULL) {
            return NULL;
        }
        
        current = current->abjad[index];
    }
    
    return current;
}


int main (){
   
    struct Trie mhs [1000] ;

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