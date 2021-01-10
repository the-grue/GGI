#  Makefile for GGI

CC = gcc
AS = gcc
#  Note CFLAGS are currently set for MMURTL
#  Most likely you will want to change for your OS
CFLAGS = -std=gnu99 -O0 -nostdlib -m32 -march=i386 -ffreestanding -fno-common -fno-pie -fno-pic -fno-asynchronous-unwind-tables -I../include -DMMURTL

SRC = grapherrormsg.c graphresult.c getarccoords.c getaspectratio.c \
      getbkcolor.c getcolor.c setbkcolor.c setcolor.c initgraph.c \
      getgraphmode.c getdrivername.c getmaxcolor.c getmaxmode.c \
      getmaxx.c getmaxy.c getmodename.c getpalette.c getmoderange.c \
      getpalettesize.c closegraph.c putpixel.c line.c getpixel.c \
      getx.c gety.c linerel.c lineto.c moverel.c moveto.c rectangle.c \
      circle.c imagesize.c getimage.c putimage.c

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
	rm -f $(OBJ) $(OBJ2) libGGI.a ../lib/libGGI.a

all: libGGI.a

install: all
	cp -p libGGI.a ../lib
