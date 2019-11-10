#include <stdio.h>
#include <stdlib.h>
#define max 10
#define min 0

typedef int Apontador;
typedef int TipoChave;

typedef struct{
    TipoChave chave;
    char nome[20];
}TipoItem;

typedef struct{
    TipoItem item[max];
    Apontador primeiro, ultimo;
}Lista;

void inicia_lista();
int insere_list();
void ordena_lista();
int verifica_pos();
void imprime_lista();
int main(){
    Lista L;
    TipoItem Item;
    int pos, resp, aux;

    inicia_lista(&L);
    //do{
        printf("Digite o nome do item: ");
        fflush(stdin);
        fgets(Item.nome, 20, stdin);
        do{
            printf("Digite a posicao em que deseja inserir o item: ");
            scanf("%d", &pos);
            aux = verifica_pos(pos);
        }while(aux != 1);

        aux = insere_lista(Item, &L, pos);
        //printf("Digite (1) para continuar ou (0) para sair: ");
        //scanf("%d", &resp);
        imprime_lista(&L);
    //}while(resp == 1);
    return (0);
}

void inicia_lista(Lista *L){
    int i;
    L->primeiro = min;
    L->ultimo = L->primeiro;
    for(i=min; i<max; i++){
        L->item[i].chave = 0;
    }
}

int insere_lista(TipoItem novo, Lista *L, int pos){
    if(L->ultimo>=max){
        printf("Lista Cheia!\n");
        system("pause");
        return (0);
    }else{
        L->item[pos] = novo;
        L->item[pos].chave = 1;
        L->ultimo = pos+1;
        return (1);
    }
}

int verifica_pos(pos){
    if(pos>=min && pos<max-1){
        return (1);
    }else{
        printf("Posicao invalida!\n");
        system("pause");
        return (0);
    }
}

void imprime_lista(Lista *L){
    int i;
    for(i=min; i<max; i++){
        if(L->item[i].chave==1){
            printf("Nome: %s\n", L->item[i].nome);
        }
    }
    system("pause");
}

/*void ordena_lista(Lista *L, int pos){
    int i, j;
    for(i=min; i<max; i++){
        if(i==pos){
            //L->item[pos] = L->item[L->ultimo];
            for(j=pos; j<=(L->ultimo); j++){
                aux = L->item[j+1];
                L->item[j+1] = L->item[j];
                L->item[j] = aux;
            }
        }
    }
}*/
