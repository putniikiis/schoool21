#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  s21_decimal one = {{1, 0, 0, 0}};
  int scale = s21_get_scale(value);

  s21_truncate(value, result);
  int sign = s21_get_bit(value, 127);
  if (scale > 0 && sign == 1) {
    s21_sub(*result, one, result);
  }

  if (result->bits[0] == 0 && result->bits[1] == 0 && result->bits[2] == 0) {
    result->bits[3] = 0;
  }
  return 0;
}
