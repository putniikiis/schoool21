#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const unsigned char *s_str1 = (const unsigned char *)str1;
  const unsigned char *s_str2 = (const unsigned char *)str2;

  int result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (s_str1[i] != s_str2[i] || s_str1[i] == '\0' || s_str2[i] == '\0') {
      result = s_str1[i] - s_str2[i];
      break;
    }
  }

  return result;
}
