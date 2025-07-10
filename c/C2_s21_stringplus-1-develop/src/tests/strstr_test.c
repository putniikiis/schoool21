#include "string_test.h"
START_TEST(first_testcase) {
  const char haystack[] = "substring was found";
  const char needle[] = "was";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(second_testcase) {
  const char haystack[] = "substring was not found";
  const char needle[] = "false";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(third_testcase) {
  const char haystack[] = "";
  const char needle[] = "was";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(fourth_testcase) {
  const char haystack[] = "substring was found";
  const char needle[] = "";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(fifth_testcase) {
  const char haystack[] = "substring was found";
  const char needle[] = "\0";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(sixth_testcase) {
  const char haystack[] = "\n\n\n\t\t\t";
  const char needle[] = "\n\t";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(seventh_testcase) {
  const char haystack[] = "";
  const char needle[] = "\0";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(eigth_testcase) {
  const char haystack[] = "\0";
  const char needle[] = "\0";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

START_TEST(ninth_testcase) {
  const char* haystack = s21_NULL;
  const char* needle = "\0";
  char* res = s21_strstr(haystack, needle);
  char* expected = strstr(haystack, needle);
  ck_assert_pstr_eq(res, expected);
}
END_TEST

Suite* suite_strstr(void) {
  Suite* s = suite_create("suite_strstr");
  TCase* tc = tcase_create("strstr_tc");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  tcase_add_test(tc, seventh_testcase);
  tcase_add_test(tc, eigth_testcase);
  tcase_add_test(tc, ninth_testcase);

  suite_add_tcase(s, tc);
  return s;
}
