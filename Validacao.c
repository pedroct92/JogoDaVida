#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

char* findParametro(int argc, char *argv[], const char * termoBusca[]){
    int i = 0;
    char *v ;

    for(; i<argc; i++){
        v = strstr(argv[i],termoBusca);
        if (v)
            return replace(v,termoBusca,"");
    }
    return "";
}

char* nameFile(int argc, char *argv[]){
    return findParametro(argc, argv, "f-");
}

int qtdGeracao(int argc, char *argv[]){
    return atoi(findParametro(argc, argv, "qtd-"));
}


