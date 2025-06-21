# Makefile para Linux e macOS

PROG = glshapes
FONTES = main.c
OBJETOS = $(FONTES:.c=.o)

FONTES2 = shapes.c
OBJETOS2 = $(FONTES2:.c=.o)

CFLAGS = -g -O3 -DGL_SILENCE_DEPRECATION -Wno-deprecated # -Wall -g  # Todas as warnings, infos de debug

UNAME = $(shell uname)

ifeq ($(UNAME),Darwin)
	LDFLAGS = -framework OpenGL -framework Cocoa -framework GLUT -lm
else
	LDFLAGS = -lGL -lGLU -lglut
endif

$(PROG): $(OBJETOS) libshapes2.so
	$(CC) $(CFLAGS) $(OBJETOS) $(LDFLAGS) -o $(PROG) -L. -lshapes2 -lm
#	$(CC) $(CFLAGS) $(OBJETOS) $(LDFLAGS) -o $(PROG) -L. -lshapes -lm

libshapes.a: $(OBJETOS2)
	ar rcs libshapes.a $(OBJETOS2)

libshapes2.so: $(OBJETOS2)
	gcc -fPIC -shared -o libshapes2.so $(OBJETOS2) $(LDFLAGS)

ultraclean:
	-@ rm -f $(OBJETOS) $(PROG) $(OBJETOS2) libshapes.a $(PROG)

clean:
	-@ rm -f $(OBJETOS) $(PROG) $(OBJETOS2) libshapes.a
