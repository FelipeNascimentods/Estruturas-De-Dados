// Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])

#include <stdio.h>
#include <string.h>

int tamString(char *str, int i){
	int quant = 0;
	if(str[i] == 'f'){
		quant++;
	}else{
		
	}
}

int main(){
	char str[20];
	int i=0;
	
	fgets(str, 20, stdin);
	printf("\n%d\n", tamString(str, i));
	
	return 0;
}
