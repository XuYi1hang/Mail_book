CC=gcc
BIN=mail_book
OBJ=main.o phone_book.o tools.o
STD=-std=gnu99
FLAG=-Wall -Werror
LD=-lm
INCLUDE=-I.

all:$(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(LD)

%.o:%.c
	$(CC) $(STD) $(FLAG) -c $< -o $@

clean:
	rm $(BIN) $(OBJ)
