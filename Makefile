BIN_NAME = eval_expr

CC ?= gcc

SRC = evalexpr.c evalexpr2.c

OBJS = evalexpr.o evalexpr2.o

HEADER = header.h

CFLAGS = -Wall -Wextra -Werror

all: fclean evalexpr.o evalexpr clean

evalexpr.o: 
	$(CC) $(CFLAGS) -c $(SRC) $(HEADER)
evalexpr:
	$(CC) -o $(BIN_NAME) $(OBJS)

clean:
	rm -rf evalexpr.o evalexpr2.o header.h.gch

fclean:
	rm -rf $(BIN_NAME)
