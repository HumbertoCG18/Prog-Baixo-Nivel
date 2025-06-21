#include <stdio.h>
#include <stdlib.h>

float Plus(float a, float b);
float Minus(float a, float b);
float Multiply(float a, float b);
float Divide(float a, float b);
float (*GetPointer(char opCode))(float, float);
void Switch(float a, float b, char opCode);
void Switch_With_Function_Pointer(float a, float b, float (*pt2Func)(float, float));

int main()
{
   printf("Testando ponteiros para função...\n");

   // instanciando um ponteiro para a funcao Minus
   float (*ptf)(float, float) = &Minus;

   Switch(2, 5, '+'); // '+' define que a funcao 'Plus' sera executada
   printf("Minus (2,5)\n");
   Switch_With_Function_Pointer(2, 5, ptf); // ptf e' um ponteiro para a funcao 'Minus'

   // usando diretamente o endereco para Multiply
   printf("Multiply (6,7)\n");
   Switch_With_Function_Pointer(6, 7, &Multiply); // Multiply é um pont. para a funcao 'Mutiply'

   // usando o metodo GetPointer para Divide
   printf("Divide (6,2)\n");
   ptf = GetPointer('/');
   Switch_With_Function_Pointer(6, 2, ptf); // ptf e' um ponteiro para a funcao 'Divide'
}

float Plus(float a, float b) {
    return a+b;
}

float Minus(float a, float b) {
    return a-b;
}

float Multiply(float a, float b) {
    return a*b;
}

float Divide(float a, float b) {
    return a/b;
}

// Solucao com um switch - <opCode> especifica que operacao executar
void Switch(float a, float b, char opCode)
{
   float result;

   // executa a operacao
   switch(opCode)
   {
      case '+' : result = Plus     (a, b); break;
      case '-' : result = Minus    (a, b); break;
      case '*' : result = Multiply (a, b); break;
      case '/' : result = Divide   (a, b); break;
   }

   printf("Com switch: %f %c %f = %f\n",a,opCode,b,result);
}

float (*GetPointer(char opCode))(float, float)
{
   float (*ptf)(float, float) = NULL;
   // executa a operacao
   switch(opCode)
   {
      case '+' : ptf = &Plus;
      case '-' : ptf = &Minus;
      case '*' : ptf = &Multiply;
      case '/' : ptf = &Divide;
   }
   return ptf;
}

// Solucao com um ponteiro para funcao - <pt2Func> e' um ponteiro para funcao e aponta
// para uma funcao que recebe 2 floats e retorna um float.
// O ponteiro para funcao "define" que operacao deve ser executada
void Switch_With_Function_Pointer(float a, float b, float (*pt2Func)(float, float))
{
   float result = (*pt2Func)(a, b);    // chamada usando ponteiro para funcao

   printf("Switch trocado por ponteiro para função = %f\n", result);
}

// Codigo de teste
void Test()
{

}
