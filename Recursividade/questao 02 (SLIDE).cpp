// Escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.

#include <stdio.h>

int calculaBase(int base, int expo){
	int result = base;
	if(expo==0){
		result = 1;
	}else{
		result *= calculaBase(base, expo-1);
	}
	return result;
}

int main(){
	printf("Calculo da base: %d", calculaBase(3, 2));
	return 0;
}
