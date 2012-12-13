#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* nameFile(int argc, char *argv[]){
    if(argc> 1)
        return argv[1];
    else
        return "";
}

int qtdGeracao(int argc, char *argv[]){
    if(argc > 2)
        return atoi(argv[2]);
    else
        return 0;
}


