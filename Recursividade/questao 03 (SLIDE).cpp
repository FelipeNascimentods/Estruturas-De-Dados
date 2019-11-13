// Escrever uma função recursiva que retorna o tamanho de um string, tamstring(char s[])

#include <stdio.h>
#include <string.h>

int tamString(char *str, int i){
	int tam;
	if(str[i] == '\n'){
		tam = 0;
		i = 0;
	}else{
		i++;
		tam = tamString(str, i) + 1;
	}
	return tam;
}

int main(){
	char str[20];
	int i=0;
	
	fgets(str, 20, stdin);
	printf("\n%d\n", tamString(str, i));
	
	return 0;
}
