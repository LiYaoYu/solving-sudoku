CC := gcc

#for debug
CFLAGS := -Wall -g -O0 -std=c99

#for performance
#CFLAGS := -Wall -g -O3 -std=c99

INCLUDE := method.c

sudoku: main.c $(INCLUDE)
	$(CC) -o $@ $(CFLAGS) $^

clean:
	rm -rf sudoku
