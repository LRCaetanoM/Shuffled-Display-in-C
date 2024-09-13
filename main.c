#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<time.h>


void delay(int milsec){

    clock_t startTime = clock();
    while(clock() < (startTime + milsec));

}

void exibir(char *printavel, char *entrada, int tamanho){
    char *inicio_ptr = printavel;
    char *texto = (char *)calloc(90,sizeof(char));
    char *ptr_texto = texto;
    while(*entrada){
        while(*printavel & *entrada){
                     
            printf("%s%c\n", texto, *printavel);
            if(*entrada == *printavel){
                *ptr_texto = *printavel;
                printavel = inicio_ptr;
                ptr_texto++;
                entrada++;
            }
            else{
                printavel++;
            }
            delay(15);
        }
          
        entrada++;
               
    }  
}

char* lista_caracteres(){
    char *lista =  (char *)malloc(sizeof(char)*256);
    int inicio = 32;
    for (int i = inicio; i < 256; i++) {
        lista[i-inicio] = (char) i;
    }
    lista[0] = ' ';
    return lista;
}
char* receber_funcao(int *tamanho){
    char *lista = (char *)malloc(sizeof(char)*100);
    fgets(lista, 40, stdin);
    *tamanho = strlen(lista);
    return lista;

}

int main(){
    
    
    printf("Digite uma frase: ");
    int tamanho = 0;
    char *entrada = receber_funcao(&tamanho);
    char *arr = lista_caracteres();
    exibir(arr, entrada, tamanho);
    return 0;
}