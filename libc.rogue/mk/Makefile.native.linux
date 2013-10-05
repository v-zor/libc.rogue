##

CC=gcc
CFLAGS=-I../include -I../include/sys -I../include/sys/arch/powerpc/include \
	-Wno-attributes

OBJS = memset.o \
	malloc.o 


all:
	$(CC) $(CFLAGS) -c memcpy.c -o memcpy.o
	$(CC) $(CFLAGS) -c memset.c -o memset.o
	$(CC) $(CFLAGS) -c malloc.c -o malloc.o

	ar rcu libc.rogue.a *.o
	ranlib libc.rogue.a

clean:
	rm -f *.o libc.rogue.a
