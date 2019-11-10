#include <stdio.h>
#include <string.h>

typedef int TipoChave;

typedef struct{
    //TipoChave chave;
    /*int matricula;
    char nome[50];*/
    float media;
}TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula{
    TipoItem item;
    Apontador prox;
}celula;

typedef struct{
    Apontador primeiro, ultimo;
    int tamanho;
}TipoLista;

void iniciaLista();
int listaVazia();
void insereLista();
int removeLista();
void imprimeLista();
//void insereCrescente();
//TipoLista separaLista();
void concatenaLista();

int main(){

    TipoLista L, L2;
    TipoItem item;
    int resp;


    iniciaLista(&L);
    iniciaLista(&L2);

    printf("*************** Lista 1 ***************\n\n");
    do{
        /*printf("Digite a matricula: ");
        scanf("%d", &item.matricula);
        printf("Digite o nome: ");
        fflush(stdin);
        fgets(item.nome, 50, stdin);
        item.nome[strlen(item.nome)-1] = '\0';
        printf("Digite a media: ");
        scanf("%f", &item.media);*/

        printf("Digite a media: ");
        scanf("%f", &item.media);

        insereLista(item, &L);
        //insereCrescente(item, &L);

        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%d", &resp);

    }while(resp == 1);

    printf("*************** Lista 2 ***************\n\n");
    do{
        printf("Digite a media: ");
        scanf("%f", &item.media);

        insereLista(item, &L2);

        printf("Digite (1) para continuar ou (0) para sair: ");
        scanf("%d", &resp);

    }while(resp == 1);

    concatenaLista(&L, &L2);

    printf("---------- Lista Inicial ----------\n");
    imprimeLista(L);
    printf("Tamanho: %d\n", L.tamanho);
    /*printf("---------- Lista Nova ----------\n");
    L2 = separaLista(&L, 10);
    imprimeLista(L2);
    printf("---------- Lista Nova Inicial ----------\n");
    imprimeLista(L);
    printf("Tamanho: %d\n", L.tamanho);*/

return 0;
}

void iniciaLista(TipoLista *lista){
    lista->primeiro = (Apontador)malloc(sizeof(celula));
    lista->ultimo = lista->primeiro;
    lista->tamanho = 0;
}

int listaVazia(TipoLista *lista){
    return (lista->primeiro == lista->ultimo);
}

void insereLista(TipoItem item, TipoLista *lista){
    lista->ultimo->prox = (Apontador)malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->item = item;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}

int removeLista(Apontador p, TipoLista *lista, TipoItem *item){
    Apontador aux;

    if(listaVazia(lista) || p==NULL || p->prox==NULL){
        printf("Erro! Lista vazia ou posicao invalida.\n");
        return 0;
    }

    aux = p->prox;
    *item = aux->item;
    p->prox = aux->prox;

    if(p->prox == NULL){
        lista->ultimo = p;
    }

    free(aux);
    lista->tamanho--;
}

void imprimeLista(TipoLista lista){
    Apontador aux;
    aux = lista.primeiro->prox;
    while(aux != NULL){
        printf("MEDIA: %.1f\n", aux->item.media);
        aux = aux->prox;
    }
}

/*void insereCrescente(TipoItem Item, TipoLista *lista){
    Apontador aux;
    aux = lista->primeiro;

    while(aux->prox != NULL){
        if(aux->prox->item.matricula > Item.matricula){
            break;
        }
        aux = aux->prox;
    }

    Apontador novo;
    novo = (Apontador)malloc(sizeof(celula));
    novo->item = Item;
    novo->prox = aux->prox;
    if(aux->prox == NULL){
        lista->ultimo = novo;
    }
    lista->ultimo->prox = NULL;
    aux->prox = novo;
    lista->tamanho++;
}*/

/*TipoLista separaLista(TipoLista *lista, TipoChave chave){
    TipoLista novaLista;
    iniciaLista(&novaLista);

    if(listaVazia(lista)){
        return novaLista;
    }

    Apontador aux = lista->primeiro->prox;
    int i = 0;

    while(aux != NULL){
        i++;
        if(chave == aux->item.chave){
            break;
        }
        aux = aux->prox;
    }

    novaLista.primeiro->prox = aux->prox;
    aux->prox = NULL;
    novaLista.ultimo = lista->ultimo;
    lista->ultimo = aux;
    novaLista.tamanho = lista->tamanho - i;
    lista->tamanho = i;

    return novaLista;
}*/


void concatenaLista(TipoLista *lista, TipoLista *lista2){
    lista->ultimo->prox = lista2->primeiro->prox;
    lista->ultimo = lista2->ultimo;
    lista->tamanho = lista->tamanho + lista2->tamanho;
    free(lista2->primeiro);
}























