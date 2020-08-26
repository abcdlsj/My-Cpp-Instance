#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *myMemcpy(void *dst, const void *src, size_t size) {
  const char *psrc = (const char *)src;
  char *pdst = (char *)dst;
  if (NULL == psrc || NULL == pdst || size <= 0) return NULL;
  if (src < dst) {
    psrc += size - 1;
    pdst += size - 1;
    while (size--) {
      *pdst-- = *psrc--;
    }
  } else {
    while (size--) {
      *pdst++ = *psrc++;
    }
  }
  return dst;
}

int main() {
  const char src[50] = "this is memcpy()";
  char dest[50];

  const char src2[50] = "this is mymemcpy()";
  char dest2[50];

  memcpy(dest, src, strlen(src) + 1);
  printf("dest = %s\n", dest);

  myMemcpy(dest2, src2, strlen(src2) + 1);
  printf("dest = %s\n", dest2);

  return (0);
}
