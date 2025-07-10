#include "string_test.h"

START_TEST(first_test) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t n = 5;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(second_test) {
  char str1[] = "Hello";
  char str2[] = "Hello World";
  s21_size_t n = 5;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(third_test) {
  char str1[] = "abcde";
  char str2[] = "abcfd";
  s21_size_t n = 5;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(fourth_test) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n = 0;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(fifth_test) {
  char str1[] = "abc";
  char str2[] = "abd";
  s21_size_t n = 3;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got < 0, expected < 0);
}
END_TEST

START_TEST(sixth_test) {
  char str1[] = "abd";
  char str2[] = "abc";
  s21_size_t n = 3;
  int got = s21_memcmp(str1, str2, n);
  int expected = memcmp(str1, str2, n);

  ck_assert_int_eq(got, expected);
}
END_TEST

Suite* suite_memcmp() {
  Suite* s = suite_create("suite_memcmp");
  TCase* tc = tcase_create("memcmp_tc");
  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fifth_test);
  tcase_add_test(tc, sixth_test);
  suite_add_tcase(s, tc);

  return s;
}