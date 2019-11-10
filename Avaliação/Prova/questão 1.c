#include <stdio.h>
#define MAX 10
#define MIN 0

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem item[MAX];
    Apontador primeiro, ultimo;
}TipoLista;

void iniciaLista();
int listaVazia();
int insereLista();
void retiraLista();
void imprimeLista();
void retornaLista();

int main(){
    TipoLista L, L2, L3;
    TipoItem item;
    int resp;

    iniciaLista(&L);
    iniciaLista(&L2);
    iniciaLista(&L3);

    printf("---------- Lista 1 ----------\n\n");
    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);

        insereLista(item, &L);

        printf("Digite 1 para continuar ou 0 para sair: ");
        scanf("%d", &resp);
    }while(resp == 1);
    printf("\n\n---------- Lista 2 ----------\n\n");
    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);

        insereLista(item, &L2);

        printf("Digite 1 para continuar ou 0 para sair: ");
        scanf("%d", &resp);
    }while(resp == 1);

    retornaLista(&L3, L, L2);

    printf("---------- Lista 1 ----------\n\n");
    imprimeLista(L);
    printf("\n---------- Lista 2 ----------\n\n");
    imprimeLista(L2);
    printf("\n---------- Lista 3 ----------\n\n");
    imprimeLista(L3);

    return 0;
}

void iniciaLista(TipoLista *lista){
    lista->primeiro = MIN;
    lista->ultimo = lista->primeiro;
}

int listaVazia(TipoLista lista){
    return lista.primeiro == lista.ultimo;
}

int insereLista(TipoItem item, TipoLista *lista){
    if(lista->ultimo > MAX-1){
        printf("Lista cheia!\n");
        return 0;
    }
    lista->item[lista->ultimo].chave = item.chave;
    lista->ultimo++;
    return 1;
}

void retiraLista(Apontador p, TipoLista *lista, TipoItem *item){
    int aux;
    if(listaVazia(*lista) || p-1 >= lista->ultimo){
        printf("Erro! Posicao nao existe.\n");
        return;
    }
    *item = lista->item[p-1];
    for(aux=p; aux<lista->ultimo; aux++){
        lista->item[aux-1] = lista->item[aux];
    }
    lista->ultimo--;
}

void imprimeLista(TipoLista lista){
    int aux;
    for(aux = lista.primeiro; aux<=(lista.ultimo-1); aux++){
        printf("CHAVE: %d\n", lista.item[aux].chave);
    }
}

void retornaLista(TipoLista *L3, TipoLista L, TipoLista L2){
    int i, j;

    if(listaVazia(L) || listaVazia(L2)){
        printf("Listas vazias!\n");
        return;
    }
    for(i=L.primeiro; i<=(L.ultimo - 1); i++){
        for(j=L2.primeiro; j <= (L2.ultimo - 1); j++){
            if(L.item[i].chave == L2.item[j].chave){
                insereLista(L.item[i], L3);
            }
        }
    }

}
