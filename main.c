#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PRIMA "1. Setting automobile: \0"
#define SECONDA "2. Data: \0"
#define TERZA "3. Ora: \0"
#define QUARTA "4. Blocco automatico porte: \0"
#define QUINTA "5. Back-home: \0"
#define SESTA "6. Check olio\0"
#define SETTIMA "7. Frecce direzione\0"
#define OTTAVA "8. Reset pressione gomme\0"
#define AZZURRO "\033[36m"
#define BIANCO "\033[37m"

void stampa_menu(int);
void getRigaCorrente(int);
int checkInput();
int cruscotto_frecce();
int cruscotto_gomme();
char* datatime();
int stampa_sotto_menu_4();
int stampa_sotto_menu_5();
int usermode(int, char *[]);

int riga;                   // Riga selezionata

// Le frecce sono stringe di 3 caratteri, 27 91 xx (il codice ascii delle lettere A B C D)

int main(int argc, char *argv[]){
    
    riga = 1;
    char input[5];

    int user_mode = usermode(argc, argv);
    
    do {
        stampa_menu(user_mode);
        scanf("%s", input);
    } while(strcmp(input, "0\0"));

    return 0; 
}

void stampa_menu(int user_mode){
    system("clear");

    int n = 7;
    if(user_mode){
        n = 9;
    }

    for(int i = 1; i < n; i++){
        if(i == riga){
            printf("%s", AZZURRO);
        }

        getRigaCorrente(i);
        printf("\n");

        if(i == riga){
            printf("%s", BIANCO);
        }
    }

    printf("\n");
}

void getRigaCorrente(int i){
    
    switch (i) {
        case 1:
            printf("%s",PRIMA);
            break;
        case 2:
            printf("%s",SECONDA);
            break;
        case 3:
            printf("%s",TERZA);
            break;
        case 4:
            printf("%s",QUARTA);
            break;
        case 5:
            printf("%s",QUINTA);
            break;
        case 6:
            printf("%s",SESTA);
            break;
        case 7:
            printf("%s",SETTIMA);
            break;
        case 8:
            printf("%s",OTTAVA);
            break;
        default:
            printf(" ");
            break;
    }
}

int usermode(int narg, char *args[]){

    if(narg>1){
        char arg[6] = "2244\0";
        if( !strcmp(arg, args[1]) ){
            return 1;
        }
    }
    return 0;

}