#include "utils.h"

void get_length(const char** format, flags* flag) {
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    flag->length = **format;
    (*format)++;
  }
}

void process_format_num(const char** format, int* num, va_list va) {
  if (**format == '*') {
    *num = va_arg(va, int);
    (*format)++;
  } else {
    *num = 0;
    while ((**format) && is_digit((**format))) {
      *num = *num * 10 + (**format) - '0';
      (*format)++;
    }
  }
}

int is_flag(const char format) { return is_in(format, "-+# 0"); }

int is_int_spec(const char c) { return is_in(c, "ido"); }

int is_float_spec(const char c) { return is_in(c, "eEfgG"); }

int is_in(char c, const char* symbols) {
  int flag = 0;
  while (!flag && *symbols != '\0') {
    if (c == *symbols) {
      flag = 1;
    }
    symbols++;
  }
  return flag;
}

int is_digit(const char c) { return c >= '0' && c <= '9'; }
