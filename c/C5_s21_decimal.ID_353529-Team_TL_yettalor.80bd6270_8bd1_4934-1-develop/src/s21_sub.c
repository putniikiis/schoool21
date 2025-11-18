#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;
  for (int i = 0; i < 4; i++) result->bits[i] = 0;

  s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
  s21_normalize_mantissa_big(&big_value_1, &big_value_2);
  s21_big_decimal big_result = {0};

  int sign1 = s21_get_bit(value_1, 127);
  int sign2 = s21_get_bit(value_2, 127);
  int scale = s21_get_big_scale(big_value_1);
  int final_sign = 0;

  if (sign1 && sign2) {
    if (s21_is_greater_or_equal_big(big_value_2, big_value_1)) {
      s21_big_minus(big_value_2, big_value_1, &big_result);
    } else {
      s21_big_minus(big_value_1, big_value_2, &big_result);
      final_sign = 1;
    }
  } else if (!sign1 && sign2) {
    s21_big_plus(big_value_1, big_value_2, &big_result);
  } else if (sign1 && !sign2) {
    s21_big_plus(big_value_1, big_value_2, &big_result);
    final_sign = 1;
  } else {
    if (s21_is_greater_or_equal_big(big_value_2, big_value_1)) {
      s21_big_minus(big_value_2, big_value_1, &big_result);
      final_sign = 1;
    } else {
      s21_big_minus(big_value_1, big_value_2, &big_result);
    }
  }

  if (overflow_check_big(big_result)) {
    if (s21_fixOverflow(&big_result, &scale)) {
      code = sign1 == sign2 ? 1 : 2;
    } else {
      s21_to_decimal(big_result, result);
      s21_set_bit(result, 127, final_sign);
      s21_set_scale(result, scale);
    }
  } else {
    s21_to_decimal(big_result, result);
    s21_set_bit(result, 127, final_sign);
    s21_set_scale(result, scale);
  }
  return code;
}

int s21_minus(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int borrow = 0;
  for (int i = 0; i < 3; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int diff = bit1 ^ bit2 ^ borrow;
      borrow = ((~bit1) & bit2) | ((bit2 ^ borrow) & (~bit1));
      result->bits[i] |= (diff << b);
    }
  }

  return borrow;
}

int s21_big_minus(s21_big_decimal value_1, s21_big_decimal value_2,
                  s21_big_decimal *result) {
  int borrow = 0;
  for (int i = 0; i < 7; i++) {
    result->bits[i] = 0;
    for (int b = 0; b < 32; b++) {
      unsigned int bit1 = (value_1.bits[i] >> b) & 1;
      unsigned int bit2 = (value_2.bits[i] >> b) & 1;

      unsigned int diff = bit1 ^ bit2 ^ borrow;
      result->bits[i] |= (diff << b);

      borrow = (bit2 + borrow > bit1);
    }
  }
  return borrow;
}
