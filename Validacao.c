#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

/*char* findParametro(int argc, char *argv[], const char * termoBusca[]){
    int i = 0;
    char *v ;

    for(; i<argc; i++){
        printf("%s",termoBusca);
        v = strstr (argv[i],termoBusca);
        if (v)
            return v;
    }
    return "";
}*/

char* nameFile(int argc, char *argv[]){
    int i = 0;
    char *v ;

    for(; i<argc; i++){
        v = strstr(argv[i],"-f");
        if (v)
            return replace(v,"-f","");
    }
    return "";
    //return findParametro(argc, argv, "f-");
}

int qtdGeracao(int argc, char *argv[]){
    int i = 0;
    char *v ;

    for(; i<argc; i++){
        v = strstr(argv[i],"-qtd");
        if (v)
            v = replace(v,"-qtd","");
    }
    return atoi(v);
}


