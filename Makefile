CFLAGS = -Wall -g

PROG = main
COMPILADOR = gcc
FONTES = main.c bibfunc.c
OBJETOS = ${FONTES:.c=.o}

${PROG}:	${OBJETOS}
		${COMPILADOR} ${CFLAGS} ${OBJETOS} -o $@

all: app2 app3

app2: app2.c diretores.o filmes.o
		${COMPILADOR} ${CFLAGS} $^ -o $@

app3: app3.c diretores.o filmes.o
		${COMPILADOR} ${CFLAGS} $^ -o $@

diretores.o: diretores.c diretores.h
		${COMPILADOR} ${CFLAGS} -c diretores.c

filmes.o: filmes.c filmes.h
		${COMPILADOR} ${CFLAGS} -c filmes.c

clean:
		-@rm -f ${OBJETOS} ${PROG} app2 app3 *.o *.txt.out 