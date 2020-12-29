#  Makefile for GGI

CC = gcc
AS = gcc
CFLAGS = -std=gnu99 -O0 -nostdlib -m32 -march=i386 -ffreestanding -fno-common -fno-pie -fno-pic -fno-asynchronous-unwind-tables -I../include

SRC =

SRC2 =

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.s=.o)

libGGI.a: $(OBJ) $(OBJ2)
	@echo "[Linking GGI]"
	@ar rcs $@ $^

.c.o:
	@echo "[Compiling]" $<
	@$(CC) -c $(CFLAGS) $< -o $@

.s.o:
	@echo "[Assembling]" $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(OBJ2) libGGI.a

all: libGGI.a
