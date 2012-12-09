#include <stdio.h>
#include "funcoes.h"

int ** geracaoArquivo(const char* fileName[], int *_linha, int *_coluna){
    int value, count = 0;
    int L = 0, C = 0;

    int linha = 0;
    int coluna = 0;

    FILE *file = fopen(*fileName, "r");

    int ** grade = NULL;

    if(file == 0){
        printf("O arquivo informado [%s] nao pode ser lido!\n",*fileName);
    }else{
        while((value = fgetc(file)) != EOF){
            if(count == 0)
                L = value - 48;
            if(count == 1)
                C = value - 48;

            if(L > 0 && C > 0 && grade == NULL){
                grade = matriz(L, C);
            }

            if((grade != NULL) && (linha <= L) && (coluna <= C)){
                if(value == 10 && count > 2){
                    linha++;
                    coluna = 0;
                }else if(count > 2){
                    grade[linha][coluna] = value - 48;
                    coluna++;
                }
            }
            count++;
        }
        fclose(file);
    }
    *_linha = linha + 1;
    *_coluna = coluna;
    return grade;
}


