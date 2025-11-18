#include "test.h"

START_TEST(s21_round_1) {
  int true_res = 0;
  s21_decimal val1 = {{32313, 0, 0, 327680}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal output;
  int s21_res = s21_round(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_round_2) {
  int true_res = 0;
  s21_decimal val1 = {{4209543331U, 3398818196U, 1440012257, 2148401152U}};
  s21_decimal result = {{238501809, 61848, 0x00000000, 2147483648U}};
  s21_decimal output;
  int s21_res = s21_round(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_round_3) {
  int true_res = 0;
  s21_decimal val1 = {{4233387526U, 3619052544U, 3637058169U, 2148073472U}};
  s21_decimal result = {{531259834, 2736144005U, 3, 2147483648U}};
  s21_decimal output;
  int s21_res = s21_round(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_round_4) {
  int true_res = 0;
  s21_decimal val1 = {{3715884070U, 4247774062U, 2313034406U, 983040}};
  s21_decimal result = {{1748620947, 9934, 0x00000000, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_round(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_round_5) {
  int true_res = 0;
  s21_decimal val1 = {{3156255456U, 3364337277U, 2036241463, 2147549184U}};
  s21_decimal result = {{2463109194U, 1624923916, 203624146, 2147483648U}};
  s21_decimal output;
  int s21_res = s21_round(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_round(void) {
  Suite *s = suite_create("test_round_suite");
  TCase *tc = tcase_create("s21_round_tc");

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);

  suite_add_tcase(s, tc);
  return s;
}