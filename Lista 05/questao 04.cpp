#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 24

typedef int Apontador;

typedef struct{
	char nome[30];
	long int CPF;
	int hora;
	char sexo;
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

TipoFila existeAgendamento(TipoFila *Fila, TipoItem item);

int main(){
	char resp;
	TipoFila fila;
	TipoItem item;
	
	iniciaFila(&fila);
	
	printf("---------- Agendamento ----------\n\n");
	do{
		printf("Digite o nome: ");
		fflush(stdin);
		fgets(item.nome, 30, stdin);
		item.nome[strlen(item.nome)-1] = '\0';
		
		printf("\nDigite o CPF: ");
		scanf("%d", &item.CPF);
		
		printf("\nDigite o sexo: [m/f]");
		fflush(stdin);
		scanf("%c", &item.sexo);
		
		printf("\nDigite o horario a ser agendado: [Somente numeros inteiros] ");
		scanf("%d", &item.hora);
		
		if(vazia(&fila)){
			enfileirar(item, &fila);
		}else{
			fila = existeAgendamento(&fila, item);
		}
		
		printf("Deseja continuar? [s/n] ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp == 's');
	
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
	return (Fila->numEmelentos == MAX-1);
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
		printf("Nome: %s\n", Fila->item[i].nome);
		printf("CPF: %d\n", Fila->item[i].CPF);
		printf("Sexo: %c\n", Fila->item[i].sexo);
		printf("Hora marcada: %d\n", Fila->item[i].hora);
		i = (i+1) % MAX;
	}
}

TipoFila existeAgendamento(TipoFila *Fila, TipoItem item){
	TipoFila aux;
	TipoItem itemAux;
	bool existe = false;
	int i = Fila->numEmelentos-1;
	
	iniciaFila(&aux);
	while(i>=0){
		desenfileirar(&itemAux, Fila);
		if(itemAux.CPF == item.CPF || item.hora == itemAux.hora){
			enfileirar(itemAux, &aux);
			existe = true;
		}else{
			enfileirar(itemAux, &aux);
		}		
		i--;
	}
	if(existe){
		printf("\nUsuario ja cadastrado ou horario indisponivel!\n");
	}else{
		enfileirar(item, &aux);
	}
	return aux;
}
