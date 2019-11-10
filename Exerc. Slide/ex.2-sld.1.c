#include <stdio.h>
#define TAM 10

int main(){
    int vtr[TAM], *p1, *p2, i, ord=0, aux;

    for(i=0; i<TAM; i++){
        scanf("%d", &vtr[i]);
    }

    p1 = vtr;
    p2 = vtr;

    while(ord <= 9){
        for(i=0; i<TAM-1; i++){
            if(p1[i]<p2[i+1]){
                aux = p1[i];
                p1[i] = p2[i+1];
                p2[i+1] = aux;
            }
        }
        ord++;
    }

    for(i=0; i<TAM; i++){
        printf("%d, ", p1[i]);
    }
    return 0;
}
