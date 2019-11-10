#include <stdio.h>
#define MAX 10
#define MIN 0

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
    int quant;
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
void criaLista();

int main(){
    TipoLista L, L2;
    TipoItem item;
    int resp;
    iniciaLista(&L);
    iniciaLista(&L2);

    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);

        insereLista(item, &L);

        printf("Digite 1 para continuar ou 0 para sair\n");
        scanf("%d", &resp);
    }while(resp == 1);
    criaLista(L, &L2);
    printf("Lista 1\n\n");
    imprimeLista(L);

    printf("\nLista 2\n\n");
    imprimeLista(L2);

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
    lista->item[lista->ultimo] = item;
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
        printf("QUANTIDADE: %d\n", lista.item[aux].quant);
    }
}

void criaLista(TipoLista L, TipoLista *L2){
    int i, j, quant=0;
    if(listaVazia(L)){
        return;
    }
    for(i=L.primeiro; i<=(L.ultimo - 1); i++){
        for(j=L.primeiro; j<=(L.ultimo - 1); j++){
            if(L.item[i].chave == L.item[j].chave){
                quant++;
            }
        }
        if(quant>1){
            if(L2->ultimo > MAX-1){
                printf("Lista cheia!\n");
            return;
            }
            L2->item[L2->ultimo].chave = L.item[i].chave;
            L2->item[L2->ultimo].quant = quant;
            L2->ultimo++;
        }
        quant = 0;
    }
}


