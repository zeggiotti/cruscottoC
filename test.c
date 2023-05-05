#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(int argc, char *argv[]){
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%2d/%2d/%d\n", tm.tm_mday, tm.tm_mon, tm.tm_year + 1900);
}