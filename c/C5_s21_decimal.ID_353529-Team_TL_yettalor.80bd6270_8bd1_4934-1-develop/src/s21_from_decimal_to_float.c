#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code = 1;
  *dst = 0;
  double tmp = 0;

  int sign = s21_get_bit(src, 127);
  int scale = s21_get_scale(src);

  for (int i = 0; i < 96; i++) {
    if (s21_get_bit(src, i) != 0) {
      tmp += pow(2.0, i);
    }
  }

  tmp /= pow(10.0, scale);
  tmp = sign == 1 ? -tmp : tmp;

  *dst = tmp;
  code = 0;

  return code;
}