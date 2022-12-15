/*3. Dada uma matriz C (30 x 10), gerar e imprimir C^t(matriz transposta). Veja o exemplo abaixo. 
A matrizes devem ser alocadas dinamicamente.
Use o seguinte protótipo:
int **transposta(int **mat, int lins, int cols)*/
#include <stdio.h>
#define LINHA 3
#define COLUNA 2

int **alocar_matriz(int m, int n){
    int **matriz, i;
    // Vetor de m ponteiros para int (linhas) 
    matriz = (int **) malloc(m * sizeof(int *));  
    for(i=0; i<m; i++){
        // m vetores de n int (colunas)
        matriz[i] = (int *) malloc(n * sizeof(int )); 
    }
    return matriz;
}

int **insere_matriz(int **matriz, int m, int n){
    int i, j;
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

int **liberar_matriz(int **matriz, int m) {
    int i;
    for(i=0; i<m; i++){
        free(matriz[i]); // libera as linhas da matriz (vetor de int)
    }
    free(matriz); // libera a matriz (vetor de ponteiros)    
    return NULL;  // retorna nulo para um o ponteiro
}

void imprime_matriz(int **matriz, int m, int n){
    int i, j;
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            printf("M[%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }
}

int **transposta(int **mat, int lins, int cols){

    int **t = malloc(cols * sizeof(int*));
    for (int j = 0; j < cols; j++) {
        t[j] = malloc(lins * sizeof(int));
        for (int i = 0; i < lins; i++) {
            t[j][i] = mat[i][j];
        }
    }
    return t;
}

int main(){
    int m = 2, n = 2;
    int **mat = alocar_matriz(m, n);
    mat = insere_matriz(mat, m, n);
    imprime_matriz(mat, m, n);
    int **trans = transposta(mat, n, m);
    imprime_matriz(trans, m, n);
    mat = liberar_matriz(mat, m);
    trans = liberar_matriz(trans, m);
    
    return 0;
}

