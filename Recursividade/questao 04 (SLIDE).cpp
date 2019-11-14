// Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])

#include <stdio.h>
#include <string.h>

int tamString(char *str, char c){
	if(str[0] == '\n'){
		return 0;
	}else if(str[0] == c){
		return tamString(&str[1], c) + 1; 
	}
	return tamString(&str[1], c);
}

int main(){
	char str[20], c = 'f';
	
	fgets(str, 20, stdin);
	printf("\n%d\n", tamString(str, c));
	
	return 0;
}
