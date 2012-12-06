#include <stdio.h>
#include <stdlib.h>
#include "validacao.h"
#include "arquivo.h"
#include "grade.h"

/* Constantes */
#define QTD_GERACOES 5
#define QTD_LINHA    10
#define QTD_COLUNA   10

/*  Parametros de prcessamento do jogo da vida:
    => f-nomeDoArquivo.txt
    => qtd-númeroDeGeraçõesDesejadas
    ex: JogoDaVida.exe f-bacterias.txt qtd-10 */

int main(int argc, char *argv[]){
    int **grade;
    int qtdGeracoes = 0, i = 1;
    char * nomeArquivo;

    nomeArquivo = nameFile(argc, argv);
    qtdGeracoes = qtdGeracao(argc, argv);

    if (qtdGeracoes == 0)
        qtdGeracoes = QTD_GERACOES;

    grade = initGrade(nomeArquivo, QTD_LINHA, QTD_COLUNA);

    for(; i <= qtdGeracoes; i++){
        printf("************************* Geracao [%d] *******************************\n",i);
        printGeracao(grade, QTD_LINHA, QTD_COLUNA);
        nextGeracao(grade, QTD_LINHA, QTD_COLUNA);
    }
    return 0;
}
