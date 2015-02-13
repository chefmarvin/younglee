younglee:
	gcc -Wall -O2 -o younglee younglee.c younglee.h -g -lm -std=c99
clean:
	rm -rf *.o younglee
