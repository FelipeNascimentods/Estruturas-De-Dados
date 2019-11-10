#include <stdio.h>
#include <string.h>
#define max 20

typedef int TipoChave;
typedef int Apontador;

typedef struct{
    TipoChave chave;
    char word[max];
    char letra;
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
void funcaoEspelho();

int main(){
    TipoPilha pilha;
    TipoItem item;
    char resp;

    iniciaPilha(&pilha);

    strcpy(item.word, "A pilha esta cheia");
	push(&pilha, item);

    printf("\n---------- Pilha ----------\n");
    //imprimePilha(&pilha);
	funcaoEspelho(&pilha);
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
        printf("%s", pilha->item[aux].letra);
        aux--;
    }
}

void funcaoEspelho(TipoPilha* pilha){
	if(pilhaVazia(pilha)){
		return;
	}
	TipoPilha aux;
	TipoItem itemAux;
	Apontador i, tam;
	
	iniciaPilha(&aux);
	tam = strlen(pilha->item->word);
	
	for(i=0; i<tam; i++){
		//strcpy(itemAux.word, &pilha->item->word[i]);
		itemAux.letra = &pilha->item->word[i];
		if(itemAux.letra!=' ' && itemAux.letra!='\0'){
			push(&aux, itemAux);
		}else{
			imprimePilha(&aux);
			push(&aux, itemAux);
		}
			
	}
}







