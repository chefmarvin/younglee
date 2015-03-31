CC=gcc
CFLAGS=-O
younglee: younglee.c younglee.h
	$(CC) $(CFLAGS) -o younglee younglee.c younglee.h -lncurses
clean:
	rm -rf *.o younglee
