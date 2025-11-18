#include "test.h"

START_TEST(s21_to_float_1) {
  s21_decimal inp = {{4, 0, 0, 0x00000000}};
  float out;
  float res = 4.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_2) {
  s21_decimal inp = {{432152, 320, 344, 65536}};
  float out;
  float res = 634567996273047572277.6;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_3) {
  s21_decimal inp = {{432152, 320, 133, 655360}};
  float out;
  float res = 2.453417E+11;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_to_float_4) {
  s21_decimal inp = {{3, 3, 3, INT_MIN}};
  float out;
  float res = -55340232234013556739.0;
  int error = s21_from_decimal_to_float(inp, &out);
  ck_assert_float_eq(out, res);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_decimal_to_float(void) {
  Suite *s = suite_create("test_from_decimal_to_float_suite");
  TCase *tc = tcase_create("s21_to_float_tc");

  tcase_add_test(tc, s21_to_float_1);
  tcase_add_test(tc, s21_to_float_2);
  tcase_add_test(tc, s21_to_float_3);
  tcase_add_test(tc, s21_to_float_4);

  suite_add_tcase(s, tc);
  return s;
}