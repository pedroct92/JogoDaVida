#include <string.h>
#include "grade.h"

int * initGrade(char * const nomeArquivo[], int qtd){
    if(strcmp(nomeArquivo, "") == 0)
        return geracaoRandomica(qtd);
    else
        return geracaoArquivo(nomeArquivo);
}


int geracaoRandomica(int qtd){ //ajuste
    int ** grade;
    int i = 0, x = 0;

    grade = matriz(qtd);

    for(; i< qtd; i++){
        for(; x< qtd; x++)
            grade[i][x] = (rand() % 2 == 0)? 1 : 0;

        x = 0;
    }
    return grade;
}

void printGeracao(int **grade, int qtd){
    int x = 0, y = 0;

    for(; x < qtd; x++){
        for(; y < qtd; y++){
            printf("%d",grade[x][y]);
            if(y == qtd -1)
               printf("\n");
        }
        y = 0;
    }
}
