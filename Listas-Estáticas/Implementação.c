#include <stdio.h>
#include <stdlib.h>
#define inicio 0

typedef int TipoChave;
typedef int Apontador; 

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem item;
    Apontador primeiro, ultimo;
}TipoLista;

void IniciaLista();
int ListaVazia();
int RetiraLista();
int InsereLista();
void ImprimeLista();

int main(){
    TipoLista L;
    TipoItem item;
    char resp;

    IniciaLista(&L);

    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);

        InsereLista(item, &L);

        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp == 's');

    printf("********** Lista **********\n\n");
    ImprimeLista(&L);

    return 0;
}

void IniciaLista(TipoLista *Lista){
    Lista->primeiro = inicio;
    Lista->ultimo = Lista->primeiro;
}

int ListaVazia(TipoLista *Lista){
    return Lista->primeiro == Lista->ultimo;
}

int InsereLista(TipoItem item, TipoLista *Lista){
    if(Lista->ultimo > max - 1){
        printf("Lista cheia!\n");
        return 0;
    }
    else{
        Lista->item[Lista->ultimo] = item;
        Lista->ultimo++;
        return 1;
    }
}

int RetiraLista(Apontador p, TipoLista *Lista, TipoItem *item){
    int i;
    if(ListaVazia(Lista) || p-1 >= Lista->ultimo){
        printf("Erro! Posicao nao existe!\n");
        return 0;
    }
    else{
        *item = Lista->item[p-1];
        for(i=p; i<Lista->ultimo; i++){
            Lista->item[i-1] = Lista->item[i];
            Lista->ultimo--;
        }
    }
}

void ImprimeLista(TipoLista *Lista){
    int i;
    for(i=Lista->primeiro; i<Lista->ultimo; i++){
        printf("%d\n", Lista->item[i].chave);\
    }
}
