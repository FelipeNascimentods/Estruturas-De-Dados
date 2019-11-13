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
		Fila->tamanho--;
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
	Apontador aux = Fila->frente->prox;
	TipoItem itens[Fila->tamanho], item;
	int i = 0, j, k;
	
	while(aux != NULL){
		desenfileirar(&item, Fila);
		itens[i] = item;
		i++;
		
		aux = aux->prox;
	}
	
	for(j = 0; j<i; j++){
		for(k = j; k<i; k++){
			if(itens[j].chave > itens[k].chave){
				item = itens[j];
				itens[j] = itens[k];
				itens[k] = item;
			}
		}
	}
	
	for(j = 0; j<i; j++){
		enfileirar(itens[j], Fila);
	}	
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

	printf("\nOrdenando a fila...\n");
	ordenaCrescente(&fila);

	exibirFila(&fila);
	return 0;
}






