PROG    = run.x
FONTES  = matematica.c fazOSomatorio.c fazOFatorial.c principal.c
OBJETOS = $(FONTES:.c=.o)

$(PROG): $(OBJETOS)
	gcc -o $(PROG) $(OBJETOS)

clear:
	rm -f $(OBJETOS) $(PROG)

echo:
	echo $(FONTES) $(OBJETOS) $(PROG)
