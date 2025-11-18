#include "s21_decimal.h"

int s21_get_bit_big(s21_big_decimal value, int bit_index) {
  int result = 0;

  if (bit_index >= 0 && bit_index <= 255) {
    int array_index = bit_index / 32;
    int bit_position = bit_index % 32;
    result = (value.bits[array_index] >> bit_position) & 1;
  }

  return result;
}

void s21_set_bit_big(s21_big_decimal* value, int position, int bit_value) {
  if (position >= 0 && position <= 255) {
    int index = position / 32;
    int bit_position = position % 32;

    if (bit_value) {
      value->bits[index] |= (1 << bit_position);
    } else {
      value->bits[index] &= ~(1 << bit_position);
    }
  }
}

int s21_get_big_scale(s21_big_decimal value) {
  int scale = (value.bits[7] >> 16) & 0xFF;
  return scale;
}

void s21_set_big_scale(s21_big_decimal* value, int scale) {
  if (scale >= 0 && scale <= 28) {
    value->bits[7] = value->bits[7] & 0b10000000000000000000000000000000;
    value->bits[7] |= (scale << 16);
  }
}

int s21_get_highest_big_bit(s21_big_decimal value) {
  int idx_bit = -1;

  for (int i = 224; i >= 0 && idx_bit == -1; i--) {
    int index = i / 32;
    int bit_position = i % 32;

    if ((value.bits[index] >> bit_position) & 1) {
      idx_bit = i;
    }
  }

  return idx_bit;
}

int s21_shift_left_big(s21_big_decimal* value, int shift) {
  int bit_carry = 0;
  if (shift != 0) {
    for (int i = 0; i < 7; i++) {
      int new_bit_carry = value->bits[i] >> (32 - shift);
      value->bits[i] <<= shift;
      value->bits[i] |= bit_carry;
      bit_carry = new_bit_carry;
    }
  }
  return bit_carry ? 1 : 0;
}

int s21_shift_right_big(s21_big_decimal* value, int shift) {
  int bit_carry = 0;

  for (int i = 6; i >= 0; i--) {
    int new_bit_carry = value->bits[i] << (32 - shift);
    value->bits[i] >>= shift;
    value->bits[i] |= bit_carry;
    bit_carry = new_bit_carry;
  }

  return bit_carry ? 1 : 0;
}

s21_big_decimal s21_to_big_decimal(s21_decimal value) {
  s21_big_decimal big_value = {0};

  for (int i = 0; i < 3; i++) {
    big_value.bits[i] = value.bits[i];
  }

  big_value.bits[7] = value.bits[3];
  return big_value;
}

int s21_is_zero_big_decimal(s21_big_decimal value) {
  int code = 1;

  for (int i = 0; i < 7 && code; i++) {
    if (value.bits[i] != 0) code = 0;
  }

  return code;
}

int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  int result = 1;
  int should_continue = 1;

  for (int i = 6; i >= 0 && should_continue; i--) {
    if (value_1.bits[i] > value_2.bits[i]) {
      result = 1;
      should_continue = 0;
    } else if (value_1.bits[i] < value_2.bits[i]) {
      result = 0;
      should_continue = 0;
    }
  }

  return result;
}

int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2) {
  int result = 0;

  for (int i = 6; i >= 0 && result == 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      result = 1;
    } else if (value_1.bits[i] > value_2.bits[i]) {
      result = 0;
    }
  }

  return result;
}
int s21_fixOverflow(s21_big_decimal* value, int* scale) {
  int overflow = 0;
  while ((*scale > 0 && (overflow = overflow_check_big(*value)) != 0) ||
         *scale > 28) {
    if (*scale == 1 || s21_is_last_overflow(*value)) {
      s21_big_rounding(value);
    } else {
      s21_divide_ten_big(value);
    }
    (*scale)--;
  }

  overflow = overflow_check_big(*value);

  return overflow;
}

int s21_is_last_overflow(s21_big_decimal value) {
  int res = 0;

  if (value.bits[4] == 0 && value.bits[5] == 0 && value.bits[6] == 0 &&
      value.bits[3] < 10) {
    res = 1;
  }

  return res;
}

void s21_mul_ten_big(s21_big_decimal* value) {
  s21_big_decimal result = {0};
  s21_big_decimal value2 = *value;

  s21_shift_left_big(value, 2);
  s21_big_plus(*value, value2, &result);
  s21_shift_left_big(&result, 1);

  *value = result;
}

void s21_divide_ten_big(s21_big_decimal* value) {
  unsigned long long carry = 0;
  for (int i = 6; i >= 0; --i) {
    unsigned long long temp = (carry << 32) + value->bits[i];
    value->bits[i] = (unsigned int)(temp / 10);
    carry = temp % 10;
  }
}

int overflow_check_big(s21_big_decimal value) {
  int overflow = 0;
  for (int i = 96; i < 224 && !overflow; i++) {
    if (s21_get_bit_big(value, i) == 1) {
      overflow = 1;
    }
  }

  return overflow;
}

void s21_normalize_mantissa_big(s21_big_decimal* value,
                                s21_big_decimal* value2) {
  int scale1 = s21_get_big_scale(*value);
  int scale2 = s21_get_big_scale(*value2);

  if (scale1 != scale2) {
    if (scale1 < scale2) {
      s21_normalize_mantissa_big(value2, value);
    } else {
      int diff = scale1 - scale2;

      for (; diff > 0; diff--) {
        s21_mul_ten_big(value2);
        scale2++;
      }

      s21_set_big_scale(value, scale1);
      s21_set_big_scale(value2, scale1);
    }
  }
}
