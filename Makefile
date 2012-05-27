CFLAGS += -I ./include -std=c99 -Wall -Werror -Wextra -pedantic -O0 -g

all: bin/example

obj/parser.o: src/parser.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/parser.o src/parser.c

obj/example.o: example.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/example.o example.c

bin/example: obj/parser.o obj/example.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/example obj/example.o obj/parser.o

clean:
	rm -f obj/* bin/*
