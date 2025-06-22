#include <stdio.h>

int meuStrLen(char *str);
char* meuStrChr(char *str, char c);

int main () {

   char str1[12] = "Hello";
   char str2[12] = "World";
   char str3[12];
   int  len;
   printf("O tamanho de %s é %d\n", str1, meuStrLen(str1));
   printf("O tamanho de %s é %d\n", str2, meuStrLen(str2));
   printf("O tamanho de %s é %d\n", str3, meuStrLen(str3));
   
   char c = 'e';
   char *p = meuStrChr(str1, c);
   if(p!=NULL)
	 printf("Encontrou o caracter %c na posição %d (%p)\n",c, p-str1,p);
   else 
	 printf("NÃO encontrou o caracter %c\n", c);
}
   
int meuStrLen(char * str){
	int len=0;
	while(*str!='\0'){
		len++;
		str++;
	}
	return len;
}

char* meuStrChr(char *str, char c){
	while(*str){
		if(*str==c) return str;
		str++;
	}
	return 0;
}
