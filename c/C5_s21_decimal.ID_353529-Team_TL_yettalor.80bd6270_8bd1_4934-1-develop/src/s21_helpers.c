#include "s21_decimal.h"

int s21_get_bit(s21_decimal value, int position) {
  int bit;
  if (position >= 0 && position <= 127) {
    int index = position / 32;
    int bit_position = position % 32;
    bit = (value.bits[index] >> bit_position) & 1;
  }
  return bit;
}

void s21_set_bit(s21_decimal* value, int position, int bit_value) {
  if (position >= 0 && position <= 127) {
    int index = position / 32;
    int bit_position = position % 32;

    if (bit_value) {
      value->bits[index] |= (1 << bit_position);
    } else {
      value->bits[index] &= ~(1 << bit_position);
    }
  }
}

int s21_get_scale(s21_decimal value) {
  int scale = (value.bits[3] >> 16) & 0xFF;
  return scale;
}

void s21_set_scale(s21_decimal* value, int scale) {
  if (scale >= 0 && scale <= 28) {
    value->bits[3] = value->bits[3] & 0b10000000000000000000000000000000;
    value->bits[3] |= (scale << 16);
  }
}

void s21_set_result_sign_and_scale(s21_decimal* result, int sign1, int sign2,
                                   int scale) {
  int final_sign = (sign1 == sign2) ? 0 : 1;
  s21_set_bit(result, 127, final_sign);
  s21_set_scale(result, scale);
}

int s21_shift_left(s21_decimal* value, int shift) {
  int bit_carry = 0;

  for (int i = 0; i < 3; i++) {
    int new_bit_carry = value->bits[i] >> (32 - shift);
    value->bits[i] <<= shift;
    value->bits[i] |= bit_carry;
    bit_carry = new_bit_carry;
  }

  return bit_carry ? 1 : 0;
}

void s21_to_decimal(s21_big_decimal big_value, s21_decimal* value) {
  for (int i = 0; i < 3; i++) {
    value->bits[i] = big_value.bits[i];
  }
}

int s21_is_zero_decimal(s21_decimal value) {
  int code = 1;

  for (int i = 0; i < 3 && code; i++) {
    if (value.bits[i] != 0) code = 0;
  }

  return code;
}

void s21_mul_ten(s21_decimal* value) {
  s21_decimal result = {0};
  s21_decimal value2 = *value;

  s21_shift_left(value, 2);
  s21_plus(*value, value2, &result);
  s21_shift_left(&result, 1);

  *value = result;
}

void s21_divide_ten(s21_decimal* value) {
  unsigned long long carry = 0;
  for (int i = 2; i >= 0; --i) {
    unsigned long long temp = (carry << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    carry = temp % 10;
  }
}

void s21_big_rounding(s21_big_decimal* value) {
  s21_big_decimal remainder = {0};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};

  s21_big_decimal tmp = *value;
  s21_divide_ten_big(value);
  int is_odd = (value->bits[0] & 1);
  s21_mul_ten_big(value);
  s21_big_minus(tmp, *value, &remainder);
  s21_divide_ten_big(value);

  if (remainder.bits[0] > 5 || (remainder.bits[0] == 5 && is_odd)) {
    s21_big_plus(*value, one, value);
  }
}
