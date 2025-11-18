#include "test.h"

START_TEST(s21_negate_1) {
  int true_res = 0;
  s21_decimal val1 = {{759814799, 3748239213U, 1727379886, 2148270080U}};
  s21_decimal result = {{759814799, 3748239213U, 1727379886, 786432}};
  s21_decimal output;
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_2) {
  int true_res = 0;
  s21_decimal val1 = {{218114824, 781153020, 920380823, 2148466688U}};
  s21_decimal result = {{218114824, 781153020, 920380823, 983040}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_3) {
  int true_res = 0;
  s21_decimal val1 = {{1075221594, 3223628885U, 2060965312, 327680}};
  s21_decimal result = {{1075221594, 3223628885U, 2060965312, 2147811328U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_4) {
  int true_res = 0;
  s21_decimal val1 = {{2199334010U, 1649779827, 1529318216, 2147942400U}};
  s21_decimal result = {{2199334010U, 1649779827, 1529318216, 458752}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_negate_5) {
  int true_res = 0;
  s21_decimal val1 = {{2091120705, 2351713895U, 2183386342U, 2148073472U}};
  s21_decimal result = {{2091120705, 2351713895U, 2183386342U, 589824}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_negate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_negate(void) {
  Suite *s = suite_create("negate_suite");
  TCase *tc = tcase_create("s21_negate_tc");

  tcase_add_test(tc, s21_negate_1);
  tcase_add_test(tc, s21_negate_2);
  tcase_add_test(tc, s21_negate_3);
  tcase_add_test(tc, s21_negate_4);
  tcase_add_test(tc, s21_negate_5);

  suite_add_tcase(s, tc);
  return s;
}
