#include "s21_string.h"

void* s21_to_lower(const char* str) {
  char* result = s21_NULL;

  if (str != s21_NULL) {
    int length = s21_strlen(str);
    result = (char*)calloc(length + 1, sizeof(char));
    if (result != NULL) {
      for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          result[i] = str[i] + ('a' - 'A');
        } else {
          result[i] = str[i];
        }
      }
    }
  }

  return (void*)result;
}
