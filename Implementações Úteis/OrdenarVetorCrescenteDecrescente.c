#include <stdio.h>
#define MAX 10

void ordenarCrescente(int vetor[MAX]);
void ordenarDecrescente(int vetor[MAX]);
void imprimirVetor(int vetor[MAX]);

int main(){
    int vetor[MAX];

    int i;
    vetor[0] = 10;
    vetor[1] = 9;
    vetor[2] = 8;
    vetor[3] = 5;
    vetor[4] = 2;
    vetor[5] = 1;
    vetor[6] = 6;
    vetor[7] = 8;
    vetor[8] = 3;
    vetor[9] = 7;

    ordenarCrescente(vetor);
    imprimirVetor(vetor);
    ordenarDecrescente(vetor);
    imprimirVetor(vetor);
}

void ordenarCrescente(int vetor[MAX]){
    int i, j, aux;

    for(i=0; i<MAX; i++){
        for(j=i; j<MAX; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void imprimirVetor(int vetor[MAX]){
    int i;
    for(i=0; i<MAX; i++){
        printf("\n%d ", vetor[i]);
    }
}

void ordenarDecrescente(int vetor[MAX]){
    int i, j, aux;

    for(i=0; i<MAX; i++){
        for(j=i; j<MAX; j++){
            if(vetor[i] < vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
