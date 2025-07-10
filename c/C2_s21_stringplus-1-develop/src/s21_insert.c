#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* res = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (src_len >= start_index) {
      s21_size_t len = src_len + str_len;
      res = calloc(len + 1, sizeof(char));
      if (res != s21_NULL) {
        s21_size_t i = 0, j = 0, k = 0;

        while (i < start_index) {
          res[k++] = src[i++];
        }

        while (j < str_len) {
          res[k++] = str[j++];
        }

        while (i < src_len) {
          res[k++] = src[i++];
        }
      }
    }
  }
  return res;
}
