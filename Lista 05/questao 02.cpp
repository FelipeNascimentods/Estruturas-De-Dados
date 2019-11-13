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

void exibirLista(TipoFila *Fila){
	Apontador aux = Fila->frente->prox;
	while(aux != NULL){
		printf("%d\n", aux->item.chave);
		aux = aux->prox;
	}
}

void divideParImpar(TipoFila *Fila){
	TipoFila Par, Impar;
	TipoItem item;
	Apontador aux= Fila->frente->prox;
	
	iniciaFila(&Par);
	iniciaFila(&Impar);
	
	while(aux != NULL){
		desenfileirar(&item, Fila);
		if (item.chave%2==0){
			enfileirar(item, &Par);
		}else{
			enfileirar(item, &Impar);
		}
		aux = aux->prox;
	}
	printf("\n----- Fila Par -----\n");
	exibirLista(&Par);
	printf("\n\n----- Fila Impar -----\n");
	exibirLista(&Impar);	
}

int main(){
	TipoFila Fila;
	TipoItem item;
	char resp;
	
	iniciaFila(&Fila);
	
	do{
		printf("Digite a chave: ");
		scanf("%d", &item.chave);
		enfileirar(item, &Fila);
		
		printf("Digite 's' para continuar ou 'n' para sair: ");
		fflush(stdin);
		scanf("%c", &resp);	
	}while(resp == 's');
	
	divideParImpar(&Fila);
	return 0;
}





