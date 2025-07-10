#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  unsigned char *s_str = (unsigned char *)str;
  unsigned char ch = (unsigned char)c;
  unsigned char *res = s21_NULL;

  while (*s_str) {
    if (*s_str == ch) {
      res = s_str;
      break;
    }
    s_str++;
  }
  if (c == '\0' && *s_str == '\0') {
    res = s_str;
  }
  return (char *)res;
}
