#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *current_char;
  char *str_part = s21_NULL;
  int run = 1;
  int run_while = 1;
  if (str != s21_NULL) current_char = str;
  if (current_char == s21_NULL || *current_char == '\0') {
    run = 0;
  }
  if (run) {
    while (*current_char != '\0' && run_while) {
      int is_delim = 0;
      for (const char *d = delim; *d != '\0'; d++) {
        if (*current_char == *d) {
          is_delim = 1;
          break;
        }
      }
      if (!is_delim) {
        run_while = 0;
      } else {
        current_char++;
      }
    }
    if (*current_char != '\0') {
      str_part = current_char;
      run_while = 1;
      while (*current_char != '\0' && run_while) {
        int is_delim = 0;
        for (const char *d = delim; *d != '\0'; d++) {
          if (*current_char == *d) {
            is_delim = 1;
            break;
          }
        }
        if (is_delim) {
          run_while = 0;
        } else {
          current_char++;
        }
      }
      if (*current_char != '\0') {
        *current_char = '\0';
        current_char++;
      }
    }
  }
  return str_part;
}
