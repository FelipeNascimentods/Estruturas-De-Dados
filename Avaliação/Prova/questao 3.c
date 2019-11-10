#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoChave;

//Estrutura do item;
typedef struct{
    char nome[50];
    char link[50];
}TipoItem;

//Estrutura do apontador;
typedef struct TipoCelula *Apontador;

//Estrutura da celula;
struct TipoCelula{
    TipoItem item;
    Apontador prox;
}celula;

//Estrutura da lista;
typedef struct{
    Apontador primeiro, ultimo;
    int tamanho;
}TipoLista;

void inicia();
void insere();
int vazia();
void remover();
void imprime();
void busca();

int main(){
    TipoLista L;
    TipoItem item;
    int resp;

    inicia(&L);//inicia a lista encadeada;

    printf("---------- Lista ----------\n\n");
    do{
        printf("Digite o nome: ");
        fflush(stdin);
        gets(item.nome);
        printf("Digite o link: ");
        fflush(stdin);
        gets(item.link);

        insere(item, &L);

        printf("Digite 1 para continuar ou 0 para sair: ");
        scanf("%d", &resp);
        fflush(stdin);
    }while(resp == 1);
    printf("---------- Imprimindo Lista ----------\n\n");
    imprime(L);
    printf("---------- Buscar ----------\n\n");
    printf("Digite o nome: ");
    fflush(stdin);
    gets(item.nome);
    busca(item, &L);

    return 0;
}
//inicia a lista encadeada;
void inicia(TipoLista *Lista){
    Lista->primeiro = (Apontador)malloc(sizeof(celula));//aloca um espa�o de mem�ria do tipo celula para o primeiro apontador;
    Lista->ultimo = Lista->primeiro;//o apontador ultimo recebe o endere�o do apontador primeiro;
    Lista->tamanho = 0;// inicializa o tamanho da lista;
}
//verifica se a lista est� vazia;
int vazia(TipoLista *Lista){
    return(Lista->primeiro == Lista->ultimo);//retorna 1 se a lista estiver vazia, -1 se estiver preenchida;
}
//insere um elemento, indicado previamente, na lista;
void insere(TipoItem item , TipoLista *Lista){
    Lista->ultimo->prox = (Apontador)malloc(sizeof(celula));//o apontador ultimo.prox recebe um espa�o de mem�ria do tipo celula;
    Lista->ultimo = Lista->ultimo->prox;//o apontador ultimo recebe o espa�o que foi alocado ao ultimo.prox;
    Lista->ultimo->item = item;//o item � inserido na ultima posi��o v�lida da lista;
    Lista->ultimo->prox = NULL;//o umtimo.prox aponta para um endere�o nulo;
    Lista->tamanho = Lista->tamanho++;//o tamanho da lista � incrementado;
}
//remove um item/celula de uma posi��o (apontador) indicado previamente;
void remover(Apontador p, TipoLista *Lista, TipoItem *item){
    //OBS: o item a ser removido � o seguinte ao apontado por p;
    Apontador aux;
    if(vazia(Lista) || p==NULL || p->prox==NULL){//se a lista estiver vazia, p for nulo ou p.prox for nulo dar� erro;
        printf("Erro! Lista vazia ou inexistente.\n");
        return 0;
    }
    aux = p->prox;//pAux recebe o endere�o do p.prox;
    *item = aux->item;
    p->prox = aux->prox;

    if(p->prox==NULL){
        Lista->ultimo = p;
    }

    free(aux);
    Lista->tamanho--;
}
//imprime a lista;
void imprime(TipoLista Lista){
    Apontador Aux;
    Aux = Lista.primeiro->prox;//o apontador Aux recebe o endere�o da pr�xima c�lula do apontador primeiro;
    while (Aux != NULL){//enquanto Aux n�o apontar para o nulo ser� imoresso a chave (item);
        printf("Nome: %s\n", Aux->item.nome);
        printf("LINK: %s\n", Aux->item.link);
        Aux = Aux->prox;//aux recebe o endere�o da pr�xima c�lula;
    }
}

void busca(TipoItem item, TipoLista *L){
    Apontador aux = L->primeiro->prox;

    if(vazia(L)){
        printf("Lista vazia!\n");
        return;
    }
     while(aux != NULL){
        if(!strcmp(item.nome, aux->item.nome)){
            printf("\n%s\n", aux->item.link);
            break;
        }
        aux = aux->prox;
    }

}














