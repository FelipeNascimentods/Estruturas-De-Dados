#include <stdio.h>

void inv(char *string){
   if(*string){
	  inv(string+1);
	  putchar(*string);
   }
}

int main(){
   inv("felipe");
   return 0;
}
