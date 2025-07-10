#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d_dest = (unsigned char *)dest;
  unsigned char *s_src = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    *d_dest++ = *s_src++;
  }
  return dest;
}
