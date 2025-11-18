#include "test.h"

START_TEST(s21_sub_1) {
  int true_res = 0;
  s21_decimal val1 = {{2167569411U, 2853565505U, 2627849456U, 393216}};
  s21_decimal val2 = {{2420526517U, 2140622315, 1265116011, 196608}};
  s21_decimal val3 = {{352479678, 179263663, 1262488162, 2147680256U}};
  s21_decimal output = {{0x000FFFF0, 0x0FFFFF00, 0x000FF000, 0x80000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST;

START_TEST(s21_sub_2) {
  int true_res = 0;
  s21_decimal val1 = {{890373317, 1664736595, 2742755499U, 2148204544U}};
  s21_decimal val2 = {{3230206353U, 3918853780U, 4043671449U, 2147483648U}};
  s21_decimal val3 = {{189631616, 3801053329U, 4043671449U, 0x00000000}};
  s21_decimal output;
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST;

START_TEST(s21_sub_3) {
  int true_res = 0;
  s21_decimal val1 = {{900961119, 2623149003U, 2341027622U, 2148597760U}};
  s21_decimal val2 = {{2096648231, 1368807658, 3501119840U, 1179648}};
  s21_decimal result = {{251632483, 2760029769U, 2691139606U, 2148597760U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST;

START_TEST(s21_sub_4) {
  int true_res = 0;
  s21_decimal val1 = {{1950710851, 961054012, 1850572092, 2148925440U}};
  s21_decimal val2 = {{2931068089U, 1288270163, 1875632178, 262144}};
  s21_decimal result = {{2708359496U, 1288270171, 1875632178, 2147745792U}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST;

START_TEST(s21_sub_5) {
  int true_res = 0;
  s21_decimal val1 = {{589626582, 1144628373, 586197204, 524288}};
  s21_decimal val2 = {{589626582, 1144628373, 586197204, 2147745792U}};
  s21_decimal val3 = {{55821110, 4238837276U, 586255823, 262144}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}
END_TEST

START_TEST(s21_sub_6) {
  int true_res = 0;
  s21_decimal val1 = {{2082227963, 936953584, 3314816446U, 196608}};
  s21_decimal val2 = {{3412878253U, 4230776124U, 3718219732U, 851968}};
  s21_decimal val3 = {{1003048368, 3634957665U, 3314816445U, 196608}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}

START_TEST(s21_sub_7) {
  int true_res = 0;
  s21_decimal val1 = {{333, 0, 0, INT_MIN}};
  s21_decimal val2 = {{100, 0, 0, INT_MIN}};
  s21_decimal val3 = {{233, 0, 0, INT_MIN}};
  s21_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int s21_res = s21_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(s21_res, true_res);
}

Suite *test_sub(void) {
  Suite *s = suite_create("sub_test");
  TCase *tc = tcase_create("s21_sub_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_sub_1);
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
  tcase_add_test(tc, s21_sub_7);
  suite_add_tcase(s, tc);
  return s;
}