#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  for (int i = 0; i < 4; i++) dst->bits[i] = 0;
  int code = 0;
  if (fabsf(src) < 1e-28 || fabsf(src) > DEC_MAX || isinf(src) || isnan(src)) {
    code = 1;
  } else if (src != 0) {
    int scale = 0;
    int sign = src < 0;
    long double s = (src > 0) ? src : -src;
    while (s < 9999999 && scale < 28) {
      s *= 10;
      ++scale;
    }
    while (s > 9999999) {
      s /= 10;
      --scale;
    }
    s = round(s);
    dst->bits[0] = (int)s;
    while (scale > 0 && dst->bits[0] % 10 == 0) {
      s21_divide_ten(dst);
      --scale;
    }
    while (scale < 0) {
      s21_mul_ten(dst);
      ++scale;
    }
    s21_set_scale(dst, scale);
    s21_set_bit(dst, 127, sign);
  }
  return code;
}