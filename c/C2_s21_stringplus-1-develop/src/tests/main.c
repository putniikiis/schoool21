#include "string_test.h"

int main(void) {
  int number_failed;

  Suite *s1, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12, *s13,
      *s14, *s15, *s16, *s17, *s18, *s19, *s20, *s21, *s22, *s23, *s24;
  SRunner *sr;

  s1 = suite_memcpy();
  s2 = suite_strrchr();
  s3 = suite_strtok();
  s4 = suite_strpbrk();
  s5 = suite_strncpy();
  s6 = suite_strstr();
  s7 = suite_strpbrk();
  s8 = suite_strncat();
  s9 = suite_memset();
  s10 = suite_memcmp();
  s11 = suite_memchr();
  s12 = suite_strcspn();
  s13 = suite_to_lower();
  s14 = suite_insert();
  s15 = suite_to_upper();
  s16 = suite_strchr();
  s17 = suite_strlen();
  s18 = suite_strcpy();
  s19 = suite_strcspn();
  s20 = suite_sprintf();
  s21 = suite_sscanf();
  s22 = suite_trim();
  s23 = suite_strerror();
  s24 = suite_strncmp();

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
  srunner_add_suite(sr, s14);
  srunner_add_suite(sr, s15);
  srunner_add_suite(sr, s16);
  srunner_add_suite(sr, s17);
  srunner_add_suite(sr, s18);
  srunner_add_suite(sr, s19);
  srunner_add_suite(sr, s20);
  srunner_add_suite(sr, s21);
  srunner_add_suite(sr, s22);
  srunner_add_suite(sr, s23);
  srunner_add_suite(sr, s24);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
