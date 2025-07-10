#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s_str = (unsigned char *)str;
  unsigned char ch_c = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    s_str[i] = ch_c;
  }
  return str;
}
