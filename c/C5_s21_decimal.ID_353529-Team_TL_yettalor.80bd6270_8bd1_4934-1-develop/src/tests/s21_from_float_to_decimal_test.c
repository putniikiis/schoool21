#include "test.h"

START_TEST(s21_float_1) {
  float inp = 1. / 0.;
  s21_decimal out;
  int error = s21_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(s21_float_2) {
  float inp = 0.004;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000004, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_3) {
  float inp = 0.0000000000000000093929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{9392939, 0, 0, 1572864}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_4) {
  float inp = 0.00000000000000000000000000013929383838292;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{1, 0, 0, 1835008}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_5) {
  float inp = 2183182381923912939123.365656f;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{2329608192U, 1505529345, 118, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(s21_float_6) {
  float inp = 79215000000000000000000000000.365656;
  s21_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

Suite *test_from_float_to_decimal(void) {
  Suite *s = suite_create("test_from_float_to_decimal_suite");
  TCase *tc = tcase_create("s21_from_float_to_decimal_tc");

  tcase_add_test(tc, s21_float_1);
  tcase_add_test(tc, s21_float_2);
  tcase_add_test(tc, s21_float_3);
  tcase_add_test(tc, s21_float_4);
  tcase_add_test(tc, s21_float_5);
  tcase_add_test(tc, s21_float_6);

  suite_add_tcase(s, tc);
  return s;
}