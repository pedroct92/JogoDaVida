#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grade.h"
#include "funcoes.h"
#include "arquivo.h"

int ** initGrade(char * const nomeArquivo[], int *linha, int *coluna){
    if(strcmp(*nomeArquivo, "") == 0)
        return geracaoRandomica(linha, coluna);
    else
        return geracaoArquivo(nomeArquivo, linha, coluna);
}

int ** geracaoRandomica(int *linha, int *coluna){
    int ** grade;
    int i, x;

    grade = matriz(*linha + 2,*coluna + 2);

    for(i = 1; i< *linha + 1; i++){
        for(x = 1; x< *coluna + 1; x++){
            grade[i][x] = (rand() % 2 == 0)? 0 : 1;

        }
    }
    return grade;
}

void printGeracao(int **grade, int *linha, int *coluna){
    int x, y;

    for(x = 1; x < *linha+1; x++){
        for(y = 1; y < *coluna+1; y++){
            if(grade[x][y] == 1)
                printf("%c",254);
            else
                printf("%c",207);

            if(y == *coluna)
               printf("\n");
        }
    }
}

void nextGeracao(int **grade, int *linha, int *coluna){
    int i = 1, j = 1, qtdVizinhos = 0;

    for(; i < *linha+1; i++){
        for(; j < *coluna+1; j++){

            qtdVizinhos = vizinhos(grade, i, j);

            if(grade[i][j] == 1 && qtdVizinhos < 2)
               grade[i][j] = 0;

            if(grade[i][j] == 1 && qtdVizinhos > 3)
               grade[i][j] = 0;

            if(grade[i][j] == 0 && qtdVizinhos == 3)
               grade[i][j] = 1;

        }
        qtdVizinhos = j = 0;
    }
}

int vizinhos(int ** grade, int i, int j){
    int x = i -1, y = j -1, qtdVizinhos = 0 ;

    if(grade[x][y] == 1)
        qtdVizinhos++;

    if(grade[x][j] == 1)
        qtdVizinhos++;

    if(grade[x][j+1] == 1)
        qtdVizinhos++;

    if(grade[i][y] == 1)
        qtdVizinhos++;

    if(grade[i][j+1] == 1)
        qtdVizinhos++;

    if(grade[i+1][y] == 1)
        qtdVizinhos++;

    if(grade[i+1][j] == 1)
        qtdVizinhos++;

    if(grade[i+1][j+1] == 1)
        qtdVizinhos++;

    return qtdVizinhos;
}

void desalocaGrade(int **grade){
    free(grade);
}
