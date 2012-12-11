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
        int espaco = 0, quebra = 0, pass = 0;
        char lin[10], col[40];
        int cont1 = 0, cont2 = 0, print =0;

        while((value = fgetc(file)) != EOF){
            (value == ' ' )? espaco++: espaco;
            (value == '\n' )? quebra++: quebra;

            if(espaco == 0){
                lin[cont1] = value;
                pass = 1;
                cont1++;
            }

            if(quebra == 0 && pass != 1 && value != ' '){
                col[cont2] = value;
                cont2++;
            }

            pass = 0;

            if (quebra == 1 && print == 0){
                L = atoi(lin);
                C = atoi(col);
                print = 1;
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


