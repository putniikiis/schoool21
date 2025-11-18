#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  int code = 0;
  if (s21_is_zero_decimal(value_2)) {
    code = 3;
  } else {
    int sign1 = s21_get_bit(value_1, 127);
    int sign2 = s21_get_bit(value_2, 127);

    s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
    s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
    s21_normalize_mantissa_big(&big_value_1, &big_value_2);
    s21_big_decimal big_result = {0};
    int scale = 0;

    s21_big_div(big_value_1, big_value_2, &big_result, &scale);

    if (overflow_check_big(big_result)) {
      if (s21_fixOverflow(&big_result, &scale)) {
        code = sign1 == sign2 ? 1 : 2;
      } else {
        s21_to_decimal(big_result, result);
        s21_set_result_sign_and_scale(result, sign1, sign2, scale);
      }
    } else {
      s21_to_decimal(big_result, result);
      s21_set_result_sign_and_scale(result, sign1, sign2, scale);
    }
  }
  return code;
}

int s21_big_div(s21_big_decimal big_value_1, s21_big_decimal big_value_2,
                s21_big_decimal* result, int* scale) {
  s21_big_decimal quotient = {0};
  s21_big_decimal remainder = {0};

  while (s21_is_less_big(big_value_1, big_value_2) && *scale < 28) {
    (*scale)++;
    s21_mul_ten_big(&big_value_1);
    s21_mul_ten_big(result);
  }

  if (s21_is_greater_or_equal_big(big_value_1, big_value_2)) {
    int shift = s21_get_highest_big_bit(big_value_1) -
                s21_get_highest_big_bit(big_value_2);
    s21_big_decimal shifted_divisor = big_value_2;
    s21_shift_left_big(&shifted_divisor, shift);

    while (shift >= 0) {
      if (s21_is_greater_or_equal_big(big_value_1, shifted_divisor)) {
        s21_big_minus(big_value_1, shifted_divisor, &remainder);
        big_value_1 = remainder;
        s21_shift_left_big(&quotient, 1);
        s21_set_bit_big(&quotient, 0, 1);
      } else {
        s21_shift_left_big(&quotient, 1);
      }

      s21_shift_right_big(&shifted_divisor, 1);
      shift--;
    }

    s21_big_plus(*result, quotient, result);

    if (!s21_is_zero_big_decimal(remainder) && *scale < 28 &&
        !overflow_check_big(*result)) {
      (*scale)++;
      s21_mul_ten_big(result);
      s21_mul_ten_big(&remainder);

      s21_big_div(remainder, big_value_2, result, scale);
    }
  }

  return 0;
}