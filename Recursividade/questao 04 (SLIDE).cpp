// Fazer uma função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])

#include <stdio.h>
#include <string.h>

int tamString(char *str){
	if(str[0] == '\n'){
		return 0;
	}else if(str[0] == 'f'){
		return tamString(&str[1]) + 1; 
	}
	return tamString(&str[1]);
}

int main(){
	char str[20];
	
	fgets(str, 20, stdin);
	printf("\n%d\n", tamString(str));
	
	return 0;
}
