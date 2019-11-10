#include <stdio.h>
#define MaxTam 5
#define InicioVetor 0

typedef int Apontador;

typedef int Tipochave;

typedef struct
{
    Tipochave chave;
    /* outros componentes */
} TipoItem;

typedef struct
{
    TipoItem item[MaxTam];
    Apontador frente, tras;
    int nItens;
} TipoFila;

void Inicia(TipoFila *Fila);
int Vazia(TipoFila *Fila);
void Enfileira(TipoItem x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TipoItem *item);
void Imprime(TipoFila Fila);

void Inicia(TipoFila *Fila)
{
    Fila->frente = 1;
    Fila->tras = Fila->frente;
}

int Vazia(TipoFila *Fila)
{
    return (Fila->frente == Fila->tras);
}

void Imprime(TipoFila Fila)
{
	int count, i;
	for(count = 0, i = Fila.frente; count<Fila.nItens; count++){
		printf("%d\n", Fila.item.chave);
		
		if(i == Fila.tras){
			i = 0;
		}
	}
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (Fila->frente == (Fila->tras % MaxTam) + 1)
    {
        printf ("Erro fila cheia\n");
    }
    else
    {
        Fila->item[Fila->tras-1] = x;
        Fila->tras = (Fila->tras % MaxTam) + 1;
    }
}

void Desenfileira(TipoFila *Fila, TipoItem *item)
{
    if (Vazia(Fila))
    {
        printf(" Erro fila esta vazia\n");
    }
    else
    {
        *item = Fila->item[Fila->frente-1];
        Fila->frente = (Fila->frente % MaxTam) + 1;
    }
}


main()
{
    TipoItem x;
    TipoFila f1;
    Inicia(&f1);

    int op;
    do
    {
        printf ("Entre com a chave\n");
        scanf("%d",&x.chave);
        Enfileira(x,&f1);
        printf ("0 - sair       1 - continuar: ");
        scanf ("%d", &op);
        system ("cls");
    }
    while (op != 0);
    Imprime(f1);
    TipoItem x2;

    /*
        printf ("Desenfileirando...\n");
        Desenfileira(&f1, &x2);
        printf ("Nova fila: \n");
        Imprime(f1);
    */


    Desenfileira(&f1, &x2);
    Desenfileira(&f1, &x2);
    Desenfileira(&f1, &x2);
    Desenfileira(&f1, &x2);
    Desenfileira(&f1, &x2);
    Desenfileira(&f1, &x2);
    printf ("Nova fila: \n");
    Imprime(f1);



    printf ("Enfileirando o 11 \n");
    x2.chave = 11;
    Enfileira(x2, &f1);
    Imprime(f1);

}
