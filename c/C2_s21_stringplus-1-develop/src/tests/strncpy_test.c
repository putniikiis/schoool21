#include "string_test.h"
START_TEST(first_testcase) {
  char dest1[10] = "Hello";
  char dest2[10] = "Hello";
  const char src[] = "";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(second_testcase) {
  char dest1[10] = "";
  char dest2[10] = "";
  const char src[] = "Goo";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(third_testcase) {
  char dest1[10] = "\n\t\a";
  char dest2[10] = "\n\t\a";
  const char src[] = "\n\t\a";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(fourth_testcase) {
  char dest1[10] = "";
  char dest2[10] = "";
  const char src[] = "szcv";
  s21_strncpy(dest1, src, 2);
  strncpy(dest2, src, 2);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(fifth_testcase) {
  char dest1[10] = "\0";
  char dest2[10] = "\0";
  const char src[] = "\0";
  s21_strncpy(dest1, src, 1);
  strncpy(dest2, src, 1);
  ck_assert_str_eq(dest1, dest2);
}

START_TEST(sixth_testcase) {
  char dest1[10] = "TESTING00";
  char dest2[10] = "TESTING00";
  const char src[] = "TESTING00";
  s21_strncpy(dest1, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);
}

Suite *suite_strncpy() {
  Suite *s;
  TCase *tc;

  s = suite_create("suite_strncpy");
  tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  suite_add_tcase(s, tc);

  return s;
}
