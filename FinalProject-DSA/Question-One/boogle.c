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
        nodeBaru -> abjad[i] = NULL ; 
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
        temp = temp -> abjad[index] ; 
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
    
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void viewByPrefix(Trie* root) {
    char prefix[100];
    
    printf("Input a prefix to be searched: ");
    scanf("%s", prefix);
    
    Trie* nodePrefix = searchPref(root, prefix);
    
    if (nodePrefix == NULL) {
        printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
    } else {
        printf("Words starts with \"%s\":\n", prefix);
        
        char kataCari[1000];
        strcpy(kataCari, prefix);
        int panjangPrefix = strlen(prefix);
        
        cekKata(nodePrefix, kataCari, panjangPrefix);
    }
    
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void menuSearch(Trie* root) {
    char kata[100];
    
    printf("Input a slang word to be searched: ");
    scanf("%s", kata);
    
    char* hasil = search(root, kata);
    
    if (hasil == NULL) {
        printf("There is no word \"%s\" in the dictionary.\n", kata);
    } else {
        printf("Slang word : %s\n", kata);
        printf("Description : %s\n", hasil);
    }
    
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}
void menuRelease(Trie* root) {
    char kata[100];
    char deskripsi[1000];
    
    
    while (1) {
        printf("Input a new slang word [Must be >1 character & no space]: ");
        scanf("%s", kata);
        
        if (strlen(kata) > 1) {
            
            break;
        } else {
            printf("Kata harus lebih dari 1 karakter!\n");
        }
    }
    
    while (1) {
        printf("Input a new slang word description [Must be >2 words]: ");
        getchar(); 
        fgets(deskripsi, 1000, stdin);
        deskripsi[strcspn(deskripsi, "\n")] = '\0'; 
        
        
        int jumlahKata = 1;
        for (int i = 0; i < strlen(deskripsi); i++) {
            if (deskripsi[i] == ' ') jumlahKata++;
        }
        
        if (jumlahKata > 2) {
            break;
        } else {
            printf("Deskripsi harus lebih dari 2 kata!\n");
        }
    }
    
    insert(root, kata, deskripsi);
    printf("Successfully released new slang word.\n");
    
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}


int main() {
    Trie* root = buatNode(); 
    
    int menu;
    
    do {
        
        printf("        BOOGLE SLANG WORD\n");

        printf("1. Release a new slang word\n");
        printf("2. Search a slang word\n");
        printf("3. View all slang words starting with a certain prefix\n");
        printf("4. View all slang words\n");
        printf("5. Exit\n");
        printf("--------------------------------\n");
        printf("Choose menu: ");
        scanf("%d", &menu);
        
        switch(menu) {
            case 1:
                menuRelease(root);
                break;
            case 2:
                menuSearch(root);
                break;
            case 3:
                viewByPrefix(root);
                break;
            case 4:
                viewAll(root);
                break;
            case 5:
                printf("Thank you... Have a nice day :)\n");
                break;
            default:
                printf("Menu tidak valid!\n");
                printf("Press enter to continue...");
                getchar();
                getchar();
        }
        
    } while (menu != 5);
    
    return 0;
}