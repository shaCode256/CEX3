CC= gcc
FLAGS= -Wall

all: twoPrograms

twoPrograms:  isort.o txtfind.o
	$(CC) $(FLAGS) isort.o -o isort
	$(CC) $(FLAGS) txtfind.o -o txtfind

isort.o: isort.c txtfind.h
	$(CC) $(FLAGS) -c isort.c -o $@

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c -o $@

clean:
	rm *.o isort txtfind

.PHONY: all clean