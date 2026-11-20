CC = gcc

SRC = main.c insert.c validation.c add.c sub.c mul.c div.c compare.c

OBJ = $(SRC:.c=.o)

apc: $(OBJ)
	$(CC) -o apc $(OBJ)

clean:
	rm -f *.o apc