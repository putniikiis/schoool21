#include "test.h"

int main(void) {
  int number_failed;

  Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13;
  SRunner *sr;

  s1 = test_add();
  s2 = test_sub();
  s3 = test_mul();
  s4 = test_div();
  s5 = test_from_decimal_to_float();
  s6 = test_from_decimal_to_int();
  s7 = test_from_int_to_decimal();
  s8 = test_from_float_to_decimal();
  s9 = test_floor();
  s10 = test_round();
  s11 = test_truncate();
  s12 = test_negate();
  s13 = test_compare();

  sr = srunner_create(s1);
  srunner_add_suite(sr, s2);
  srunner_add_suite(sr, s3);
  srunner_add_suite(sr, s4);
  srunner_add_suite(sr, s5);
  srunner_add_suite(sr, s6);
  srunner_add_suite(sr, s7);
  srunner_add_suite(sr, s8);
  srunner_add_suite(sr, s9);
  srunner_add_suite(sr, s10);
  srunner_add_suite(sr, s11);
  srunner_add_suite(sr, s12);
  srunner_add_suite(sr, s13);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
