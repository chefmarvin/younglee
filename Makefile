CC=gcc
CFLAGS=-O
younglee: younglee.c younglee.h view.h
	$(CC) $(CFLAGS) -o younglee younglee.c younglee.h view.h -lncurses
clean:
	rm -rf *.o younglee
