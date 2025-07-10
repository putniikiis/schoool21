#include "string_test.h"

START_TEST(first_testcase) {
  const char str1[] = "LEGO";
  const char str2[] = "GO";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(second_testcase) {
  const char str1[] = "LEGO";
  const char str2[] = "";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(third_testcase) {
  const char str1[] = "";
  const char str2[] = "LEGO";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(fourth_testcase) {
  const char str1[] = "LEGO";
  const char str2[] = "NY";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(fifth_testcase) {
  const char str1[] = "\0Go";
  const char str2[] = "Go";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(sixth_testcase) {
  const char str1[] = "Go";
  const char str2[] = "\0Go";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

START_TEST(seventh_testcase) {
  const char str1[] = "1234";
  const char str2[] = "4321";
  s21_size_t res = s21_strcspn(str1, str2);
  s21_size_t expected = strcspn(str1, str2);
  ck_assert_int_eq(res, expected);
}
END_TEST

Suite *suite_strcspn() {
  Suite *s;
  TCase *tc;

  s = suite_create("suite_strcspn");
  tc = tcase_create("tc_strcspn");

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
