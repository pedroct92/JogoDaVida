#include <stdio.h>
#include <stdlib.h>

int ** matriz(int linha, int coluna){
    int **mat;
    int i = 0;
    mat = (int **) malloc(linha * sizeof(int *));

    if(mat == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }

    for(; i< linha; i++){
        mat[i] = malloc(coluna * sizeof(int));
        if(mat[i] == NULL)
            printf("** Erro: Memoria Insuficiente **");
    }
    return mat;
}
