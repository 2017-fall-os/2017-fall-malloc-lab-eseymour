CFLAGS = -g
CC = gcc
OBJ = myAllocatorTest1  myAllocatorTest2 myAllocatorTest3 test1 test2 test3

all: $(OBJ)

myAllocatorTest1: myAllocator.o myAllocatorTest1.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTest2: myAllocator.o myAllocatorTest2.o
	$(CC) $(CFLAGS) -o $@ $^

myAllocatorTest3: myAllocator.o myAllocatorTest3.o
	$(CC) $(CFLAGS) -o $@ $^

test1: myAllocator.o malloc.o test1.o
	$(CC) $(CFLAGS) -o $@ $^

test2: myAllocator.o malloc.o test2.o
	$(CC) $(CFLAGS) -o $@ $^

test3: myAllocator.o malloc.o test3.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o $(OBJ)

