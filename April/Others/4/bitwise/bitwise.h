/*
Zera todos os bits: unsigned int clear(unsigned int val)
Seta um único bit: unsigned int setbit (unsigned int x, int bit)
Resseta um único bit: unsigned int clearbit (unsigned int x, int bit)
Inverte o valor de um único bit: unsigned int invertBit (unsigned int x, int bit)
Retorna o estado de um determinado bit: int testBit (unsigned int x, int bit) (retorna 0 ou 1)
*/

unsigned int clear(unsigned int val){
    unsigned int resultado;
    // objetivo, rápido, mas que não faz uso  dos recursos vistos
    resultado = 0;

    // and?
    resultado = val & 0; 
    resultado = val & 0x00000000; //0x0
    resultado = val & 0b00000000000000000000000000000000; //0x0
    
    // or?
    resultado = ~(val | 0xFFFFFFFF);

    // xor?
    resultado = val ^ val;
    resultado = ~(val ^ ~val);

    // deslocamento a direita
    resultado = val >> 32;
    resultado = val >> sizeof(val)*8;
    
    // deslocamento a esquerda
    resultado = val << 32;
    resultado = val << sizeof(val)*8;

    return resultado;
}

//setbit
// x -> valor a ser modificado
// bit -> posição do bit valor x a ser posto em 1
unsigned int setbit (unsigned int x, int bit){
    unsigned int resultado;
    unsigned int mascara = (1 << bit);

    resultado = x | mascara;

    return resultado;
}

unsigned int clearbit (unsigned int x, int bit){
    unsigned int resultado;
    unsigned int mascara = ~(1 << bit);
    resultado &= mascara;
    return resultado;
}