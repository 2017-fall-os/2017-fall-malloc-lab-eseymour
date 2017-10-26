#include <stdlib.h>
#include <string.h>

#include "myAllocator.h"

#define align4(x) ((x+3) & ~3)
#define align8(x) ((x+7) & ~7)

AllocMethod_t allocMethod = NEXT_FIT;

/* first, the standard malloc functions */
void *malloc(size_t NBYTES) {
  void *APTR;
  switch (allocMethod) {
    case FIRST_FIT:
      APTR = firstFitAllocRegion(NBYTES);
      break;
    case NEXT_FIT:
      APTR = nextFitAllocRegion(NBYTES);
      break;
    case BEST_FIT:
      APTR = bestFitAllocRegion(NBYTES);
  }
  return APTR;
}

void *realloc(void *APTR, size_t NBYTES) {
  return resizeRegion(APTR, NBYTES);
}

void free(void *APTR) {
  freeRegion(APTR);
}

void *memalign(size_t ALIGN, size_t NBYTES) { /* ignore ALIGN -- hack -- */
  void *p = malloc(NBYTES+ALIGN);
  return p;
}

size_t malloc_usable_size(void *APTR) {
  return computeUsableSpace(regionToPrefix(APTR));
}

/* some systems require that malloc replacements provide these... */
void *calloc(size_t N, size_t S) {
  size_t req;
  void *p;
  if (S <= 4)
    req = N * align4(S);
  else
    req = N * align8(S);
  p = malloc(req);
  memset(p, 0, req);
  return p;
}

char *strdup(const char *s) {
  void *p = malloc(strlen(s) + 1);
  strcpy(p, s);
  return p;
}
