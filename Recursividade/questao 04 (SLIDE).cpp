// Fazer uma fun��o recursiva que conta o n�mero de ocorr�ncias de um determinado caracter, caract(char c, char s[])

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
