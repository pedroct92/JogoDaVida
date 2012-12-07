#include <string.h>
#include "grade.h"
#include "funcoes.h"

int * initGrade(char * const nomeArquivo[], int linha, int coluna){
    if(strcmp(nomeArquivo, "") == 0)
        return geracaoRandomica(linha, coluna);
    else
        return geracaoArquivo(nomeArquivo);
}

int geracaoRandomica(int linha, int coluna){
    int ** grade;
    int i = 0, x = 0;

    grade = matriz(linha,coluna);

    for(; i< linha; i++){
        for(; x< coluna; x++)
            grade[i][x] = (rand() % 2 == 0)? 1 : 0;

        x = 0;
    }
    return grade;
}

void printGeracao(int **grade, int linha, int coluna){
    int x = 0, y = 0;

    for(; x < linha; x++){
        for(; y < coluna; y++){
            if(grade[x][y] == 1)
                printf("%c",254);//254
            else
                printf("%c",207);

            if(y == coluna -1)
               printf("\n");
        }
        y = 0;
    }
}

int nextGeracao(int **grade, int linha, int coluna){
    int i = 1, j = 1;
    int qtdVizinhos = 0;

    for(; i < linha-1; i++){
        for(; j < coluna-1; j++){

            if(grade[i-1][j-1] == 1)
                qtdVizinhos++;

            if(grade[i-1][j] == 1)
                qtdVizinhos++;

            if(grade[i-1][j+1] == 1)
                qtdVizinhos++;

            if(grade[i][j-1] == 1)
                qtdVizinhos++;

            if(grade[i][j+1] == 1)
                qtdVizinhos++;

            if(grade[i+1][j-1] == 1)
                qtdVizinhos++;

            if(grade[i+1][j] == 1)
                qtdVizinhos++;

            if(grade[i+1][j+1] == 1)
                qtdVizinhos++;

            if(grade[i][j] == 1 && qtdVizinhos < 2)
               grade[i][j] = 0;

            if(grade[i][j] == 1 && qtdVizinhos > 3)
               grade[i][j] = 0;

            if(grade[i][j] == 0 && qtdVizinhos == 3)
               grade[i][j] = 1;

        }
        qtdVizinhos = 0;
        j = 0;
    }

    return grade;
}
