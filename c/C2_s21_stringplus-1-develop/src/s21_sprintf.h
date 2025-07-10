#include "s21_string.h"
#include "utils.h"

#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#define BUFF_SIZE 512

int s21_sprintf(char* str, const char* format, ...);
void form_str(char*, flags*, va_list);

void fun_flags(const char**, flags*);
void get_precision(const char**, flags*, va_list);
void get_width(const char**, flags*, va_list);

void process_int(char*, flags*, va_list);
void process_hex(char*, flags*, va_list);
void process_pointer(char*, va_list);
void process_unsigned(char*, flags*, va_list);
void process_float(char*, flags*, va_list);
void process_string(char*, flags*, va_list);
void postprocess(char*, char*, flags*);
void add_zeros(char* str, int num, int* idx);
void int_to_str(char*, flags*, int64_t, int);
int uint_to_str(char*, uint64_t, int);

void format_f(char*, flags*, long double);
void format_g(char*, flags*, long double);
void format_e(char*, flags*, long double);

void to_upper(char* s);

void process_mantissa(char*, flags*, long double, s21_size_t);
s21_size_t double_int_to_str(char* buffer, long double val);

#endif