CFLAGS = -Wall -g    # Opções do compilador: todos warnings e debug info

PROG = main
FONTES = main.c bibfunc.c biboutra.c
OBJETOS = $(FONTES:.c=.o)

$(PROG): $(OBJETOS)
	gcc $(CFLAGS) $(OBJETOS) -o $@

clean:
	-@ rm -f $(OBJETOS) $(PROG)
