#include <stdio.h>
#include <string.h>

int minhaStrStr(const char*, const char*);

int main(){
    char *str1 = "Noite";
    char *str2 = "Hoje a noite tem jogo";

    int posicao=minhaStrStr(str1, str2);

    if(posicao==-1)
        printf("A substring %s não está na string %s\n", str1, str2);
    else
        printf("A substring está na posição %d da string %s\n",posicao,str2);
}

int minhaStrStr(const char* substring, const char* todaString){
    if(strlen(substring)>strlen(todaString))
        return -1;

    for(int pos=0; pos<=(strlen(todaString)-strlen(substring)); pos++){ // percorro toda a grande string
        for(int sub=0; sub<strlen(substring); sub++){ // percorro a substring
            if(substring[sub]!=todaString[pos+sub])
                break;
            else
                if(sub==(strlen(substring)-1))
                    return pos;
        }
    }
    return -1;

}