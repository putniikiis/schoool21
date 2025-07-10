#include "string_test.h"

START_TEST(first_testcase) {
  const char* src = "tes one";
  const char* str = "ting";
  int start_index = 3;
  char* res = s21_insert(src, str, start_index);
  char* expected = "testing one";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(second_testcase) {
  const char* src = s21_NULL;
  const char* str = "ting";
  int start_index = 3;
  char* res = s21_insert(src, str, start_index);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(third_testcase) {
  const char* src = "tes one";
  const char* str = s21_NULL;
  int start_index = 3;
  char* res = s21_insert(src, str, start_index);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(fourth_testcase) {
  const char* src = "tes one";
  const char* str = "";
  int start_index = 3;
  char* res = s21_insert(src, str, start_index);
  char* expected = "tes one";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(fifth_testcase) {
  const char* src = "tes";
  const char* str = "ting";
  int start_index = 3;
  char* res = s21_insert(src, str, start_index);
  char* expected = "testing";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(sixth_testcase) {
  const char* src = "tes";
  const char* str = "ting";
  int start_index = 32;
  char* res = s21_insert(src, str, start_index);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(seventh_testcase) {
  const char* src = "";
  const char* str = "test";
  int start_index = 0;
  char* res = s21_insert(src, str, start_index);
  char* expected = "test";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

START_TEST(eighth_testcase) {
  const char* src = "";
  const char* str = "test";
  int start_index = 5;
  char* res = s21_insert(src, str, start_index);
  ck_assert_ptr_null(res);
}
END_TEST

START_TEST(ninth_testcase) {
  const char* src = "testing";
  const char* str = "\0";
  int start_index = 5;
  char* res = s21_insert(src, str, start_index);
  char* expected = "testing";
  ck_assert_str_eq(res, expected);
  free(res);
}
END_TEST

Suite* suite_insert() {
  Suite* s;
  TCase* tc;

  s = suite_create("suite_insert");
  tc = tcase_create("tc_insert");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  tcase_add_test(tc, sixth_testcase);
  tcase_add_test(tc, seventh_testcase);
  tcase_add_test(tc, eighth_testcase);
  tcase_add_test(tc, ninth_testcase);
  suite_add_tcase(s, tc);

  return s;
}
