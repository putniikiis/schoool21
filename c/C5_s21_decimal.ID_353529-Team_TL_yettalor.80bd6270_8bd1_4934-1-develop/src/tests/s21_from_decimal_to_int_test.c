#include "test.h"

START_TEST(s21_from_decimal_to_int_1) {
  int true_res = 1;
  s21_decimal val1 = {{336139824, 2147037051, 1049562280, 2148007936}};
  int result = 0;
  int output;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
  int true_res = 0;
  s21_decimal val1 = {{3800457492U, 746078660, 44358857, 2149187584U}};
  int result = -8;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
  int true_res = 0;
  s21_decimal val1 = {{4146582168U, 737655971, 3179105752U, 1507328}};
  int result = 586441;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
  int true_res = 0;
  s21_decimal val1 = {{1989396232, 480664185, 3293331971U, 2148990976U}};
  int result = -607512;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
  int true_res = 1;
  s21_decimal val1 = {{1395180557, 3885759711U, 2862126795U, 393216}};
  int result = 0;
  int output = 0;
  int s21_res = s21_from_decimal_to_int(val1, &output);
  ck_assert_int_eq(result, output);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_from_decimal_to_int(void) {
  Suite *s = suite_create("test_from_decimal_to_int_suite");
  TCase *tc = tcase_create("s21_from_decimal_to_int_tc");

  tcase_add_test(tc, s21_from_decimal_to_int_1);
  tcase_add_test(tc, s21_from_decimal_to_int_2);
  tcase_add_test(tc, s21_from_decimal_to_int_3);
  tcase_add_test(tc, s21_from_decimal_to_int_4);
  tcase_add_test(tc, s21_from_decimal_to_int_5);

  suite_add_tcase(s, tc);
  return s;
}