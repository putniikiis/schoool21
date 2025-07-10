#include "string_test.h"

START_TEST(first_test) {
  char str[] = "Hello, world";
  char c = 'o';
  s21_size_t n = 13;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(second_test) {
  const char* str = "Hello, World";
  char c = 'c';
  s21_size_t n = 13;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(third_test) {
  const char* str = "\0\0\0";
  char c = '\0';
  s21_size_t n = 4;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(fourth_test) {
  const char* str = "";
  char c = 'e';
  s21_size_t n = 1;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(fifth_test) {
  const char* str = "Hello";
  char c = '\0';
  s21_size_t n = 6;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(sixth_test) {
  const char* str = "Hello, world";
  char c = 'o';
  s21_size_t n = 0;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(seventh_test) {
  const char* str = "Hello, World";
  char c = 'l';
  s21_size_t n = 13;
  char* got = s21_memchr(str, c, n);
  char* expected = memchr(str, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(eighth_test) {
  const int arr[] = {1, 2, 3, 4, 5};
  int c = 3;
  s21_size_t n = 5 * sizeof(int);
  char* got = s21_memchr(arr, c, n);
  char* expected = memchr(arr, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

START_TEST(ninth_test) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  float c = 3.3;
  s21_size_t n = 5 * sizeof(float);
  char* got = s21_memchr(arr, c, n);
  char* expected = memchr(arr, c, n);

  ck_assert_pstr_eq(got, expected);
}
END_TEST

Suite* suite_memchr(void) {
  Suite* s = suite_create("suite_memchr");
  TCase* tc = tcase_create("memchr_tc");
  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fifth_test);
  tcase_add_test(tc, sixth_test);
  tcase_add_test(tc, seventh_test);
  tcase_add_test(tc, eighth_test);
  tcase_add_test(tc, ninth_test);
  suite_add_tcase(s, tc);

  return s;
}
