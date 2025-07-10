#include "s21_string.h"
#include "utils.h"

#ifndef S21_SSCANF_H
#define S21_SSCANF_H

int s21_sscanf(const char*, const char*, ...);
int parse_value(const char**, const flags*, va_list, int);
void get_width_scanf(const char**, flags*, va_list);
void check_n(const char*, va_list, int);

int parse_char(const char**, const flags*, va_list);
int parse_int(const char**, const flags*, va_list);
int parse_hex(const char**, const flags*, va_list);
int parse_octal(const char**, const flags*, va_list);
int parse_float(const char**, const flags*, va_list);
int parse_f(const char**, const flags*, va_list);
int parse_e(const char**, const flags*, va_list);
int parse_string(const char**, const flags*, va_list);
int parse_pointer(const char**, const flags*, va_list);
int parse_unsigned(const char**, const flags*, va_list);
int parse_int_i(const char**, const flags*, va_list);

long double parse_mantissa(const char**, const flags*, int*);
long double process_exp(const char**, const flags*, long double, int);

void copy_int(int64_t, va_list, const flags*);
void copy_uint(uint64_t, va_list, const flags*);
void copy_double(long double, const flags*, va_list);
void skip_spaces(const char**);
int is_space(const char);
int is_hex_digit(const char);
int is_sci_not(const char*);

#endif