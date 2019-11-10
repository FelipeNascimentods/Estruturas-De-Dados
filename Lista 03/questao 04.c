#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

//Estrutura do item;
typedef struct{
    TipoChave chave;
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
void criaNovaLista();
int busca();

int main(){
    TipoLista L;
    TipoItem item;
    char resp;

    inicia(&L);//inicia a lista encadeada;

    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);

        insere(item, &L);
        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp == 's');

    system("cls");

    printf("***** Lista Original *****\n\n");
    imprime(L);

    printf("\n\nDigite a chave que deseja buscar: ");
    scanf("%d", &item.chave);
    busca(&L, item);

    return 0;
}
//inicia a lista encadeada;
void inicia(TipoLista *Lista){
    Lista->primeiro = (Apontador)malloc(sizeof(celula));//aloca um espaço de memória do tipo celula para o primeiro apontador;
    Lista->ultimo = Lista->primeiro;//o apontador ultimo recebe o endereço do apontador primeiro;
    Lista->tamanho = 0;// inicializa o tamanho da lista;
}
//verifica se a lista está vazia;
int vazia(TipoLista *Lista){
    return(Lista->primeiro == Lista->ultimo);//retorna 1 se a lista estiver vazia, -1 se estiver preenchida;
}
//insere um elemento, indicado previamente, na lista;
void insere(TipoItem item , TipoLista *Lista){
    Lista->ultimo->prox = (Apontador)malloc(sizeof(celula));//o apontador ultimo.prox recebe um espaço de memória do tipo celula;
    Lista->ultimo = Lista->ultimo->prox;//o apontador ultimo recebe o espaço que foi alocado ao ultimo.prox;
    Lista->ultimo->item = item;//o item é inserido na ultima posição válida da lista;
    Lista->ultimo->prox = NULL;//o umtimo.prox aponta para um endereço nulo;
    Lista->tamanho = Lista->tamanho++;//o tamanho da lista é incrementado;
}
//remove um item/celula de uma posição (apontador) indicado previamente;
void remover(Apontador p, TipoLista *Lista, TipoItem *item){
    //OBS: o item a ser removido é o seguinte ao apontado por p;
    Apontador pAux;
    if(vazia(Lista) || p==NULL || p->prox==NULL){//se a lista estiver vazia, p for nulo ou p.prox for nulo dará erro;
        printf("Erro! Lista vazia ou inexistente.\n");
        return 0;
    }
    pAux = p->prox;//pAux recebe o endereço do p.prox;
    *item = pAux->item;
    p->prox = pAux->prox;
    if(p->prox==NULL){
        Lista->ultimo = p;
        free(pAux);
        Lista->tamanho--;
    }
}
//imprime a lista;
void imprime(TipoLista Lista){
    Apontador Aux;
    Aux = Lista.primeiro->prox;//o apontador Aux recebe o endereço da próxima célula do apontador primeiro;
    while (Aux != NULL){//enquanto Aux não apontar para o nulo será imoresso a chave (item);
        printf("Chave: %d\n", Aux->item.chave);
        Aux = Aux->prox;//aux recebe o endereço da próxima célula;
    }
}
//vria uma lista de aprovados e outra de reprovados;
/*void criaNovaLista(TipoLista l, TipoLista *ap, TipoLista *rp){
    Apontador Aux;
    Aux = l.primeiro->prox;//o apontador Aux recebe o endereço da próxima célula do apontador primeiro;
    if (vazia(&l)){
        printf("Lista vazia\n");
        return 0;
    }
    while (Aux != NULL){//enquanto Aux não apontar para o nulo será imoresso a chave (item);
        if(Aux->item.nota>=7){
            insere(Aux->item, ap);
        }
        else{
            insere(Aux->item, rp);
        }
        Aux = Aux->prox;//aux recebe o endereço da próxima célula;
    }
}*/

// FUNÇÃO QUE REALIZA A BUSCA
int busca(TipoLista* lista, TipoItem item){
    Apontador aux, ant;
    aux = lista->primeiro->prox;
    ant = lista->primeiro;
    if(vazia(lista)){
        printf("A lista esta vazia!\n");
        return 0;
    }
    while(!aux == NULL){
        if(aux->item.chave == item.chave){
            printf("\nBusca realizada com sucesso!\n");
            return ant;
        }
        aux = aux->prox;
        ant = ant->prox;
    }
    printf("O item buscado nao pode ser encontrado!\n");
    return 0;
}





