#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include "arquivo.h"
#include "grade.h"

/* Constantes */
#define QTD_GERACOES 10
#define QTD_PADRAO   22

/*  Parametros de prcessamento do jogo da vida:
    => nomeDoArquivo.txt
    => n�meroDeGera��esDesejadas
    ex: JogoDaVida.exe bacterias.txt 10 */

int main(int argc, char *argv[]){
    int **grade;
    int qtdGeracoes = 0, i = 1;
    int *L = QTD_PADRAO, *C = QTD_PADRAO;
    char * nomeArquivo;

    nomeArquivo = nameFile(argc, argv);
    qtdGeracoes = qtdGeracao(argc, argv);

    if (qtdGeracoes == 0)
        qtdGeracoes = QTD_GERACOES;

    grade = initGrade(&nomeArquivo, &L, &C);

    for(; i <= qtdGeracoes; i++){
        printf("+--------------------- Geracao [%d] --------------------------+\n",i);
        printGeracao(grade, &L, &C);
        nextGeracao(grade, &L, &C);
    }
    return 0;
}
