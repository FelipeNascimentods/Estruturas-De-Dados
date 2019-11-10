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
void decimalParaBinario();

int main(){
    TipoPilha pilha;
    TipoItem item;
    int numero;

    iniciaPilha(&pilha);
	
	numero = 13;
	decimalParaBinario(&pilha, numero);
	
    printf("\n---------- Pilha ----------\n");
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
        printf("%d", pilha->item[aux].chave);
        aux--;
    }
}

void decimalParaBinario(TipoPilha* pilha, int numero){
	TipoItem item;
	while(numero>0){
		item.chave = numero%2;
		push(pilha, item);
		numero /= 2;
	}
}




