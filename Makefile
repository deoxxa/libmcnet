CFLAGS += -I ./include -std=c99 -Wall -Werror -Wextra -pedantic -O0 -g

all: prepare bin/example

prepare:
	if [ ! -e obj ]; then mkdir obj; fi;
	if [ ! -e bin ]; then mkdir bin; fi;

obj/read.o: src/read.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/read.o src/read.c

obj/parser.o: src/parser.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/parser.o src/parser.c

obj/metadata.o: src/metadata.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/metadata.o src/metadata.c

obj/slot.o: src/slot.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/slot.o src/slot.c

obj/example.o: example.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/example.o example.c

bin/example: obj/read.o obj/parser.o obj/metadata.o obj/slot.o obj/example.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o bin/example obj/example.o obj/read.o obj/parser.o obj/metadata.o obj/slot.o

clean:
	rm -rf obj bin
