#include "string_test.h"

START_TEST(first_testcase) {
  char* got = s21_strerror(-100);
  char* expected = strerror(-100);
  ck_assert_str_eq(got, expected);
}
END_TEST

START_TEST(second_testcase) {
  for (int i = 0; i < 77; i++) {
    char* got = s21_strerror(i);
    char* expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
  for (int i = 77; i < 134; i++) {
    char* got = s21_strerror(i);
    char* expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

START_TEST(third_testcase) {
  char* got = s21_strerror(300);
  char* expected = strerror(300);
  ck_assert_str_eq(got, expected);
}
END_TEST

Suite* suite_strerror(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("suite_strerror");
  tc = tcase_create("strerror_tc");
  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  suite_add_tcase(s, tc);
  return s;
}