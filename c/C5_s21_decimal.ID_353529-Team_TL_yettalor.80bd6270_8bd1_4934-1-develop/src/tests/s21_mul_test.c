#include "test.h"

START_TEST(s21_mul_1) {
  int true_res = 1;
  s21_decimal val1 = {{3661687825U, 3548589221U, 1484172995, 1048576}};
  s21_decimal val2 = {{739397062, 184307300, 2689959896U, 262144}};
  s21_decimal output;
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_2) {
  int true_res = 0;
  s21_decimal val1 = {{4238762691U, 3671025269U, 1569026641, 2148139008U}};
  s21_decimal val2 = {{1385753655, 1868041255, 3252235690U, 2149122048U}};
  s21_decimal output;
  s21_decimal result = {{1189335618, 183158651, 941308655, 393216}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_3) {
  int true_res = 2;
  s21_decimal val1 = {{352428650, 1409216065, 2233978886U, 196608}};
  s21_decimal val2 = {{1207544536, 1235392391, 1673987602, 2148007936U}};
  s21_decimal output;
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_4) {
  int true_res = 0;
  s21_decimal val1 = {{189070322, 361703882, 136336248, 2149253120U}};
  s21_decimal val2 = {{2992116040U, 278003652, 2291766132U, 262144}};
  s21_decimal output;
  s21_decimal result = {{965378582, 3516624292U, 576369986, 2147680256U}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_5) {
  int true_res = 0;
  s21_decimal val1 = {{1282924988, 3192268870U, 2879138566U, 2147942400U}};
  s21_decimal val2 = {{119053939, 3867311634U, 2868763161U, 1572864}};
  s21_decimal output;
  s21_decimal result = {{3920050555U, 216164041, 1523621123, 2147614720U}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_mul_6) {
  int true_res = 0;
  s21_decimal val1 = {{100, 0, 0, 0}};
  s21_decimal val2 = {{10, 0, 0, 0}};
  s21_decimal output;
  s21_decimal result = {{1000, 0, 0, 0}};
  int s21_res = s21_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("s21_mul_suite");
  TCase *tc = tcase_create("s21_mul_tc");

  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);
  tcase_add_test(tc, s21_mul_3);
  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  suite_add_tcase(s, tc);
  return s;
}