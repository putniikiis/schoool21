#include "string_test.h"

START_TEST(first_testcase) {
  char src[6] = "world";
  char res[15] = "Hello ";
  char expected[15] = "Hello ";
  s21_size_t n = 6;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 13);
}

START_TEST(second_testcase) {
  char src[] = "";
  char res[15] = "Hello ";
  char expected[15] = "Hello ";
  s21_size_t n = 6;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 13);
}

START_TEST(third_testcase) {
  char src[] = "world";
  char res[] = "Hello ";
  char expected[] = "Hello ";
  s21_size_t n = 0;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 7);
}

START_TEST(fourth_testcase) {
  char src[] = "everyone";
  char res[15] = "Hello ";
  char expected[15] = "Hello ";
  s21_size_t n = 5;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 12);
}

START_TEST(fifth_testcase) {
  char src[] = "\0";
  char res[10] = "Hello ";
  char expected[10] = "Hello ";
  s21_size_t n = 10;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 7);
}

START_TEST(sixth_testcase) {
  char dest[15] = "Hello ";
  s21_strncat(dest, dest, 6);

  ck_assert_str_eq(dest, "Hello Hello ");
}

START_TEST(seventh_testcase) {
  char src[] = "every\0 one ";
  char res[15] = "Hello ";
  char expected[15] = "Hello ";
  s21_size_t n = 5;
  s21_strncat(res, src, n);
  strncat(expected, src, n);

  ck_assert_mem_eq(res, expected, 12);
}

Suite *suite_strncat(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("strncat_tc");

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
