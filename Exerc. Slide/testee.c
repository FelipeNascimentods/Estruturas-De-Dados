#include <stdio.h>

int main(){
    int vtr[5], i, aux, ord=0;

    for(i=0 ;i<5; i++){
        scanf("%d", &vtr[i]);
    }

    while(ord <= 4){
        for(i=0; i<4; i++){
            if(vtr[i]<vtr[i+1]){
                aux = vtr[i];
                vtr[i] = vtr[i+1];
                vtr[i+1] = aux;
            }
        }
        ord++;
    }
    for(i=0; i<5; i++){
        printf("%d, ", vtr[i]);
    }
}
