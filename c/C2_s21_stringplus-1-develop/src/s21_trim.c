#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;

  if (src != s21_NULL) {
    const char *start = src;
    const char *end = src + s21_strlen(src) - 1;

    if (trim_chars == s21_NULL || *trim_chars == '\0') {
      trim_chars = " \t\n";
    }

    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, *end)) {
      end--;
    }

    s21_size_t len = end - start + 1;

    res = (char *)malloc(len + 1);
    if (res != s21_NULL) {
      s21_strncpy(res, start, len);
      res[len] = '\0';
    }
  }

  return res;
}
