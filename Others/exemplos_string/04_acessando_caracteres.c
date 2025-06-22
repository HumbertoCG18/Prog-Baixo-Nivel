//
// Exemplos de acesso a caracteres individuais (com indices ou ponteiros)
// (slides 33-36)
//
#include <stdio.h>

int count_spaces(const char s[]);
int count_spaces_ptr(const char s[]);

int count_spaces(const char s[])
{
    int count = 0;
    for(int i=0; s[i] != '\0'; i++)
        if(s[i] == ' ')
            count++;
    return count;
}

int count_spaces_ptr(const char* s)
{
    int count = 0;
    for(; *s != '\0'; s++)
        if(*s == ' ')
            count++;
    return count;
}

int main()
{
    char* frase = "Esta e' uma frase cheia de espacos em branco";
    printf("A frase: %s\n", frase);
    printf("tem %d espacos em branco (com array)\n", count_spaces(frase));
    printf("tem %d espacos em branco (com ponteiro)\n", count_spaces_ptr(frase));
}
