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
	Apontador frente, tras;
	int tamanho;
}TipoFila;

void iniciaFila(TipoFila *Fila){
	Fila->frente = (Apontador)malloc (sizeof(celula));
	Fila->tras = Fila->frente;
	Fila->frente->prox = NULL;
	Fila->tamanho = 0;
}

int vazia(TipoFila *Fila){
	return (Fila->frente==Fila->tras);
}

void enfileirar(TipoItem item, TipoFila *Fila){
	Fila->tras->prox = (Apontador)malloc (sizeof(celula));
	Fila->tras = Fila->tras->prox;
	Fila->tras->item = item;
	Fila->tras->prox = NULL;
	Fila->tamanho++;	
}

void desenfileirar(TipoItem *item, TipoFila *Fila){
	Apontador aux;
	if(vazia(Fila)){
		printf("Erro! Fila vazia.\n");
	}else{
		aux = Fila->frente;
		Fila->frente = Fila->frente->prox;
		*item = Fila->frente->item;
		free(aux);
		Fila->tamanho = Fila->tamanho - 1;
	}
}

void exibirFila(TipoFila *Fila){
	Apontador aux = Fila->frente->prox;
	while(aux != NULL){
		printf("%d\n", aux->item.chave);
		aux = aux->prox;
	}
}

void ordenaCrescente(TipoFila *Fila){
	Apontador aux = Fila->frente;
	TipoFila FAux;
	
	iniciaFila(&FAux);
	
	
	while(aux->prox != NULL){
		if(aux->item.chave > aux->prox->item.chave){
			enfileirar(aux->prox->item, &FAux);		
		}			
		aux = aux->prox;
	}
	exibirFila(&FAux);
}

int main(){
	TipoFila fila;
	TipoItem item;
	
	iniciaFila(&fila);
	
	item.chave = 100;
	enfileirar(item, &fila);
	item.chave = 2;
	enfileirar(item, &fila);
	item.chave = 30;
	enfileirar(item, &fila);
	item.chave = 4;
	enfileirar(item, &fila);
	item.chave = 15;
	enfileirar(item, &fila);
	
	exibirFila(&fila);
	ordenaCrescente(&fila);
	return 0;
}





