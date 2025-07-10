#include "string_test.h"

START_TEST(tc_first) {
  char str1[] = "Exactly 1it is must1 work1ing ";
  char str2[] = "Exactly 1it is must1 work1ing ";
  const char delim[] = " 1";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
  while (got_res && right_res) {
    got_res = s21_strtok(NULL, delim);
    right_res = strtok(NULL, delim);
    if (got_res || right_res) {
      ck_assert_str_eq(got_res, right_res);
    } else {
      ck_assert_ptr_null(got_res);
      ck_assert_ptr_null(right_res);
    }
  }
}
END_TEST;

START_TEST(tc_second) {
  char str1[] = "123 456 789";
  char str2[] = "123 456 789";
  const char delim[] = "123 456 789";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_ptr_null(got_res);
  ck_assert_ptr_null(right_res);
}
END_TEST;

START_TEST(tc_third) {
  char str1[] = "Let's go to watch 10 hours video for C";
  char str2[] = "Let's go to watch 10 hours video for C";
  const char delim[] = "'go 0";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
  while (got_res && right_res) {
    got_res = s21_strtok(NULL, delim);
    right_res = strtok(NULL, delim);
    if (got_res || right_res) {
      ck_assert_str_eq(got_res, right_res);
    } else {
      ck_assert_ptr_null(got_res);
      ck_assert_ptr_null(right_res);
    }
  }
}
END_TEST;

START_TEST(tc_fourth) {
  char str1[] = "flawless victory___###&&&***";
  char str2[] = "flawless victory___###&&&***";
  const char delim[] = "_#&*";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
  while (got_res && right_res) {
    got_res = s21_strtok(NULL, delim);
    right_res = strtok(NULL, delim);
    ck_assert_ptr_null(got_res);
    ck_assert_ptr_null(right_res);
  }
}
END_TEST;

START_TEST(tc_fifth) {
  char str1[] = "1 - . 2 - , 3 - ! 4 - ?";
  char str2[] = "1 - . 2 - , 3 - ! 4 - ?";
  const char delim[] = "- .,!?";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
  while (got_res && right_res) {
    got_res = s21_strtok(NULL, delim);
    right_res = strtok(NULL, delim);
    if (got_res || right_res) {
      ck_assert_str_eq(got_res, right_res);
    } else {
      ck_assert_ptr_null(got_res);
      ck_assert_ptr_null(right_res);
    }
  }
}
END_TEST;

START_TEST(tc_six) {
  char str1[] = "\0\0\0\0\0";
  char str2[] = "\0\0\0\0\0";
  const char delim[] = "\0";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);

  ck_assert_ptr_null(got_res);
  ck_assert_ptr_null(right_res);
}
END_TEST;

START_TEST(tc_seventh) {
  char str1[] = "FAANG";
  char str2[] = "FAANG";
  const char delim[] = "Y";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
}
END_TEST;

START_TEST(tc_eighth) {
  char str1[] = "";
  char str2[] = "";
  const char delim[] = "Y";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_ptr_null(got_res);
  ck_assert_ptr_null(right_res);
}
END_TEST;

START_TEST(tc_ninth) {
  char str1[] = "FAANG";
  char str2[] = "FAANG";
  const char delim[] = "";
  char* got_res = s21_strtok(str1, delim);
  char* right_res = strtok(str2, delim);
  ck_assert_str_eq(got_res, right_res);
  while (got_res && right_res) {
    got_res = s21_strtok(NULL, delim);
    right_res = strtok(NULL, delim);
    ck_assert_ptr_null(got_res);
    ck_assert_ptr_null(right_res);
  }
}
END_TEST;

Suite* suite_strtok() {
  Suite* s;
  TCase* tc;

  s = suite_create("suite_strtok");
  tc = tcase_create("strtok_tc");
  tcase_add_test(tc, tc_first);
  tcase_add_test(tc, tc_second);
  tcase_add_test(tc, tc_third);
  tcase_add_test(tc, tc_fourth);
  tcase_add_test(tc, tc_fifth);
  tcase_add_test(tc, tc_six);
  tcase_add_test(tc, tc_seventh);
  tcase_add_test(tc, tc_eighth);
  tcase_add_test(tc, tc_ninth);

  suite_add_tcase(s, tc);

  return s;
}
