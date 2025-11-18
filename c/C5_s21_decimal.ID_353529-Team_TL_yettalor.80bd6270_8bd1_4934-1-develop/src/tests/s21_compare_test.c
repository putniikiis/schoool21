#include "test.h"

START_TEST(s21_is_less_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_less(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_less(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 0;
  int got = s21_is_less(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 1;
  int got = s21_is_less(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 0;
  int got = s21_is_less(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_or_equal_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_less_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_or_equal_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_less_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_or_equal_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 0;
  int got = s21_is_less_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_or_equal_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 1;
  int got = s21_is_less_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_less_or_equal_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 1;
  int got = s21_is_less_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_greater(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_greater(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 1;
  int got = s21_is_greater(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 0;
  int got = s21_is_greater(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 0;
  int got = s21_is_greater(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_or_equal_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_or_equal_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_or_equal_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_or_equal_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 0;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_greater_or_equal_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 1;
  int got = s21_is_greater_or_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_equal_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_equal_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 0;
  int got = s21_is_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_equal_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 0;
  int got = s21_is_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_equal_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 0;
  int got = s21_is_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_equal_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 1;
  int got = s21_is_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_not_equal_1) {
  s21_decimal num1 = {{1, 2, 3, 655360}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
  s21_decimal num1 = {{1, 2, 3, -2146828288}};
  s21_decimal num2 = {{3, 2, 1, -2146828288}};
  int expected = 1;
  int got = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
  s21_decimal num1 = {{1, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, -2146959360}};
  int expected = 1;
  int got = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_not_equal_4) {
  s21_decimal num1 = {{10, 2, 3, -2146566144}};
  s21_decimal num2 = {{3, 2, 1, 524288}};
  int expected = 1;
  int got = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_is_not_equal_5) {
  s21_decimal num1 = {{1, 2, 3, 917504}};
  s21_decimal num2 = {{1, 2, 3, 917504}};
  int expected = 0;
  int got = s21_is_not_equal(num1, num2);
  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *test_compare(void) {
  Suite *s = suite_create("suite_compare");
  TCase *tc = tcase_create("comp_tc");

  tcase_add_test(tc, s21_is_less_1);
  tcase_add_test(tc, s21_is_less_2);
  tcase_add_test(tc, s21_is_less_3);
  tcase_add_test(tc, s21_is_less_4);
  tcase_add_test(tc, s21_is_less_5);
  tcase_add_test(tc, s21_is_less_or_equal_1);
  tcase_add_test(tc, s21_is_less_or_equal_2);
  tcase_add_test(tc, s21_is_less_or_equal_3);
  tcase_add_test(tc, s21_is_less_or_equal_4);
  tcase_add_test(tc, s21_is_less_or_equal_5);
  tcase_add_test(tc, s21_is_greater_1);
  tcase_add_test(tc, s21_is_greater_2);
  tcase_add_test(tc, s21_is_greater_3);
  tcase_add_test(tc, s21_is_greater_4);
  tcase_add_test(tc, s21_is_greater_5);
  tcase_add_test(tc, s21_is_greater_or_equal_1);
  tcase_add_test(tc, s21_is_greater_or_equal_2);
  tcase_add_test(tc, s21_is_greater_or_equal_3);
  tcase_add_test(tc, s21_is_greater_or_equal_4);
  tcase_add_test(tc, s21_is_greater_or_equal_5);
  tcase_add_test(tc, s21_is_equal_1);
  tcase_add_test(tc, s21_is_equal_2);
  tcase_add_test(tc, s21_is_equal_3);
  tcase_add_test(tc, s21_is_equal_4);
  tcase_add_test(tc, s21_is_equal_5);
  tcase_add_test(tc, s21_is_not_equal_1);
  tcase_add_test(tc, s21_is_not_equal_2);
  tcase_add_test(tc, s21_is_not_equal_3);
  tcase_add_test(tc, s21_is_not_equal_4);
  tcase_add_test(tc, s21_is_not_equal_5);

  suite_add_tcase(s, tc);

  return s;
}