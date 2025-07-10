#include "s21_string.h"

void* s21_to_upper(const char* str) {
  char* res = s21_NULL;

  if (str != s21_NULL) {
    int len = s21_strlen(str);
    res = (char*)calloc(len + 1, sizeof(char));

    if (res != NULL) {
      for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          res[i] = str[i] - ('a' - 'A');
        } else {
          res[i] = str[i];
        }
      }
    }
  }

  return (void*)res;
}
