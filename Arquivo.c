 /*
  Autor: Pedro Coelho
  Email: pedroct92@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
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
        int espaco = 0, quebra = 0, pass = 0;
        int contLinha = 0, contColuna = 0, linhaXcoluna =0;
        char lin[10], col[10];

        while((value = fgetc(file)) != EOF){
            (value == ' ' )? espaco++: espaco;
            (value == '\n' )? quebra++: quebra;

            if(espaco == 0){
                lin[contLinha] = value;
                pass = 1;
                contLinha++;
            }

            if(quebra == 0 && pass != 1 && value != ' '){
                col[contColuna] = value;
                contColuna++;
            }

            pass = 0;

            if (quebra == 1 && linhaXcoluna == 0){
                L = atoi(lin);
                C = atoi(col);
                linhaXcoluna = 1;
            }

            if(L > 0 && C > 0 && grade == NULL)
                grade = matriz(L, C);

            if((grade != NULL) && (linha <= L) && (coluna <= C)){
                if(count >0){
                    if(value == '\n'){
                        linha++;
                        coluna = 0;
                    }else{
                        grade[linha][coluna] = value - 48;
                        coluna++;
                    }
                }
                count++;
            }
        }
        fclose(file);
        free(file);
    }
    *_linha = L;
    *_coluna = C;
    return grade;
}


