##

CC=powerpc64-ps3-elf-gcc
CFLAGS=-I../libc.rogue/include -I../libc.rogue/include/sys -I../libc.rogue/include/sys/arch/powerpc/include \
	-Wno-attributes

OBJS = form.o \
	main.o \
	routines.o \
	opcodes.o \
	operators.o


all:
	$(CC) $(CFLAGS) -c form.c -o form.o
	$(CC) $(CFLAGS) -c opcodes.c -o opcodes.o
	$(CC) $(CFLAGS) -c operators.c -o operators.o
	$(CC) $(CFLAGS) -c routines.c -o routines.o
	$(CC) $(CFLAGS) -c vm.c -o vm.o
	$(CC) $(CFLAGS) -c main.c -o main.o

	$(CC) $(CFLAGS) -c _vm.s -o _vm.o

clean:
	rm -f *.o
