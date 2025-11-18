#include "test.h"

START_TEST(s21_add_1) {
  int true_res = 1;
  s21_decimal val1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal val2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}};
  s21_decimal val3 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_2) {
  int true_res = 0;
  s21_decimal val1 = {{1307134224, 2186923947U, 2607973463U, 0x00000000}};
  s21_decimal val2 = {{3565833824U, 2872738143U, 987227108, 0x00000000}};
  s21_decimal val3 = {{578000752, 764694795, 3595200572U, 0x00000000}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_3) {
  int true_res = 0;
  s21_decimal val1 = {{1007074604, 2811093394U, 3772406541U, 1703936}};
  s21_decimal val2 = {{885504328, 1741477495, 918879916, 2148204544U}};
  s21_decimal val3 = {{3622585528U, 1741461292, 918879916, 2148204544U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_4) {
  int true_res = 0;
  s21_decimal val1 = {{2491706240U, 748419313, 2598887286U, 524288}};
  s21_decimal val2 = {{644735587, 30151762, 3160592536U, 65536}};
  s21_decimal val3 = {{51158041, 3847212109U, 3160592795U, 65536}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_5) {
  int true_res = 0;
  s21_decimal val1 = {{523843692, 4274560817U, 3633426202U, 2148859904U}};
  s21_decimal val2 = {{3290915184U, 1301506363, 3682324378U, 720896}};
  s21_decimal val3 = {{1446634491, 4035928988U, 3682324377U, 720896}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_add_6) {
  int true_res = 0;
  s21_decimal val1 = {{382, 172, 55, 0}};
  s21_decimal val2 = {{182, 160, 25, INT_MIN}};
  s21_decimal val3 = {{200, 12, 30, 0}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_add(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("s21_add_suite");
  TCase *tc = tcase_create("s21_add_tc");

  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  suite_add_tcase(s, tc);
  return s;
}