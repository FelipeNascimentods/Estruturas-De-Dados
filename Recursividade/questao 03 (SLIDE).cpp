// Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[])

#include <stdio.h>
#include <string.h>

int tamString(char *str, int i){
	int tam;
	if(str[i] == '\n'){
		tam = 0;
	}else{
		i++;
		tam = tamString(str, i) + 1;
	}
	return tam;
}

int tamStringMelhorado(char *str){
	if(str[0]=='\n')
		return 0;
	return 1 + tamStringMelhorado(&str[1]);
}

int main(){
	char str[20];
	int i=0;
	
	fgets(str, 20, stdin);
	printf("\n%d\n", tamString(str, i));
	// teste melhorado
	printf("\n%d\n", tamStringMelhorado(str));
	
	return 0;
}
