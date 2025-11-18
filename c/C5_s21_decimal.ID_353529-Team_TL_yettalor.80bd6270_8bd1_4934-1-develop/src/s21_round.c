#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  int scale = s21_get_scale(value);
  int sign = s21_get_bit(value, 127);
  s21_decimal remainder = {0};
  s21_decimal one = {{1, 0, 0, 0}};
  while (scale > 0) {
    if (scale == 1) {
      s21_decimal tmp = value;
      s21_divide_ten(&value);
      s21_mul_ten(&value);
      s21_minus(tmp, value, &remainder);
      s21_divide_ten(&value);
      scale--;
    } else {
      s21_divide_ten(&value);
      scale--;
    }
  }

  if (remainder.bits[0] >= 5) {
    s21_plus(value, one, &value);
  }

  *result = value;
  s21_set_scale(result, scale);
  s21_set_bit(result, 127, sign);

  if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
    result->bits[3] = 0;
  }

  return 0;
}