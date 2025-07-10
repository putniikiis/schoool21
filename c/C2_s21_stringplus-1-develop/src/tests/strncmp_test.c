#include "string_test.h"

START_TEST(first_test) {
  s21_size_t n = 3;
  char *str1 = "Hello!";
  char *str2 = "Hello!";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq((s21_c > 0) - (s21_c < 0), (s_c > 0) - (s_c < 0));
}
END_TEST

START_TEST(second_test) {
  s21_size_t n = 3;
  char *str1 = "School 21 the best!";
  char *str2 = "Software engineer!";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq((s21_c > 0) - (s21_c < 0), (s_c > 0) - (s_c < 0));
}
END_TEST

START_TEST(third_test) {
  s21_size_t n = 3;
  char *str1 = "School 21 the best!";
  char *str2 = "Hello!";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq((s21_c > 0) - (s21_c < 0), (s_c > 0) - (s_c < 0));
}
END_TEST

START_TEST(fourth_test) {
  s21_size_t n = 0;
  char *str1 = "Hello!";
  char *str2 = "Hello!";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(fifth_test) {
  s21_size_t n = 100;
  char *str1 = "Hello!";
  char *str2 = "Hello!";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq((s21_c > 0) - (s21_c < 0), (s_c > 0) - (s_c < 0));
}
END_TEST

START_TEST(sixth_test) {
  s21_size_t n = 3;
  char *str1 = "";
  char *str2 = "";
  int s21_c = s21_strncmp(str1, str2, n);
  int s_c = strncmp(str1, str2, n);
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

Suite *suite_strncmp() {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fifth_test);
  tcase_add_test(tc, sixth_test);

  suite_add_tcase(s, tc);
  return s;
}
