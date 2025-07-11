#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "adc.h"
#include "print.h"
#include "usart.h"

int main() {
  float val1;

  USART_Init();
  adc_init();

  for (;;) {
    adc_set_channel(0);
    val1 = adc_read() * 0.0009765625;

    print("\nv1: ");
    printfloat(val1);
  }

  return 0;
}
