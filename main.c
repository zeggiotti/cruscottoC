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

#define SOTTOMENU_4 "1. Blocco automatico porte: \0"
#define SOTTOMENU_5 "1. Back-home: \0"
#define SOTTOMENU_7_INFO "Numero di lampeggi impostato: \0"
#define SOTTOMENU_7_INPUT "Inserisci un nuovo numero: \0"
#define SOTTOMENU_8 "Pressione gomme resettata\0"

#define ON "ON\0"
#define OFF "OFF\0"

void stampa_menu();
void getRigaCorrente(int);
int checkInput(char []);
void cruscotto_frecce();
int cruscotto_gomme();
char* datatime();
void stampa_sotto_menu_4();
void stampa_sotto_menu_5();
void stampa_sotto_menu_8();
int usermode(int, char *[]);

int riga;                   // Riga selezionata
int rigaMax;

int status4, status5, frecce;

// Le frecce sono stringe di 3 caratteri, 27 91 xx (il codice ascii delle lettere A B C D)

int main(int argc, char *argv[])
{
    riga = 1;
    status4 = 1;
    status5 = 1;
    frecce = 3;
    
    char input[5];

    rigaMax = 6;
    int user_mode = usermode(argc, argv);

    do {
        int inp_status = checkInput(input);
        if(inp_status == 25 && riga == 4){
            stampa_sotto_menu_4();
        } else if(inp_status == 25 && riga == 5){
            stampa_sotto_menu_5();
        } else if(inp_status == 25 && riga == 7){
            cruscotto_frecce();
        } else if(inp_status == 25 && riga == 8){
            stampa_sotto_menu_8();
        }

        stampa_menu();
        scanf("%s", input);

    } while(strcmp(input, "0\0"));

    return 0; 
}

void stampa_menu(){
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

void cruscotto_frecce(){
    char numstr[30];
    int isnum = 1;

    system("clear");
    printf("%s", SOTTOMENU_7_INFO);
    printf("%d\n", frecce);
    printf("%s", SOTTOMENU_7_INPUT);
    scanf("%s", numstr);


    
    frecce = num;
    if(frecce < 2){
        frecce = 2;
    } else if(frecce > 5){
        frecce = 5;
    }
}

void stampa_sotto_menu_4()
{
    system("clear");

    char input[5];

    printf("%s", AZZURRO);
    printf("%s%s",SOTTOMENU_4, ON);
    printf("%s", BIANCO);
    printf("\n");

    scanf("%s", input);

    if(input[0] == 27 && input[1] == 91 && input[3] == '\0')
    {
        if(input[2] == 'A' || input[2] == 'B')
        {
            if(status4 == 1)
                status4 = 0;
            else
                status4 = 1;
        }
    }
}

void stampa_sotto_menu_5()
{
    system("clear");

    char input[5];

    printf("%s", AZZURRO);
    printf("%s%s",SOTTOMENU_5, ON);
    printf("%s", BIANCO);
    printf("\n");

    scanf("%s", input);

    if(input[0] == 27 && input[1] == 91 && input[3] == '\0')
    {
        if(input[2] == 'A' || input[2] == 'B')
        {
            if(status5 == 1)
                status5 = 0;
            else
                status5 = 1;
        }
    }
}

void stampa_sotto_menu_8()
{
    system("clear");

    char input[5];

    printf("%s", AZZURRO);
    printf("%s",SOTTOMENU_8);
    printf("%s", BIANCO);
    printf("\n");

    scanf("%s", input);
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
            printf("%s%s",QUARTA, status4 ? ON : OFF);
            break;
        case 5:
            printf("%s%s",QUINTA, status5 ? ON : OFF);
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

int checkInput(char input[]){
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