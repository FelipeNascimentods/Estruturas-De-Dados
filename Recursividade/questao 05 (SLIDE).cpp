// Escreva uma função recursiva que imprima o contrário de um string, contrario(char s[])

#include <stdio.h>

char imprimeInverso(char *str){
	char aux;
	if(str[0] == '\n'){
		return '-';
	}
	printf("%c", aux);
	return  aux = imprimeInverso(&str[1]);
}

int main(){
	char str[20];
	
	fgets(str, 20, stdin);
	printf("\n");
	imprimeInverso(str);
	printf("\n");
}
