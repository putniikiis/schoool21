#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = 0;

  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
  int sign = src < 0 ? 1 : 0;
  src = sign == 0 ? src : -src;

  dst->bits[0] = src;
  dst->bits[3] = sign << 31;

  code = 0;

  return code;
}