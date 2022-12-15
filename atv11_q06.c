/*6. Escreva uma função em C que recebe uma string de caracteres alocada
dinamicamente e uma letra e devolve um vetor de inteiros contendo as posições
(índices no vetor da string onde a letra foi encontrada) e um inteiro contendo o
tamanho do vetor criado (total de letras iguais encontradas). Utilize o retorno de
um vetor para retornar os índices e um ponteiro para guardar o tamanho do
vetor criado (retorne por referência). Dica: use o realloc para ir realocando
espaços no vetor à medida que encontrar caracteres na string, para não
desperdiçar memória.*/
#include<stdio.h>
#include<stdlib.h>

char *insere_string(int n){
    char *pv, i;
    pv = (char *) calloc(n+1, sizeof(char));
    setbuf(stdin, NULL);
    gets(pv);
    return pv;
}

int *vetor_posicoes(char *string, char c, int n, int *tamanho){
    int i=0;
    int *v = (int *) malloc(sizeof(int));
    for(i=0; i<n; i++){
        if(string[i] == c){
            v[*tamanho] = i;
            *tamanho = *tamanho + 1;
            v = (int *) realloc(v, *tamanho * sizeof(int));
        }
    }
    return v;
}   

void imprime_vetor(int *pv, int n){
    int i;
    for(i=0; i<n; i++){
        printf("V[%d]: %d\n", i, pv[i]); // ou *(pv+1)
    }
}

int main(){
    int n, tamanho = 0;
    char caractere;
    
    printf("Digite o tamanho da string: ");
    scanf("%d", &n);

    char *string = insere_string(n);
    
    printf("Digite um caractere: ");
    setbuf(stdin, NULL);
    scanf("%c", &caractere);

    int *vetor = vetor_posicoes(string, caractere, n, &tamanho);
    printf("Tamanho: %d\n", tamanho);
    imprime_vetor(vetor, tamanho);

    free(string);
    free(vetor);
    string = NULL;
    vetor = NULL;
    
    return 0;
}