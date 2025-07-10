#include "string_test.h"

START_TEST(first_tc) {
  const char src[] = "Golang Software Engineer";
  char dest1[25];
  char dest2[25];
  s21_size_t n = 25;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(second_tc) {
  const int src[] = {1, 4, 3, 4, 5};
  int dest1[24];
  int dest2[24];
  s21_size_t n = 20;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(third_tc) {
  const char src[] = "Software";
  char dest1[25];
  char dest2[25];
  s21_size_t n = 0;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(fourth_tc) {
  const double src[] = {1.2, 2.4, 3.14, 4, 5.0};
  double dest1[24];
  double dest2[24];
  s21_size_t n = 24;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(fifth_tc) {
  const char src[] = "MMM";
  char dest1[2];
  char dest2[2];
  s21_size_t n = 2;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(sixth_tc) {
  const char src[] = "\0\0\0\t\t\t\n\n\n";
  char dest1[10];
  char dest2[10];
  s21_size_t n = 10;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(seventh_tc) {
  const char src[] = "MMM";
  char dest1[5];
  char dest2[5];
  s21_size_t n = 4;
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

START_TEST(eighth_tc) {
  const int src[] = {1, 2, 3};
  double dest1[3];
  double dest2[3];
  s21_size_t n = sizeof(src);
  s21_memcpy(dest1, src, n);
  memcpy(dest2, src, n);
  ck_assert_mem_eq(dest1, dest2, n);
}
END_TEST

Suite *suite_memcpy() {
  Suite *s;
  TCase *tc;

  s = suite_create("suite_memcpy");
  tc = tcase_create("tc_memcpy");

  tcase_add_test(tc, first_tc);
  tcase_add_test(tc, second_tc);
  tcase_add_test(tc, third_tc);
  tcase_add_test(tc, fourth_tc);
  tcase_add_test(tc, fifth_tc);
  tcase_add_test(tc, sixth_tc);
  tcase_add_test(tc, seventh_tc);
  tcase_add_test(tc, eighth_tc);

  suite_add_tcase(s, tc);

  return s;
}
