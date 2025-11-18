#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>

#define DEC_MAX 7.9228162514264337593543950335e+28

typedef struct s21_decimal {
  unsigned int bits[4];
} s21_decimal;

typedef struct s21_big_decimal {
  unsigned int bits[8];
} s21_big_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_compare(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

int s21_plus(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_minus(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_get_bit(s21_decimal value, int position);
void s21_set_bit(s21_decimal* value, int position, int bit_value);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal* value, int scale);
void s21_set_result_sign_and_scale(s21_decimal* result, int sign1, int sign2,
                                   int scale);
int s21_shift_left(s21_decimal* value, int shift);
void s21_to_decimal(s21_big_decimal big_value, s21_decimal* value);
int s21_is_zero_decimal(s21_decimal value);
void s21_mul_ten(s21_decimal* value);
void s21_divide_ten(s21_decimal* value);
int s21_fixOverflow(s21_big_decimal* value, int* scale);
void s21_big_rounding(s21_big_decimal* value);
int s21_is_last_overflow(s21_big_decimal value);

int s21_get_bit_big(s21_big_decimal value, int bit_index);
void s21_set_bit_big(s21_big_decimal* value, int position, int bit_value);
int s21_get_big_scale(s21_big_decimal value);
void s21_set_big_scale(s21_big_decimal* value, int scale);
int s21_get_highest_big_bit(s21_big_decimal value);
int s21_shift_left_big(s21_big_decimal* value, int shift);
int s21_shift_right_big(s21_big_decimal* value, int shift);
s21_big_decimal s21_to_big_decimal(s21_decimal value);
int s21_is_zero_big_decimal(s21_big_decimal value);
int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2);
int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2);
int overflow_check_big(s21_big_decimal value);
void s21_mul_ten_big(s21_big_decimal* value);
void s21_divide_ten_big(s21_big_decimal* value);
void s21_normalize_mantissa_big(s21_big_decimal* value,
                                s21_big_decimal* value2);

int s21_big_mul(s21_big_decimal big_val_1, s21_big_decimal big_val_2,
                s21_big_decimal* big_res);
int s21_big_div(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                s21_big_decimal* result, int* scale);
int s21_big_plus(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result);
int s21_big_minus(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal* result);
#endif
