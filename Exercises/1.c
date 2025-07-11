#include <stdio.h>

#include <stdlib.h> // Para malloc

#include <ctype.h>  // Para toupper

/* ==================================================================
 * PROTÓTIPOS DAS FUNÇÕES
 * ================================================================== */

// Retorna o número de caracteres de s1.
int STRLEN(char * s1);

// Copia uma string C padrão (s2) para uma new_string (s1).
void STRCPYNULL(char * s1, char * s2);

// Copia uma new_string (s2) para outra new_string (s1).
void STRCPY(char * s1, char * s2);

// Concatena a new_string s2 no final da new_string s1.
void STRCAT(char * s1, char * s2);

// Aloca memória para uma new_string de n caracteres.
char * STRALLOC(int n);

// Converte uma new_string para maiúsculas.
void STRUPPER(char * s1);

/* ==================================================================
 * PROGRAMA DE TESTE
 * ================================================================== */
int main() {
  char str_a[50], str_b[50];
  char * str_c;

  printf("--- INICIANDO TESTES ---\n\n");

  // Teste 1: STRCPYNULL e STRLEN
  printf("1. Testando STRCPYNULL e STRLEN...\n");
  STRCPYNULL(str_a, "teste"); // Copia "teste" (padrão) para str_a (new_string)
  printf("   STRLEN(str_a) retornou: %d (esperado: 5)\n", STRLEN(str_a));
  printf("---------------------------------\n\n");

  // Teste 2: STRCPY
  printf("2. Testando STRCPY...\n");
  STRCPY(str_b, str_a); // Copia str_a (new_string) para str_b (new_string)
  printf("   STRLEN(str_b) apos copia: %d (esperado: 5)\n", STRLEN(str_b));
  printf("---------------------------------\n\n");

  // Teste 3: STRCAT
  printf("3. Testando STRCAT...\n");
  // str_a = "teste" (tam 5), str_b = "PBN" (tam 3)
  STRCPYNULL(str_a, "Ola ");
  STRCPYNULL(str_b, "Mundo!");
  printf("   Concatenando 'Ola ' e 'Mundo!'...\n");
  STRCAT(str_a, str_b);
  printf("   STRLEN(str_a) apos STRCAT: %d (esperado: 11)\n", STRLEN(str_a));
  printf("   Conteudo: ");
  for (int i = 0; i < STRLEN(str_a); i++) printf("%c", *(str_a + 1 + i));
  printf("\n---------------------------------\n\n");

  // Teste 4: STRALLOC
  printf("4. Testando STRALLOC...\n");
  str_c = STRALLOC(10); // Aloca espaço para uma new_string de 10 chars
  if (str_c != NULL) {
    printf("   Memoria alocada com sucesso.\n");
    // Vamos usar a memória alocada
    STRCPYNULL(str_c, "alocado");
    printf("   STRLEN(str_c) apos copia: %d (esperado: 7)\n", STRLEN(str_c));
    printf("---------------------------------\n\n");
  } else {
    printf("   Falha na alocacao de memoria.\n");
  }

  // Teste 5: STRUPPER
  printf("5. Testando STRUPPER...\n");
  printf("   String original: ");
  for (int i = 0; i < STRLEN(str_c); i++) printf("%c", *(str_c + 1 + i));
  printf("\n");
  STRUPPER(str_c);
  printf("   String em maiusculas: ");
  for (int i = 0; i < STRLEN(str_c); i++) printf("%c", *(str_c + 1 + i));
  printf("\n---------------------------------\n\n");

  free(str_c); // Libera a memória alocada por STRALLOC

  return 0;
}

/* ==================================================================
 * IMPLEMENTAÇÃO DAS FUNÇÕES
 * ================================================================== */

/**
 * Retorna o tamanho de uma new_string.
 * O tamanho está no primeiro byte. Basta desreferenciar o ponteiro.
 */
int STRLEN(char * s1) {
  return * s1;
}

/**
 * Copia uma string C padrão (s2, com '\0') para uma new_string (s1).
 */
void STRCPYNULL(char * s1, char * s2) {
  // 1. Achar o tamanho da string de origem (s2)
  int tamanho = 0;
  char * p_aux = s2;
  while ( * p_aux != '\0') {
    tamanho++;
    p_aux++;
  }

  // 2. Gravar o tamanho no primeiro byte do destino (s1)
  * s1 = tamanho;

  // 3. Copiar os caracteres
  char * p_origem = s2;
  char * p_destino = s1 + 1; // O texto começa no segundo byte
  while ( * p_origem != '\0') {
    * p_destino = * p_origem;
    p_destino++;
    p_origem++;
  }
}

/**
 * Copia uma new_string (s2) para outra new_string (s1).
 */
void STRCPY(char * s1, char * s2) {
  // 1. Obter o tamanho da string de origem (s2). É mais fácil que na STRCPYNULL.
  int tamanho = * s2;

  // 2. Copiar todos os bytes necessários: 1 byte para o tamanho + 'tamanho' bytes para o texto.
  char * p_origem = s2;
  char * p_destino = s1;
  for (int i = 0; i < tamanho + 1; i++) {
    * p_destino = * p_origem;
    p_destino++;
    p_origem++;
  }
}

/**
 * Concatena a new_string s2 no final da new_string s1.
 */
void STRCAT(char * s1, char * s2) {
  // 1. Obter os tamanhos de ambas as strings
  int tam1 = * s1;
  int tam2 = * s2;

  // 2. Definir os ponteiros de origem e destino
  // O destino começa no primeiro byte livre de s1 (após o texto original)
  char * p_destino = s1 + 1 + tam1;
  // A origem começa no primeiro byte de DADO de s2 (após o tamanho)
  char * p_origem = s2 + 1;

  // 3. Copiar 'tam2' caracteres da origem para o destino
  for (int i = 0; i < tam2; i++) {
    * p_destino = * p_origem;
    p_destino++;
    p_origem++;
  }

  // 4. Atualizar o byte de tamanho de s1 com a nova soma
  * s1 = tam1 + tam2;
}

/**
 * Aloca memória para uma new_string de n caracteres.
 */
char * STRALLOC(int n) {
  // Precisamos alocar 'n' bytes para os caracteres + 1 byte para o tamanho.
  char * ponteiro_alocado = (char * ) malloc(n + 1);
  return ponteiro_alocado;
}

/**
 * Converte uma new_string para maiúsculas.
 */
void STRUPPER(char * s1) {
  int tamanho = * s1;
  // O ponteiro começa a "andar" a partir do primeiro caractere (s1 + 1)
  char * p_texto = s1 + 1;

  for (int i = 0; i < tamanho; i++) {
    // Usa a função toupper da biblioteca ctype.h para converter o caractere.
    // A desreferência *p_texto altera o valor diretamente na memória.
    * p_texto = toupper( * p_texto);
    p_texto++; // Avança para o próximo caractere
  }
}