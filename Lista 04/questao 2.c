#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct TipoCelula *Apontador;

struct TipoCelula{
    TipoItem item;
    Apontador prox;
}celula;

typedef struct{
    Apontador topo, fundo;
    int tamanho;
}TipoPilha;

void iniciaPilha();
int pilhaVazia();
void push();
void pop();
void imprimePilha();
void paresNaBase();

int main(){
    TipoPilha pilha;
    TipoItem  item;
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

    printf("========== Pilha ==========\n\n");
    imprimePilha(&pilha);
	
	paresNaBase(&pilha);
	
	printf("========== Pilha Alterada ==========\n\n");
    imprimePilha(&pilha);
    
	
	return 0;
}

void iniciaPilha(TipoPilha* pilha){
    pilha->topo = (Apontador) malloc(sizeof(celula));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int pilhaVazia(TipoPilha* pilha){
    return (pilha->topo == pilha->fundo);
}

void push(TipoPilha* pilha, TipoItem item){
    Apontador aux;
    aux = (Apontador) malloc(sizeof(celula));
    pilha->topo->item = item;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void pop(TipoPilha* pilha, TipoItem* item){
    Apontador aux;

    if(pilhaVazia(pilha)){
        printf("Lista vazia!\n");
        return;
    }
    aux = pilha->topo;
    pilha->topo = aux->prox;
    *item = aux->prox->item;
    free(aux);
    pilha->tamanho--;
}


void imprimePilha(TipoPilha* pilha){
    Apontador aux;
    aux = pilha->topo->prox;
    while(aux!=NULL){
            printf("Chave: %d\n", aux->item.chave);
        aux = aux->prox;
    }
}

void paresNaBase(TipoPilha* pilha){
	TipoPilha pares, impares;
	TipoItem item;
	Apontador aux;
	
	iniciaPilha(&pares);
	iniciaPilha(&impares);
	
	while(!pilhaVazia(pilha)){
		pop(pilha, &item);
		if(item.chave%2==0){
			push(&pares, item);
		}else{
			push(&impares, item);
		}
	}
	
	while(!pilhaVazia(&pares)){
		pop(&pares, &item);
		push(pilha, item);
	}
	
	while(!pilhaVazia(&impares)){
		push(pilha, item);
		pop(&impares, &item);
	}
}









