FLAGS = -lncurses -Wall -fsanitize=address -ggdb

INCLUDE = include

all: main.c
	gcc main.c ${INCLUDE}/windows.c ${FLAGS} -o menu

run:
	./menu

clean:
	rm *.out