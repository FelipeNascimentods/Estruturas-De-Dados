#include <stdio.h>
#include <stdlib.h>
#define Max 100
#define InVet 0

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    //TipoChave chave;
    char nome[Max];
}TipoItem;

typedef struct{
    TipoItem item[Max];
    Apontador Primeiro, Ultimo;
}TipoLista;

//Função que inicia a lista;
void inicia_lista(TipoLista *Lista){
    Lista->Primeiro = InVet;
    Lista->Ultimo = Lista->Primeiro;
}

int lista_vazia(TipoLista Lista){
    return Lista.Primeiro == Lista.Ultimo;
}

int insere_lista(TipoItem x, TipoLista *Lista){
    if(Lista->Ultimo>Max-1){
        printf("Lista Cheia!\n");
        system("pause");
        return(0);
    }
    else{
        Lista->item[Lista->Ultimo] = x;
        Lista->Ultimo++;
        return(1);
    }
}

void retira_lista(Apontador ap, TipoLista *Lista, TipoItem *item){
    int i;
    if(lista_vazia(*Lista) || ap-1 >= Lista->Ultimo){
        printf("Erro! Posicao inexistente.\n");
        system("pause");
        return (0);
    }
    else{
        *item = Lista->item[ap-1];
        for(i=ap; i<Lista->Ultimo; i++){
            Lista->item[i-1] =  Lista->item[i];
        }
        Lista->Ultimo--;
    }
}

void imprime_lista(TipoLista Lista){
    int i;
    for(i=Lista.Primeiro; i<=(Lista.Ultimo-1); i++){
        printf("Nome: %s\n", Lista.item[i].nome);
    }
    system("pause");
}

int main(){
    TipoLista Lista;
    TipoItem x;
    //int aux;
    char resp;

    inicia_lista(&Lista);

    do{
        printf("Digite o nome do aluno: ");
        fflush(stdin);
        gets(x.nome);
        insere_lista(x, &Lista);
        printf("Deseja continuar [s/n]? ");
        scanf("%c", &resp);
        system("cls");
    }while(resp == 's');

    imprime_lista(Lista);
    return (0);
}
