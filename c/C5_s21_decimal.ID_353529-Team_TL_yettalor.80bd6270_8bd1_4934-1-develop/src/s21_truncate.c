#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  int scale = s21_get_scale(value);
  while (scale > 0) {
    s21_divide_ten(&value);
    scale--;
  }
  *result = value;
  s21_set_scale(result, scale);
  return 0;
}