#include <stdio.h>
#include <stdlib.h>

typedef struct header {
  unsigned int size;
  struct header *next;
} header_t;

static header_t base;
static header_t *freep = &base;
