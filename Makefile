CFLAGS = -Wall -g

PROG = main
FONTES = main.c bibfunc.c
OBJETOS = ${FONTES:.c=.o}

${PROG}:	${OBJETOS}
		gcc ${CFLAGS} ${OBJETOS} -o $@

all: app2 app3

app2: app2.c diretores.o filmes.o
		gcc ${CFLAGS} $^ -o $@

app3: app3.c diretores.o filmes.o
		gcc ${CFLAGS} $^ -o $@

diretores.o: diretores.c diretores.h
		gcc ${CFLAGS} -c diretores.c

filmes.o: filmes.c filmes.h
		gcc ${CFLAGS} -c filmes.c

clean:
		-@rm -f ${OBJETOS} ${PROG} app2 app3 *.o *.txt.out 