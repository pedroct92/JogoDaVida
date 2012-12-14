#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include "arquivo.h"
#include "grade.h"

/* Constantes */
#define QTD_GERACOES 50
#define QTD_PADRAO   20

/*  Parametros de prcessamento do jogo da vida:
    => nomeDoArquivo.txt
    => númeroDeGeraçõesDesejadas
    ex: JogoDaVida.exe bacterias.txt 10

    Modelo arquivo:

    3 3
    1 0 1
    1 0 1
    1 1 1

 */

int main(int argc, char *argv[]){
    int **grade;
    int qtdGeracoes = 0, i = 1;
    int L = QTD_PADRAO, C = QTD_PADRAO;
    char * nomeArquivo;

    nomeArquivo = nameFile(argc, argv);
    qtdGeracoes = qtdGeracao(argc, argv);

    if (qtdGeracoes == 0)
        qtdGeracoes = QTD_GERACOES;

    grade = initGrade(&nomeArquivo, &L, &C);

    for(; i <= qtdGeracoes; i++){
        printf("\n**************************** Geracao [%d] ******************************\n\n",i);
        printGeracao(grade, &L, &C);
        nextGeracao(grade, &L, &C);
    }
    desalocaGrade(grade);
    return 0;
}
