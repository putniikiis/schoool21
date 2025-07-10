#include "string_test.h"

START_TEST(first_testcase) {
  char dest[100];
  char src[] = "Correct copy";
  char* res = s21_strrcpy(dest, src);
  char* expected = "ypoc tcerroC";
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(second_testcase) {
  char dest[100];
  char src[] = "";
  char* res = s21_strrcpy(dest, src);
  char* expected = "";
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(third_testcase) {
  char dest[100] = "string";
  char src[] = "Correct copy";
  char* res = s21_strrcpy(dest, src);
  char* expected = "ypoc tcerroC";
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(fourth_testcase) {
  char dest[100];
  char src[] = "\0";
  char* res = s21_strrcpy(dest, src);
  char* expected = "\0";
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(fifth_testcase) {
  char dest[100];
  char src[] = "\n\t\0sdf";
  char* res = s21_strrcpy(dest, src);
  char* expected = "\t\n";
  ck_assert_str_eq(res, expected);
}
END_TEST

Suite* suite_strrcpy() {
  Suite* s;
  TCase* tc;

  s = suite_create("suite_strrcpy");
  tc = tcase_create("strrcpy_tc");

  tcase_add_test(tc, first_testcase);
  tcase_add_test(tc, second_testcase);
  tcase_add_test(tc, third_testcase);
  tcase_add_test(tc, fourth_testcase);
  tcase_add_test(tc, fifth_testcase);
  suite_add_tcase(s, tc);

  return s;
}
