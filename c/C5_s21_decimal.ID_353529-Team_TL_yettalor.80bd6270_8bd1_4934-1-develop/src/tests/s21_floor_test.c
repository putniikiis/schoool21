#include "test.h"

START_TEST(s21_floor_1) {
  int true_res = 0;
  s21_decimal val1 = {{1900836102, 3149800568U, 4121353038U, 2148532224U}};
  s21_decimal result = {{462360372, 0x000006EA, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_floor_2) {
  int true_res = 0;
  s21_decimal val1 = {{2603221583U, 3437586824U, 2835584762U, 2148794368U}};
  s21_decimal result = {{523073065, 0x00000000, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_floor_3) {
  int true_res = 0;
  s21_decimal val1 = {{3203002091U, 1104962998, 2404417579U, 2148139008U}};
  s21_decimal result = {{3795659903U, 0x3D8D974E, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_floor_4) {
  int true_res = 0;
  s21_decimal val1 = {{3490959618U, 1100246717, 931221762, 2148925440U}};
  s21_decimal result = {{1717801, 0x00000000, 0x00000000, 2147483648U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_floor_5) {
  int true_res = 0;
  s21_decimal val1 = {{272593817, 2457732400U, 2207089905U, 1769472}};
  s21_decimal result = {{40, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_floor_6) {
  int true_res = 0;
  s21_decimal val1 = {{0, 0, 0, 1769472}};
  s21_decimal result = {{0, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_floor(val1, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("test_floor_suite");
  TCase *tc = tcase_create("s21_floor_tc");

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  tcase_add_test(tc, s21_floor_6);

  suite_add_tcase(s, tc);
  return s;
}