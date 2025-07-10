#include "string_test.h"

START_TEST(first_testcase) {
  const char str1[] = "Find the symbol";
  const char str2[] = "symbol";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(second_testcase) {
  const char str1[] = "";
  const char str2[] = "symbol";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(third_testcase) {
  const char str1[] = "Find the symbol";
  const char str2[] = "";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(fourth_testcase) {
  const char str1[] = "\0\0\0";
  const char str2[] = "\0";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(fifth_testcase) {
  const char str1[] = "\n\t\n\0";
  const char str2[] = "\n\t";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(sixth_testcase) {
  const char str1[] = "\0\tasd";
  const char str2[] = "\0\tasd";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(seventh_testcase) {
  const char str1[] = "Symblol wasn't found";
  const char str2[] = "x";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(eigth_testcase) {
  const char str1[] = "\0\tasd";
  const char str2[] = "asd";
  const char* res = s21_strpbrk(str1, str2);
  const char* expected = strpbrk(str1, str2);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

Suite* suite_strpbrk() {
  Suite* s;
  TCase* tc;

  s = suite_create("suite_strpbrk");
  tc = tcase_create("tc_create");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  tcase_add_test(tc, seventh_testcase);
  tcase_add_test(tc, eigth_testcase);
  suite_add_tcase(s, tc);

  return s;
}
