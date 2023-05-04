#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char str[5];
    scanf("%s", str);
    for(int i = 0; i < 5; i++){
        printf("%d ", str[i]);
    }
    printf("\n");
}