#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(int argc, char *argv[]){
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *data;
    data = asctime(tm);
    for(int i = 0; *(data + i) != '\0'; i++){
        printf("%c %d\n", *(data + i), *(data + i));
    }
}