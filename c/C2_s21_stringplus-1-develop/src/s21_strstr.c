#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  const char* res = s21_NULL;
  if (haystack != s21_NULL) {
    int lenHaystack = s21_strlen(haystack);
    int lenNeedle = s21_strlen(needle);
    for (int i = 0; i <= lenHaystack - lenNeedle && !res; i++) {
      int k = 0;

      while (k < lenNeedle && haystack[i + k] == needle[k]) {
        k++;
      }

      if (k == lenNeedle) {
        res = (haystack + i);
      }
    }
  }

  return (char*)res;
}
