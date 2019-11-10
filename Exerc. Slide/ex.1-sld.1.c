#include <stdio.h>
#define TAM 100
int main(){
    int vtr[TAM], i, *p;
    float media=0;

    for(i=0; i<TAM; i++){
        scanf("%d", &vtr[i]);
    }

    p = vtr;

    for(i=0; i<TAM; i++){
        media = media + p[i];
    }

    media = media/TAM;

    printf("Media = %.2f\n", media);

    return 0;
}
