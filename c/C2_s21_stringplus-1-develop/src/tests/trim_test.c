#include "string_test.h"

START_TEST(first_test) {
  char str[] = "  Hello, World!  ";
  char trim_ch[] = " ";
  char expected[] = "Hello, World!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(second_test) {
  char str[] = "\n\tHello, World!\n\t";
  char trim_ch[] = "\n\t";
  char expected[] = "Hello, World!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(third_test) {
  char str[] = " \t\nHello, World! \t\n";
  char *got = s21_trim(str, s21_NULL);
  char expected[] = "Hello, World!";
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(fourth_test) {
  char str[] = "Hello, World!";
  char trim_ch[] = "abc";
  char expected[] = "Hello, World!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(fifth_test) {
  char str[] = "";
  char trim_ch[] = " ";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(sixth_test) {
  char str[] = " \t\n";
  char trim_ch[] = " \t\n";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *suite_trim() {
  Suite *s;
  TCase *tc;

  s = suite_create("suite_trim");
  tc = tcase_create("trim_tc");

  tcase_add_test(tc, first_test);
  tcase_add_test(tc, second_test);
  tcase_add_test(tc, third_test);
  tcase_add_test(tc, fourth_test);
  tcase_add_test(tc, fifth_test);
  tcase_add_test(tc, sixth_test);
  suite_add_tcase(s, tc);

  return s;
}
