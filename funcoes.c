#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

char *replace(char *st, char *orig, char *repl) {
  static char buffer[4096];
  char *ch;
  if (!(ch = strstr(st, orig)))
   return st;
  strncpy(buffer, st, ch-st);
  buffer[ch-st] = 0;
  sprintf(buffer+(ch-st), "%s%s", repl, ch+strlen(orig));
  return buffer;
  }

int ** matriz(int qtd){
    int **mat;
    int i = 0;
    mat = (int **) malloc(qtd * sizeof(int *));

    if(mat == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }

    for(; i< qtd; i++){
        mat[i] = malloc(qtd * sizeof(int));
        if(mat[i] == NULL)
            printf("** Erro: Memoria Insuficiente **");
    }
    return mat;
}
