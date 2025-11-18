#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  for (int i = 0; i < 4; i++) result->bits[i] = 0;
  unsigned sign1 = s21_get_bit(value_1, 127);
  unsigned sign2 = s21_get_bit(value_2, 127);
  int code = 0;

  if (!s21_is_zero_decimal(value_1) && !s21_is_zero_decimal(value_2)) {
    int scale = s21_get_scale(value_1) + s21_get_scale(value_2);
    s21_big_decimal big_val_1 = s21_to_big_decimal(value_1);
    s21_big_decimal big_val_2 = s21_to_big_decimal(value_2);
    s21_big_decimal big_res = {0};

    s21_big_mul(big_val_1, big_val_2, &big_res);

    if (overflow_check_big(big_res)) {
      if (s21_fixOverflow(&big_res, &scale)) {
        code = sign1 == sign2 ? 1 : 2;
      } else {
        s21_to_decimal(big_res, result);
        s21_set_result_sign_and_scale(result, sign1, sign2, scale);
      }
    } else {
      s21_to_decimal(big_res, result);
      s21_set_result_sign_and_scale(result, sign1, sign2, scale);
    }
  }

  return code;
}

int s21_big_mul(s21_big_decimal big_val_1, s21_big_decimal big_val_2,
                s21_big_decimal* big_res) {
  int overflow = 0;
  for (int i = 0; i < 8; i++) {
    for (int b = 0; b < 32; b++) {
      unsigned int bit2 = (big_val_2.bits[i] >> b) & 1;

      if (bit2 == 1) {
        if (s21_big_plus(big_val_1, *big_res, big_res) != 0) {
          overflow = 1;
        }
      }

      s21_shift_left_big(&big_val_1, 1);
    }
  }
  return overflow;
}
