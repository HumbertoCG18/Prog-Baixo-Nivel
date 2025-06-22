# Makefile para Linux e macOS

PROG = glshapes
FONTES = main.c
OBJETOS = $(FONTES:.c=.o)
CFLAGS = -g -O3 -DGL_SILENCE_DEPRECATION -Wno-deprecated # -Wall -g  # Todas as warnings, infos de debug
FONTES2 = shapes.c
OBJ2 = $(FONTES2:.c=.o)
UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
	LDFLAGS = -framework OpenGL -framework Cocoa -framework GLUT -lm
else
	LDFLAGS = -lGL -lGLU -lglut -lm
endif

$(PROG): $(OBJETOS) libshapes.a
	$(CC) $(CFLAGS) $(OBJETOS) $(LDFLAGS) -o $(PROG) -L. -lshapes

libshapes.a: $(OBJ2)
	ar rcs libshapes.a $(OBJ2)

libshapes2.so: $(OBJ2)
	gcc -fPIC -shared -o libshapes2.so $(OBJ2) $(LDFLAGS)

glshapes-shared: $(OBJETOS) libshapes2.so
	$(CC) $(OBJETOS) -o glshapes-shared -L. -lshapes2 $(LDFLAGS)

clean:
	-@ rm -f $(OBJETOS) $(OBJ2) $(PROG)
