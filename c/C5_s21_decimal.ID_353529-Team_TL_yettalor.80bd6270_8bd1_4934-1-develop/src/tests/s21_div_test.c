#include "test.h"

START_TEST(s21_div_1) {
  s21_decimal num1 = {{1, 1, 1, 655360}};
  s21_decimal num2 = {{1, 1, 1, 655360}};
  s21_decimal expected = {{1, 0, 0, 0}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_2) {
  s21_decimal num1 = {{1, 1, 1, 655360}};
  s21_decimal num2 = {{1, 1, 1, 983040}};
  s21_decimal expected = {{100000, 0, 0, 0}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal num1 = {{1, 1, 1, 655360}};
  s21_decimal num2 = {{1, 10, 1, -2146500608}};
  s21_decimal expected = {{1019311944, 458670364, 542101085, -2145976320}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_4) {
  s21_decimal num1 = {{1, 1, 1, 983040}};
  s21_decimal num2 = {{1, 1, 1, -2146500608}};
  s21_decimal expected = {{1, 0, 0, -2147483648}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal num1 = {{4, 0, 0, 0}};
  s21_decimal num2 = {{3, 0, 0, 0}};
  s21_decimal expected = {{357913941, 1390150444, 722801448, 1835008}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_6) {
  s21_decimal num1 = {{3, 0, 0, 0}};
  s21_decimal num2 = {{4, 0, 0, 0}};
  s21_decimal expected = {{75, 0, 0, 131072}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(s21_div_7) {
  s21_decimal num1 = {{3, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(s21_div_8) {
  s21_decimal num1 = {{0, 0, 0, 0}};
  s21_decimal num2 = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal output;
  int status = s21_div(num1, num2, &output);
  for (int i = 0; i < 4; i++)
    ck_assert_int_eq(expected.bits[i], output.bits[i]);
  ck_assert_int_eq(status, 3);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("suite_div");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  suite_add_tcase(s, tc);

  return s;
}