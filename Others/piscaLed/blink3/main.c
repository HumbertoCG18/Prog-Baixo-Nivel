#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    uint8_t val = 0x1;
    uint16_t i, j;

    DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3) |
            (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7);    // seta PB0 a PB7 como saídas

    PORTB = 0;         // desliga todos os LEDs
    _delay_ms(1000);
    PORTB = 0xff;      // liga todos os LEDs
    _delay_ms(1000);
    PORTB = 0;         // desliga todos os LEDs
    _delay_ms(1000);

    while (1) {
        for (i = 0; i < 16; i++) {    // Liga os LEDs usando uma variável
            PORTB = val;
            val = val << 1;
            if (!val) {
                val = 0x1;
            }
            _delay_ms(500);
        }

        for (j = 0; j < 10; j++) {
            PORTB = 0x1;
            for (i = 0; i < 8; i++) {    // Liga os LEDs usando a leitura da própria porta
                PORTB = PORTB << 1;
                _delay_ms(100);
            }
            PORTB = 0x80;
            for (i = 0; i < 8; i++) {    // Liga os LEDs usando a leitura da própria porta
                PORTB = PORTB >> 1;
                _delay_ms(100);
            }
        }
    }
}
