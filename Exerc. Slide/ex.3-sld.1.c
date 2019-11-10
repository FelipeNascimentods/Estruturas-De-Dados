//Programa que faz um cadastro de contatos numa agenda, contendo o nome, endereço e telefone de 500 pessoas;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 500

typedef struct{
    char nome[30];
    char ender[50];
    char tel[15];
}CONTATO;

CONTATO lista[TAM];

int main(){
    int i, aux=1;

    for(i=0; i<TAM; i++){
        system("cls");
        printf("Digite o nome %d: ", i+1);
        fflush(stdin);
        fgets(lista[i].nome, 30, stdin);
        lista[i].nome[strlen(lista[i].nome)-1] = '\0';

        printf("Digite o endereco %d: ", i+1);
        fflush(stdin);
        fgets(lista[i].ender, 50, stdin);
        lista[i].ender[strlen(lista[i].ender)-1] = '\0';

        printf("Digite o telefone %d: ", i+1);
        fflush(stdin);
        fgets(lista[i].tel, 15, stdin);
        lista[i].tel[strlen(lista[i].tel)-1] = '\0';

        printf("\nContinuar - 1\nParar - 0\n");
        scanf("%d", &aux);

        if(aux==0){
            system("cls");
            break;
        }
    }

    for(i=0; i<TAM; i++){
        printf("Nome: %s\nEndereco: %s\nTelefone: %s\n", lista[i].nome, lista[i].ender, lista[i].tel);
    }
    system("pause");
    return 0;
}
