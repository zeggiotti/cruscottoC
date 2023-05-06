#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(int argc, char *argv[]){
    char str[5];
    fgets(str, 5, stdin);
    //scanf("%s", str);
    for(int i = 0; i < 5; i++){
        if(str[i] == 10)
            str[i] = '\n';
        printf("%d ", str[i]);
    }
    printf("Finito.\n");
}