#include <stdio.h>

int * readFile(const char* fileName[]){
    FILE *file = fopen(fileName, "r");

    if(file == 0){
        printf("O arquivo informado [%s] nao pode ser lido!");
    }else{
        char value, count = 0, linha = 0, coluna = 0;

        while((value = fgetc(file)) != EOF){
            if(count == 0){
               linha = (int)value;
            }else if(count == 1){
                coluna = (int) value;

            }else{

                printf("Linha: %d \n coluna: %d \n", linha, coluna);

            }
            count++;
        }

    }
    fclose(file);
}


