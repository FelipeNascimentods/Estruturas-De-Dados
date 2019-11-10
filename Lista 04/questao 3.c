#include <stdio.h>
#define max 10

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem item[max];
    Apontador topo;
}TipoPilha;

void iniciaPilha();
int pilhaVazia();
int pilhaCheia();
int push();
void pop();
void imprimePilha();
void concatenaPilha();

int main(){
    TipoPilha pilha, pilha2, pilha3;
    TipoItem item;
    char resp;

    iniciaPilha(&pilha);
    iniciaPilha(&pilha2);
    iniciaPilha(&pilha3);
	
	printf("---------- Pilha ----------\n\n");
    do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);
        push(&pilha, item);

        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp=='s');
	
	printf("\n---------- Pilha2 ----------\n\n");
	do{
        printf("Digite a chave: ");
        scanf("%d", &item.chave);
        push(&pilha2, item);

        printf("Deseja continuar? [s/n] ");
        fflush(stdin);
        scanf("%c", &resp);
    }while(resp=='s');

    printf("\n---------- Pilha ----------\n\n");
	imprimePilha(&pilha);
    printf("\n---------- Pilha2 ----------\n\n");
	imprimePilha(&pilha2);
	printf("\n---------- Pilha2 ----------\n\n");
	concatenaPilha(&pilha, &pilha2, &pilha3);
	imprimePilha(&pilha3);
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
    TipoItem item;
	Apontador aux;
    aux = pilha->topo;
    while(aux > -1){
        printf("Chave: %d\n", pilha->item[aux].chave);
        aux--;
    }
}

void concatenaPilha(TipoPilha* p1, TipoPilha* p2, TipoPilha* p3){
	TipoItem item;
	Apontador aux, i;
	
	while(!pilhaVazia(p1)){
		pop(p1, &item);
		push(p3, item);
	}
	
	while(!pilhaVazia(p2)){
		pop(p2, &item);
		push(p3, item);
	}
	
}




