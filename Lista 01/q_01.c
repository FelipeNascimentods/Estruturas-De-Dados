#include <stdio.h>
#define MAX 5
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
int verificaListaVazia();
int verificaListaCheia();
int insereLista();
int insereListaPosicao();
void imprimeLista();

int main(){
    TipoLista lista;
    TipoItem item;
    Apontador posicao;
    char resp;

    iniciaLista(&lista);

    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);
        insereLista(&lista, item);

        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp == 's');

    printf("========== Lista ==========\n\n");

    imprimeLista(&lista);

    printf("\nDigite a chave: ");
    scanf("%d", &item.chave);
    printf("Digite a posicao: ");
    scanf("%d", &posicao);
    insereListaPosicao(&lista, posicao, item);

    printf("========== Nova Lista ==========\n\n");


    imprimeLista(&lista);

    return 0;
}

void iniciaLista(TipoLista* lista){
    lista->primeiro = MIN;
    lista->ultimo = lista->primeiro;
}

int verificaListaVazia(TipoLista* lista){
    return lista->primeiro == lista->ultimo;
}

int verificaListaCheia(TipoLista* lista){
    return lista->ultimo > MAX - 1;
}

int insereLista(TipoLista* lista, TipoItem item){
    if(verificaListaCheia(lista)){
        printf("Lista cheia!\n");
        return 0;
    }
    lista->item[lista->ultimo] = item;
    lista->ultimo++;
    return 1;
}

int insereListaPosicao(TipoLista* lista, Apontador posicao, TipoItem item){
    if(verificaListaCheia(lista)){
        printf("Lista cheia!\n");
        return 0;
    }
    else if(posicao>MAX - 1 || posicao<0){
        printf("Posicao invalida!\n");
    }
    Apontador i;
    for(i=lista->ultimo; i>=posicao; i--){
        lista->item[i+1] = lista->item[i];
    }
    lista->item[posicao] = item;
    lista->ultimo++;
    return 1;
}

void imprimeLista(TipoLista* lista){
    if(verificaListaVazia(lista)){
        printf("Lista vazia!\n");
        return;
    }
    Apontador i;
    for(i=lista->primeiro; i<lista->ultimo; i++){
        printf("CHAVE: %d\n", lista->item[i]);
    }
}











