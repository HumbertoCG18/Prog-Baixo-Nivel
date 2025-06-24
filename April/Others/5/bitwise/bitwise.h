/*
Zera todos os bits: unsigned int clear(unsigned int val)
Seta um único bit: unsigned int setbit (unsigned int x, int bit)
Resseta um único bit: unsigned int clearbit (unsigned int x, int bit)
Retorna o estado de um determinado bit: int testBit (unsigned int x, int bit) (retorna 0 ou 1)
Inverte o valor de um único bit: unsigned int invertBit (unsigned int x, int bit)
*/

unsigned int clear(unsigned int val);
unsigned int setbit (unsigned int x, int bit);
unsigned int clearbit (unsigned int x, int bit);
unsigned int invertBit (unsigned int x, int bit);
int testBit (unsigned int x, int bit);
