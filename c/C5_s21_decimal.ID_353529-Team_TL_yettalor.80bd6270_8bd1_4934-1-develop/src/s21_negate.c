#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 4; i++) {
    result->bits[i] = value.bits[i];
  }

  int sign = s21_get_bit(value, 127);

  if (sign == 1) {
    s21_set_bit(result, 127, 0);
  } else {
    s21_set_bit(result, 127, 1);
  }

  return 0;
}