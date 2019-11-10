#include <stdio.h>

int main(){
    int v[5], i, aux, pos, n;

     for(i=0; i<5; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &v[i]);
    }


    printf("Digite n: ");
    scanf("%d", &n);
    printf("Digite pos: ");
    scanf("%d", &pos);

    int j;
    //for(i=pos; i<5; i++){
      for(j=pos; j<5; j++){
        aux = v[j];
        v[j] = v[j+1];
        v[j+1] = aux;
      }
    //}

    for(i=0; i<5; i++){
        printf("%d, ", v[i]);
    }
}
