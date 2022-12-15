/*2. Escreva um programa em C que solicita ao usuário a quantidade de notas de uma
turma. Diante disso, crie uma função para alocar um vetor de notas (números
reais) dinamicamente. Finalmente, crie uma função para imprimir a média
aritmética das notas.*/
#include<stdio.h>
#include<stdlib.h>

void ler_notas(int *v, int quant){
    int i;
    for(i=0; i<quant; i++){
        scanf("%d", &v[i]);
    }
}

void media(int v[], int quant){
    int i;
    float total;
    for(i=0; i<quant; i++){
        total += v[i];
    }
    printf("Media: %.2f\n", total/quant);

}

float *libera_vetor(int *v){
    free(v);
    return NULL;
}

int main(){
    int quant;

    printf("Quantas notas: ");
    scanf("%d", &quant);

    float *vn = (float *) malloc(quant * sizeof(float));

    ler_notas(vn, quant);
    media(vn, quant);
    vn = libera_vetor(vn);

    printf("%p", vn);
    
    return 0;
}