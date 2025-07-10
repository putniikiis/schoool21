#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;

  for (; *str != '\0'; str++) {
    if (*str == (char)c) {
      res = (char *)str;
    }
  }
  if (c == '\0') {
    res = (char *)str;
  }
  return res;
}
