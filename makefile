FLAGS = -lncurses -Wall

all: main.c
	gcc main.c ${FLAGS} -o menu

run:
	./menu

clean:
	rm *.out