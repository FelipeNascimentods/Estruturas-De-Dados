
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int TipoChave;

typedef struct{
	TipoChave numeroRegistro;
	char nome[30];
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

void exibirCaracteristicas(TipoFila *Fila){
	Apontador aux = Fila->frente->prox;
	printf("\n---------- Caracteristicas das aeronaves ----------\n");
	while(aux != NULL){
		printf("Nome: %s\n", aux->item.nome);
		printf("Numero: %d\n", aux->item.numeroRegistro);
		aux = aux->prox;
	}
}

void exibirProximoADecolar(TipoFila *Fila){
	Apontador aux = Fila->frente->prox;
	printf("\n---------- Caracteristicas Do Proximo A Decolar ----------\n");
	printf("Nome: %d\n", aux->item.nome);
	printf("Numero: %d\n", aux->item.numeroRegistro);
}

int main(){
	char resp;
	TipoFila fila;
	TipoItem item;
	
	iniciaFila(&fila);
	printf("---------- AEROPORTO ----------\n\n");
	do{
		printf("Digite o numero de registro da aeronave: ");
		scanf("%d", &item.numeroRegistro);
		printf("Digite o nome/compania da aeronave: ");
		fflush(stdin);
		fgets(item.nome, 30, stdin);
		item.nome[strlen(item.nome)-1] = '\0';
		
		enfileirar(item, &fila);
		
		printf("Deseja continuar? [s/n] ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp == 's');
	
	printf("\nNumero de avioes a espera da decolagem = %d\n", fila.tamanho);
	
	desenfileirar(&item, &fila);
	printf("\nDecolagem do %s - %d\n", item.nome, item.numeroRegistro);
	
	exibirCaracteristicas(&fila);
	
	printf("\nProximo a decolar: %s - %d\n", fila.frente->prox->item.nome, fila.frente->prox->item.numeroRegistro);
	return 0;
}





