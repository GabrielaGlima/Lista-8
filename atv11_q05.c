/*5. Faça um programa que receba do usuário o tamanho de uma string e chame uma
função para alocar dinamicamente essa string. Em seguida, o usuário deverá
informar o conteúdo dessa string. O programa imprime a string sem suas vogais.*/
#include<stdio.h>
#include<stdlib.h>

char *insere_string(int n){
    char *pv;
    pv = (char *) calloc(n+1, sizeof(char));
    setbuf(stdin, NULL);
    gets(pv);
    return pv;
}

int eh_vogal(char c){
    int vogal = 0;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        vogal = 1;
    return vogal; 
}

void string_sem_vogal(char *ps, int n){
    int i;
    for(i=0; i<n; i++){
        if(!eh_vogal(ps[i])){
            printf("%c", ps[i]);
        }
    }
}

int main(){
    int n;
    
    printf("Digite o tamanho da string: ");
    scanf("%d", &n);

    char *string = insere_string(n);
    
    string_sem_vogal(string, n);

    free(string);
    string = NULL;
    
    return 0;
}