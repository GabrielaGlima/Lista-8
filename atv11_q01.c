/*1. Escreva um trecho de código que seja capaz de ler uma string do teclado e em
seguida escrever a string completa e apenas o último caractere. O seu código
deve perguntar ao usuário o tamanho da string que ele deseja digitar. Faça
usando alocação dinâmica.*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int tamanho;
    
    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    char *string = (char *) malloc(tamanho+1 * sizeof(char));
    printf("Digite a palavra de tamanho %d: ", tamanho);
    setbuf(stdin, NULL);
    gets(string);

    printf("A palavra digitada eh %s e tem tamanho %d!\n", string, strlen(string));
    printf("O 5o caractere eh: %c!\n", *(string+4), strlen(string));
    //printf("O 5o caractere eh: %c!\n", string[4], strlen(string));

    free(string);
    string = NULL;
    
    return 0;
}