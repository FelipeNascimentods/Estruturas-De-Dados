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
void topoNoFundo();

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
	
	printf("\n---------- Pilha depois da funcao ----------\n\n");
    topoNoFundo(&pilha);
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
        printf("Pilha cheia!\n");
        return 0;
    }
    pilha->topo++;
    pilha->item[pilha->topo] = item;
    return 1;
}

void pop(TipoPilha* pilha, TipoItem* item){
    if(pilhaVazia(pilha)){
        printf("Pilha vazia!\n");
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

void topoNoFundo(TipoPilha* pilha){
	if(pilhaVazia(pilha)){
        printf("Pilha vazia!\n");
        return;
    }
    
    TipoPilha aux;
    TipoItem itemFundo, itemTopo;
    Apontador i = pilha->topo;
    
    iniciaPilha(&aux);
	pop(pilha, &itemTopo);
    
	while(pilha->topo>0){
    	pop(pilha, &itemFundo);
		push(&aux, itemFundo);
	}
	
	pop(pilha, &itemFundo);
	push(pilha, itemTopo);
	
	while(!pilhaVazia(&aux)){
		pop(&aux, &itemTopo);
		push(pilha, itemTopo);	
	}
	
	push(pilha, itemFundo);
}




