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
        printf("[%s]",v);
        if (v)
            return replace(v,termoBusca,"");
    }
    return "";
}

char* nameFile(int argc, char *argv[]){
    if(argc> 1)
        return argv[1]; //findParametro(argc, argv, "f-");
    else
        return "";
}

int qtdGeracao(int argc, char *argv[]){
    if(argc > 2)
        return atoi(argv[2]); //atoi(findParametro(argc, argv, "qtd-"));
    else
        return NULL;
}


