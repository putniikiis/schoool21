#include "test.h"

START_TEST(s21_truncate_1) {
  int true_res = 0;
  s21_decimal val1 = {{1249969685, 3390647538U, 2662707735U, 2148794368U}};
  s21_decimal result = {{491182881, 0x00000000, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_2) {
  int true_res = 0;
  s21_decimal val1 = {{2374016245U, 50508052, 3968951055U, 2148139008U}};
  s21_decimal result = {{300735900, 1704651498, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_3) {
  int true_res = 0;
  s21_decimal val1 = {{823186291, 4200134272U, 3565270959U, 196608}};
  s21_decimal result = {{584938738, 4123073771U, 3565270, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_4) {
  int true_res = 0;
  s21_decimal val1 = {{929425793, 3651333253U, 2292993710U, 2149122048U}};
  s21_decimal result = {{4229, 0x00000000, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_truncate_5) {
  int true_res = 0;
  s21_decimal val1 = {{3207100350U, 1993341063, 1110179151, 2147680256U}};
  s21_decimal result = {{3263087278U, 650533402, 1110179, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_truncate(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_truncate(void) {
  Suite *s = suite_create("test_truncate_suite");
  TCase *tc = tcase_create("s21_truncate_tc");

  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_4);
  tcase_add_test(tc, s21_truncate_5);

  suite_add_tcase(s, tc);
  return s;
}