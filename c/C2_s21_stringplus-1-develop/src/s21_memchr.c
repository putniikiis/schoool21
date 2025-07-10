#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *p = (unsigned char *)str;
  unsigned char uc = (unsigned char)c;
  void *res = s21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (p[i] == uc) {
      res = &p[i];
      break;
    }
  }
  return res;
}
