#include <stdio.h>
#define max 10
#define inicio 0

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem item[max];
    Apontador topo;
}TipoPilha;

typedef struct{
    TipoItem item[max];
    Apontador primeiro, ultimo;
}TipoLista;

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


void iniciaPilha();
int pilhaVazia();
int pilhaCheia();
int push();
void pop();
void imprimePilha();
void invertePilha();

int main(){
    TipoPilha pilha;
    TipoItem item;
    char resp;

    iniciaPilha(&pilha);

    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);
        push(&pilha, item);

        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp=='s');

    printf("---------- Pilha ----------\n\n");
    imprimePilha(&pilha);

    invertePilha(&pilha);
    printf("---------- Pilha Invertida----------\n\n");
    imprimePilha(&pilha);

    return 0;
}

void iniciaPilha(TipoPilha* pilha){
    pilha->topo = -1;
}

int pilhaVazia(TipoPilha* pilha){
    return pilha->topo == - 1;
}

int pilhaCheia(TipoPilha* pilha){
    return pilha->topo == max - 1;
}

int push(TipoPilha* pilha, TipoItem item){
    if(pilhaCheia(pilha)){
        printf("Lista cheia!\n");
        return 0;
    }
    pilha->topo++;
    pilha->item[pilha->topo] = item;
    return 1;
}

void pop(TipoPilha* pilha, TipoItem* item){
    if(pilhaVazia(pilha)){
        printf("Lista vazia!\n");
        return;
    }
    *item = pilha->item[pilha->topo];
    pilha->topo--;
}

void imprimePilha(TipoPilha* pilha){
    Apontador aux;
    aux = pilha->topo;
    while(aux > -1){
        printf("Chave: %d\n", pilha->item[aux].chave);
        aux--;
    }
}

void invertePilha(TipoPilha *pilha){
    
	if(pilhaVazia(pilha)){
        printf("Lista vazia!\n");
    	return;
    }
	
	TipoItem itemLista;
    TipoLista lista;
	Apontador i;
	
	IniciaLista(&lista);
	
	while(!pilhaVazia(pilha)){
    	pop(pilha, &itemLista);
    	InsereLista(itemLista, &lista);
    }
    
	for(i=lista.primeiro; i<lista.ultimo; i++){
        //RetiraLista(i+1, &lista, &itemLista);
        push(pilha, lista.item[i]);
    }
}




