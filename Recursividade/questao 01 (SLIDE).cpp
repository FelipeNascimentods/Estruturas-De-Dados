// Escreva uma função recursiva para computar o produto de dois números inteiros positivos em termos da adição.

#include <stdio.h>

int funcao(int n1, int n2);

int main(){
	printf("%d\n", funcao(3, 2));
	return 0;
}

int funcao(int n1, int n2){
	int result = n1;
	if(n2==0){
		result = 0;
	}else{
		result += funcao(n1, n2-1);
	}
	return result;
}
