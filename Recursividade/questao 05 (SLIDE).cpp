// Escreva uma função recursiva que imprima o contrário de um string, contrario(char s[])

#include <stdio.h>

void imprimeInverso(char *str){
	if(*str){
		imprimeInverso(str+1);
		putchar(*str);
	}
}

int main(){
	char str[20];	
	fgets(str, 20, stdin);
	imprimeInverso(str);
}
