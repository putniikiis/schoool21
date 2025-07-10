#ifndef COMMON_H
#define COMMON_H
#include <stdarg.h>

typedef struct {
  short minus, plus, space, hash, zero, prec_flag, width_flag, asterisk;
  char length, spec;
  int precision, width;
} flags;

void get_length(const char**, flags*);
void process_format_num(const char**, int*, va_list);

int is_flag(const char);
int is_int_spec(const char);
int is_float_spec(const char);
int is_in(char c, const char*);
int is_digit(const char);

#endif