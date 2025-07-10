#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  if (str1 != s21_NULL || str2 != s21_NULL) {
    for (s21_size_t i = 0; i < s21_strlen(str1) && !res; i++) {
      for (s21_size_t h = 0; h < s21_strlen(str2) && !res; h++) {
        if (str1[i] == str2[h]) {
          res = (char *)(str1 + i);
        }
      }
    }
  }
  return res;
}
