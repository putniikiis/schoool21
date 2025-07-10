#include "string_test.h"
START_TEST(first_test) {
  const char* str = "Hello, World";
  char c = 'r';
  char* got = s21_strrchr(str, c);
  char* expected = strrchr(str, c);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(second_test) {
  const char* str = "testing";
  char c = 'r';
  char* got = s21_strrchr(str, c);
  char* expected = strrchr(str, c);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(third_test) {
  const char* str = "\0\0\0";
  char c = '\0';
  char* got = s21_strrchr(str, c);
  char* expected = strrchr(str, c);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(fourth_test) {
  const char* str = "";
  char c = 'e';
  char* got = s21_strrchr(str, c);
  char* expected = strrchr(str, c);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(fifth_test) {
  const char* str = "Hello";
  char c = '\0';
  char* got = s21_strrchr(str, c);
  char* expected = strrchr(str, c);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

Suite* suite_strrchr(void) {
  Suite* s = suite_create("suite_strrchr");
  TCase* tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fifth_test);
  suite_add_tcase(s, tc);
  return s;
}
