#include "s21_string.h"

char* s21_strrcpy(char* dest, const char* src) {
  s21_size_t len = s21_strlen(src);
  s21_size_t i = 0;
  for (; len > 0; len--) {
    dest[i] = src[len - 1];
    i++;
  }
  dest[i] = '\0';
  return dest;
}
