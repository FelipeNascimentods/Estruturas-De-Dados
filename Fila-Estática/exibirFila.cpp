#include <stdio.h>

#define MAX 6
#define MIN 0

typedef int Apontador;
typedef int TipoChave;

typedef struct{
	TipoChave chave;
}TipoItem;

typedef struct{
	TipoItem item[MAX];
	Apontador frente, tras;
	int numEmelentos;
}TipoFila;

void iniciaFila(TipoFila *Fila);
int vazia(TipoFila *Fila);
int filaCheia(TipoFila *Fila);
void enfileirar(TipoItem item, TipoFila *Fila);
void desenfileirar(TipoItem *item, TipoFila *Fila);
void imprimir(TipoFila *Fila);

int main(){
	TipoFila fila;
	TipoItem item;
	
	iniciaFila(&fila);
	
	item.chave = 1;
	enfileirar(item, &fila);
	item.chave = 2;
	enfileirar(item, &fila);
	item.chave = 3;
	enfileirar(item, &fila);
	item.chave = 4;
	enfileirar(item, &fila);
	item.chave = 15;
	enfileirar(item, &fila);
	
	imprimir(&fila);
	
	return 0;
}

void iniciaFila(TipoFila *Fila){
	Fila->frente = 1;
	Fila->tras = Fila->frente;
	Fila->numEmelentos = 0;
}

int vazia(TipoFila *Fila){
	return (Fila->frente==Fila->tras);
}

void enfileirar(TipoItem item, TipoFila *Fila){
	if(filaCheia(Fila)){
		printf("Erro! Fila cheia.\n");
	}else{
		Fila->item[Fila->tras-1] = item;
		Fila->tras = (Fila->tras % MAX) + 1;
		Fila->numEmelentos++;
	}
}

int filaCheia(TipoFila *Fila){
	return (Fila->frente==(Fila->tras % MAX) + 1);
}

void desenfileirar(TipoItem *item, TipoFila *Fila){
	if(vazia(Fila)){
		printf("Erro! Fila vazia.\n");
	}else{
		*item = Fila->item[Fila->frente-1];
		Fila->frente = (Fila->frente % MAX)+1;
		Fila->numEmelentos--;
	}
}
void imprimir(TipoFila *Fila){
	printf("\n------ Fila ------\n");
	int i = Fila->frente-1, count;
	for(count = 0; count < Fila->numEmelentos; count++){
		printf("%d ", Fila->item[i].chave);
		i = (i+1) % MAX;
	}
	printf("\n\n");
}

