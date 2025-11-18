#include "s21_decimal.h"

int s21_compare(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;
  int should_continue = 1;
  int sign1 = s21_get_bit(value_1, 127);
  int sign2 = s21_get_bit(value_2, 127);

  s21_big_decimal big_value_1 = s21_to_big_decimal(value_1);
  s21_big_decimal big_value_2 = s21_to_big_decimal(value_2);
  s21_normalize_mantissa_big(&big_value_1, &big_value_2);

  if (sign1 && !sign2) {
    code = -1;
  } else if (!sign1 && sign2) {
    code = 1;
  } else {
    for (int i = 6; i >= 0 && should_continue; i--) {
      if ((big_value_1.bits[i] > big_value_2.bits[i] && !sign1) ||
          (big_value_1.bits[i] < big_value_2.bits[i] && sign1)) {
        code = 1;
        should_continue = 0;
      } else if ((big_value_1.bits[i] < big_value_2.bits[i] && !sign1) ||
                 (big_value_1.bits[i] > big_value_2.bits[i] && sign1)) {
        code = -1;
        should_continue = 0;
      }
    }
  }

  return code;
}