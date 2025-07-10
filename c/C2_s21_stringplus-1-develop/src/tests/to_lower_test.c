#include "string_test.h"

START_TEST(first_testcase) {
  char* str = "BASE";
  char* res = s21_to_lower(str);
  char* expected = "base";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(second_testcase) {
  char* str = "BaSe 123!@#";
  char* res = s21_to_lower(str);
  char* expected = "base 123!@#";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(third_testcase) {
  char* str = "\t\n\t\0";
  char* res = s21_to_lower(str);
  char* expected = "\t\n\t\0";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(fourth_testcase) {
  char* str = "";
  char* res = s21_to_lower(str);
  char* expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(fifth_testcase) {
  char* str = "\0\0\0";
  char* res = s21_to_lower(str);
  char* expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(sixth_testcase) {
  char* str = "\0BASE";
  char* res = s21_to_lower(str);
  char* expected = "";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(seventh_testcase) {
  char* str = s21_NULL;
  char* res = s21_to_lower(str);
  ck_assert_ptr_null(res);
}
END_TEST

Suite* suite_to_lower() {
  Suite* s;
  TCase* tc;

  s = suite_create("suite_to_lower");
  tc = tcase_create("tc_to_lower");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  tcase_add_test(tc, seventh_testcase);

  suite_add_tcase(s, tc);

  return s;
}
