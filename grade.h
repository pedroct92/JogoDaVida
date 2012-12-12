int ** initGrade(char * const nomeArquivo[], int *linha, int *coluna);
int ** geracaoRandomica(int *linha, int *coluna);
void printGeracao(int **grade, int *linha, int *coluna);
void nextGeracao(int **grade, int *linha, int *coluna);
int vizinhos(int ** grade, int i, int j);
void desalocaGrade(int **grade);
