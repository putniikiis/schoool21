#include "string_test.h"

START_TEST(first_testcase) {
  char str1[10];
  char str2[10];
  int c = '\0';
  s21_memset(str1, c, 10);
  memset(str2, c, 10);
  ck_assert_mem_eq(str1, str2, 10);
}

START_TEST(second_testcase) {
  int str1[5];
  int str2[5];
  int c = 5;
  s21_memset(str1, c, 10);
  memset(str2, c, 10);
  ck_assert_mem_eq(str1, str2, 10);
}

START_TEST(third_testcase) {
  double str1[15];
  double str2[15];
  double c = 3.14;
  s21_memset(str1, c, sizeof(c) * 15);
  memset(str2, c, sizeof(c) * 15);
  ck_assert_mem_eq(str1, str2, 15);
}

START_TEST(fourth_testcase) {
  char str1[3];
  char str2[3];
  int c = '4';

  s21_memset(str1, c, 2);
  memset(str2, c, 2);

  ck_assert_mem_eq(str1, str2, 2);
}

START_TEST(fifth_testcase) {
  char str1[10];
  char str2[10];
  int c = '\0';
  s21_memset(str1, c, 3);
  memset(str2, c, 3);
  ck_assert_mem_eq(str1, str2, 3);
}

START_TEST(sixth_testcase) {
  char str1[] = "Singleton";
  char str2[] = "Singleton";
  int c = 'A';
  s21_memset(str1, c, 3);
  memset(str2, c, 3);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(seventh_testcase) {
  int str1[5];
  int str2[5];
  int c = -128;
  s21_memset(str1, c, 10);
  memset(str2, c, 10);
  ck_assert_mem_eq(str1, str2, 10);
}

Suite *suite_memset(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("suite_memset");
  tc = tcase_create("memset_tc");
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
