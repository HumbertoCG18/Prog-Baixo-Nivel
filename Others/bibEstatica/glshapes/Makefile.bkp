# Makefile para Linux e macOS

PROG = glshapes
FONTES = main.c shapes.c
OBJETOS = $(FONTES:.c=.o)
CFLAGS = -g -O3 -DGL_SILENCE_DEPRECATION -Wno-deprecated # -Wall -g  # Todas as warnings, infos de debug

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
	LDFLAGS = -framework OpenGL -framework Cocoa -framework GLUT -lm
else
	LDFLAGS = -lGL -lGLU -lglut -lm
endif

$(PROG): $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) $(LDFLAGS) -o $(PROG)

clean:
	-@ rm -f $(OBJETOS) $(PROG)
