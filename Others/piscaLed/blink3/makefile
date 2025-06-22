MCU = atmega328p
CRYSTAL = 16000000

SERIAL_DEV = /dev/ttyUSB0
SERIAL_PROG = /dev/ttyACM0
SERIAL_BAUDRATE=57600

CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size

CFLAGS = -g -mmcu=$(MCU) -Wall -Os -fno-inline-small-functions -fno-split-wide-types -D F_CPU=$(CRYSTAL) -D USART_BAUD=$(SERIAL_BAUDRATE)

AVRDUDE_CONFIG=/usr/local/avr/gcc/etc/avrdude.conf
AVRDUDE_PART=m328p

#PROGRAMMER = bsd
#PROGRAMMER = usbtiny
#PROGRAMMER = dasa -P $(SERIAL_PROG)
#PROGRAMMER = usbasp
PROGRAMMER = arduino -P $(SERIAL_PROG)

all:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o code.elf
	$(OBJCOPY) -R .eeprom -O ihex code.elf code.hex
	$(OBJDUMP) -d code.elf > code.lst
	$(OBJDUMP) -h code.elf > code.sec
	$(SIZE) code.elf

flash:
	avrdude -C $(AVRDUDE_CONFIG) -p $(AVRDUDE_PART) -U flash:w:code.hex -y -c $(PROGRAMMER)

# external high frequency crystal
fuses:
	avrdude -C $(AVRDUDE_CONFIG) -p $(AVRDUDE_PART) -U lfuse:w:0xcf:m -U hfuse:w:0xd9:m -U efuse:w:0x07:m -c $(PROGRAMMER)

# internal rc osc @ 1MHz, original factory config
fuses_osc:
	avrdude -C $(AVRDUDE_CONFIG) -p $(AVRDUDE_PART) -U lfuse:w:0x62:m -U hfuse:w:0xd9:m -U efuse:w:0x07:m -c $(PROGRAMMER)

serial:
	stty ${SERIAL_BAUDRATE} raw cs8 -parenb -crtscts clocal cread ignpar ignbrk -ixon -ixoff -ixany -brkint -icrnl -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke -F ${SERIAL_DEV}

serial_sim:
	socat -d -d  pty,link=/tmp/ttyS10,raw,echo=0 pty,link=/tmp/ttyS11,raw,echo=0

test:
	avrdude -C $(AVRDUDE_CONFIG) -p $(AVRDUDE_PART) -c $(PROGRAMMER)

parport:
	modprobe parport_pc

clean:
	rm -f *.o *.map *.elf *.sec *.lst *.hex *~
