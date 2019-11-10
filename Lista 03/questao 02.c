#include <stdio.h>
#include <stdlib.h>
#define max 10
#define inicio 0

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem item[max];
    Apontador primeiro, ultimo;
}TipoLista;

void IniciaLista();
int ListaVazia();
int RetiraLista();
int InsereLista();
void ImprimeLista();
int busca();
void ordenaLista();

int main(){
    TipoLista L;
    TipoItem item[max], teste;
    Apontador posicao;

    IniciaLista(&L);

    char resp;
    int i=0;
    do{
        printf("Digite a chave: ");
        scanf("%d", &item[i].chave);
        InsereLista(item[i], &L);
        i++;
        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp == 's');

    printf("\n---------- LISTA ----------\n\n");
    ordenaLista(&L);
    ImprimeLista(&L);

    printf("\n\nDigite o elemento desejado: ");
    scanf("%d", &teste.chave);

    posicao = busca(&L, teste);
    printf("\nPosicao do elemento buscado: %d\n", posicao-1);

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
    Apontador i;
    for(i=Lista->primeiro; i<Lista->ultimo; i++){
        printf("%d\n", Lista->item[i].chave);\
    }
}

//FUNÇÃO QUE REALIZA A BUSCA
int busca(TipoLista *Lista, TipoItem item){
    Apontador i, posicao = 0;
    for(i=Lista->primeiro; i<Lista->ultimo; i++){
        if(Lista->item[i].chave == item.chave){
            printf("\n\nBusca realizada com sucesso!\n");
            posicao = i + 1;
            return posicao;
        }else if(Lista->item[i].chave > item.chave){
            break;
        }
    }
    printf("\n\nBusca nao realizada! O elemento nao foi encontrado.\n");
    return posicao;
}

// FUNÇÃO QUE ORDENA A LISTA
void ordenaLista(TipoLista* lista){
    Apontador i, j;
    TipoItem aux;
    for(i=lista->primeiro; i<lista->ultimo; i++){
        for(j=i+1; j<lista->ultimo; j++){
            if(lista->item[i].chave > lista->item[j].chave){
                aux = lista->item[i];
                lista->item[i] = lista->item[j];
                lista->item[j] = aux;
            }
        }
    }
}




