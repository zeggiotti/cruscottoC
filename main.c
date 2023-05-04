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
int checkInput(char [], int);
int cruscotto_frecce();
int cruscotto_gomme();
char* datatime();
int stampa_sotto_menu_4();
int stampa_sotto_menu_5();
int usermode(int, char *[]);

int riga;                   // Riga selezionata
int rigaMax;

// Le frecce sono stringe di 3 caratteri, 27 91 xx (il codice ascii delle lettere A B C D)

int main(int argc, char *argv[]){
    
    riga = 1;
    char input[5];

    rigaMax = 6;
    int user_mode = usermode(argc, argv);
    
    do {

        stampa_menu(user_mode);
        scanf("%s", input);
        int inp_status = checkInput(input, user_mode);

        if(inp_status == 25){

        }

    } while(strcmp(input, "0\0"));

    return 0; 
}

void stampa_menu(int user_mode){
    system("clear");

    for(int i = 1; i <= rigaMax; i++){
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

int checkInput(char input[], int umode){

    if(input[0] == 27 && input[1] == 91 && input[3] == '\0'){
        if(input[2] == 'A'){
            riga--;
            if(riga == 0){
                riga = rigaMax;
            }
        } else if (input[2] == 'B'){
            riga++;
            if(riga > rigaMax){
                riga = 1;
            }
        } else if (input[2] == 'C'){
            return 25;
        }
    }

    return 0;

}

int usermode(int narg, char *args[]){

    if(narg>1){
        char arg[6] = "2244\0";
        if( !strcmp(arg, args[1]) ){
            rigaMax = 8;
            return 1;
        }
    }
    return 0;

}