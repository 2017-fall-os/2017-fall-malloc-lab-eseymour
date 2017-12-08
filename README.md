# OS `malloc`

## Directory contents

myAllocator.c: a first/next/best-fit allocator
myAllocator.h: its header file

myAllocatorTest1.c: a test program for my first-fit allocator
myAllocatorTest2.c: a test program for my next-fit allocator
myAllocatorTest3.c: a test program for my best-fit allocator

malloc.c: a replacement for malloc that uses my allocator
test1.c: a test program that uses this replacement malloc using my first-fit allocator
test2.c: a test program that uses this replacement malloc using my next-fit allocator
test3.c: a test program that uses this replacement malloc using my best-fit allocator

Makefile: a fairly portable "makefile", targets "all" and "clean"

## Building

To compile:

```bash
$ make
```

To clean:

```bash
$ make clean
```

## Running

Each test program generates a respective executable without the .c extension

```bash
# Test programs
$ ./myAllocatorTest1
$ ./myAllocatorTest2
$ ./myAllocatorTest3
$ ./test1
$ ./test2
$ ./test3
```

## cygwin info

Check added to test for cygwin.

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!
