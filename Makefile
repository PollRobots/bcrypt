CC = gcc
CFLAGS = -W -Wall -O2 -fomit-frame-pointer -funroll-loops

all: bcrypt.a

test: bcrypt.o bcrypt_test.c
	$(CC) $(CFLAGS) -c bcrypt_test.c
	$(CC) -o bcrypt_test bcrypt.o bcrypt_test.o

bcrypt.a: bcrypt.o
	ar r bcrypt.a bcrypt.o

clean:
	rm -f *.o bcrypt_test bcrypt.a
