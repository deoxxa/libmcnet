CFLAGS += -I ./include -std=c99 -Wall -Werror -Wextra -pedantic -O0 -g

all: prepare example

prepare:
	if [ ! -e obj ]; then mkdir obj; fi;

obj/read.o: src/read.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/read.o src/read.c

obj/parser.o: src/parser.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/parser.o src/parser.c

obj/metadata.o: src/metadata.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/metadata.o src/metadata.c

obj/slot.o: src/slot.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/slot.o src/slot.c

libmcnet.so: obj/read.o obj/parser.o obj/metadata.o obj/slot.o
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o libmcnet.so obj/read.o obj/parser.o obj/metadata.o obj/slot.o

obj/example.o: example.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o obj/example.o example.c

example: obj/example.o libmcnet.so
	$(CC) $(CFLAGS) $(LDFLAGS) -o example obj/example.o obj/read.o obj/parser.o obj/metadata.o obj/slot.o

clean:
	rm -rf obj example libmcnet.so
