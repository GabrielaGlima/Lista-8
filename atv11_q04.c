/*4. Faça um programa em C que leia um vetor alocado dinamicamente. O usuário
informará o tamanho do vetor. Posteriormente, implemente uma função que irá
retornar o maior elemento do vetor usando ponteiro. Siga o protótipo a seguir:
Dica: aloque dinamicamente a variável (ponteiro) que será retornada, ou seja, a
que conterá o maior elemento do vetor.
                    int *maior(int *v, int n);
*/
#include<stdio.h>
#include<stdlib.h>

int *insere_vetor(int n){
    int *pv, i;
    pv = (int *) calloc(n, sizeof(int));
    for(i=0; i<n; i++){
        scanf("%d", pv+i); //scanf("%d", &pv[i]);
    }
    return pv;
}

void imprime_vetor(int *pv, int n){
    int i;
    for(i=0; i<n; i++){
        printf("V[%d]: %d\n", i, pv[i]); // ou *(pv+1)
    }
}

int *maior(int *v, int n){
    int i, *maior = (int *) malloc(sizeof(int));
    *maior = v[0];
    for(i=0; i<n; i++){
        if(v[i] > *maior){
            *maior = v[i];
        }
    }
    return maior;
}

float *libera_vetor(int *v){
    free(v);
    return NULL;
}

int main(){
    int tamanho = 3;
    int *v = insere_vetor(tamanho);
    imprime_vetor(v, tamanho);
    int *p = maior(v, tamanho);
    printf("O maior eh: %d", *p);
    v = libera_vetor(v);
    p = libera_vetor(p);
    return 0;
}