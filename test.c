#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    printf("N args: %d\n", argc);
    char str[10] = "2244";
    if(!(strcmp(str, argv[1]))){
        printf("Uguali\n");
    }
}