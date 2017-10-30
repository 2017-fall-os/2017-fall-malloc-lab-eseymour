This directory contains:

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

To compile:
 $ make
To clean:
 $ make clean

Each test program generates a respective executable without the .c extension

Check added to test for cygwin.

The cygwin runtime uses malloc() and brk() extensively.  It is
interesting to compare the output of test1 & myAllocatorTest1.  All
those extra allocated regions are being used by cygwin's libraries!
