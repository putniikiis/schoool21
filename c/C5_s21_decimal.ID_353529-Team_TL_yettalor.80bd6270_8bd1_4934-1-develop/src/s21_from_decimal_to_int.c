#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0;
  *dst = 0;
  int sign = s21_get_bit(src, 127);

  s21_truncate(src, &src);

  if ((src.bits[1] != 0 || src.bits[2] != 0) ||
      (sign == 0 && src.bits[0] > INT_MAX) ||
      (sign == 1 && src.bits[0] > INT_MAX + 1u)) {
    code = 1;
  } else {
    *dst = src.bits[0];
    *dst = (sign == 1) ? -(*dst) : *dst;
  }

  return code;
}