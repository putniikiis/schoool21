#include "s21_sscanf.h"

#include <math.h>

int s21_sscanf(const char* str, const char* format, ...) {
  int res = 0, cur_res = 0;
  const char* start = str;
  va_list va;
  va_start(va, format);

  if (s21_strlen(str) == 0) {
    res = -1;
    cur_res = -1;
  }

  while (*format && *str && cur_res != -1) {
    if (is_space(*format)) {
      skip_spaces(&str);
      format++;
    } else if (*format == '%') {
      format++;
      if (*format && *format != '%') {
        flags f = {0};
        get_width_scanf(&format, &f, va);
        get_length(&format, &f);
        if (*format) {
          f.spec = *format;
          cur_res = parse_value(&str, &f, va, (str - start));
          res = (cur_res != -1) ? res + cur_res : res;
          format++;
        }
      } else if (*format && *str && *format == *str) {
        format++;
        str++;
      }
    } else if (*format == *str) {
      while (*format && *str && *format == *str) {
        str++;
        format++;
      }
    } else {
      cur_res = -1;
    }
    if (*str == '\0' && cur_res == -1 && res == 0) res = -1;
  }
  check_n(format, va, (str - start));
  va_end(va);
  return res;
}

void check_n(const char* format, va_list va, int count) {
  while (*format) {
    if (*format == '%' && *(format + 1) == 'n') {
      int* val = va_arg(va, int*);
      *val = count;
    }
    format++;
  }
}

void skip_spaces(const char** str) {
  while (**str != '\0' && is_space(**str)) (*str)++;
}

int parse_value(const char** str, const flags* f, va_list va, int sym_count) {
  int res = 0;
  if (f->spec == 'c') {
    res = parse_char(str, f, va);
  } else if (f->spec == 'd') {
    res = parse_int(str, f, va);
  } else if (f->spec == 'o') {
    res = parse_octal(str, f, va);
  } else if (f->spec == 'i') {
    res = parse_int_i(str, f, va);
  } else if (f->spec == 'x' || f->spec == 'X' || f->spec == 'p') {
    res = parse_hex(str, f, va);
  } else if (is_float_spec(f->spec)) {
    res = parse_float(str, f, va);
  } else if (f->spec == 's') {
    res = parse_string(str, f, va);
  } else if (f->spec == 'u') {
    res = parse_unsigned(str, f, va);
  } else if (f->spec == 'n') {
    int* val = va_arg(va, int*);
    *val = sym_count;
  }
  return res;
}

int parse_char(const char** str, const flags* f, va_list va) {
  int res = 0;
  wchar_t c = 0;

  if (*str && **str != '\0') {
    mbtowc(NULL, NULL, 0);

    int len = mblen(*str, MB_CUR_MAX);
    if (len > 0) {
      mbtowc(&c, *str, len);
      (*str) += len;
      res = 1;
    }
  }

  if (f->asterisk == 0 && res == 1) {
    wchar_t* dest = va_arg(va, wchar_t*);
    if (dest) {
      *dest = c;
    }
  }

  return res;
}

int8_t check_width(const flags* f, int i) {
  return !f->width_flag || i < f->width;
}

uint64_t dec_to_uint(const char** str, const flags* f, int i, int* res) {
  uint64_t num = 0;
  for (; **str && check_width(f, i) && is_digit(**str); ++i) {
    num = num * 10 + ((**str) - '0');
    (*str)++;
    *res = 0;
  }
  return num;
}

uint64_t hex_to_uint(const char** str, const flags* f, int i, int* res) {
  uint64_t num = 0, digit;
  if (**str == '0') ++(*str);
  if (**str == 'x' || **str == 'X') {
    ++(*str);
    *res = 0;
  }
  for (; **str && check_width(f, i) && is_hex_digit(**str); ++i) {
    if (is_digit(**str)) {
      digit = **str - '0';
    } else if (**str >= 'A' && **str <= 'F') {
      digit = **str - 'A' + 10;
    } else if (**str >= 'a' && **str <= 'f') {
      digit = **str - 'a' + 10;
    }
    num = (num << 4) | digit;
    (*str)++;
    *res = 0;
  }
  return num;
}

uint64_t oct_to_uint(const char** str, const flags* f, int i, int* res) {
  uint64_t num = 0;
  for (; **str && check_width(f, i) && is_digit(**str) && **str < '8'; ++i) {
    num = (num << 3) | (**str - '0');
    (*str)++;
    *res = 0;
  }
  return num;
}

int parse_int(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0;
  int64_t num = 0;
  int sign = 1;
  skip_spaces(str);
  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }
  num = (int64_t)dec_to_uint(str, f, i, &res);

  if (f->asterisk == 0 && res == 0) {
    num *= sign;
    copy_int(num, va, f);
    res = 1;
  }
  return res;
}

void copy_int(int64_t num, va_list va, const flags* f) {
  if (f->length == 'h') {
    int16_t* p = va_arg(va, int16_t*);
    *p = (int16_t)num;
  } else if (f->length == 0) {
    int32_t* p = va_arg(va, int32_t*);
    *p = (int32_t)num;
  } else {
    int64_t* p = va_arg(va, int64_t*);
    *p = num;
  }
}

int parse_int_i(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  int64_t num = 0;
  skip_spaces(str);

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }
  if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
    num = (int64_t)hex_to_uint(str, f, i, &res);
  } else if (**str == '0') {
    num = (int64_t)(oct_to_uint(str, f, i, &res));
  } else {
    num = (int64_t)(dec_to_uint(str, f, i, &res));
  }

  if (f->asterisk == 0 && res == 0) {
    num *= sign;
    copy_int(num, va, f);
    res = 1;
  }

  return res;
}

int parse_hex(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  int64_t num;
  skip_spaces(str);

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }

  num = hex_to_uint(str, f, i, &res) * sign;

  if (f->asterisk == 0 && res == 0) {
    copy_uint(num, va, f);
    res = 1;
  }

  return res;
}

int parse_octal(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  int64_t num;
  skip_spaces(str);

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }

  num = oct_to_uint(str, f, i, &res) * sign;

  if (f->asterisk == 0 && res == 0) {
    copy_uint(num, va, f);
    res = 1;
  }

  return res;
}

void copy_uint(uint64_t num, va_list va, const flags* f) {
  if (f->spec == 'p' || f->length == 'l') {
    uint64_t* p = va_arg(va, uint64_t*);
    *p = num;
  } else if (f->length == 'h') {
    uint16_t* p = va_arg(va, uint16_t*);
    *p = (uint16_t)num;
  } else if (f->length == 0) {
    uint32_t* p = va_arg(va, uint32_t*);
    *p = (uint32_t)num;
  }
}

int parse_unsigned(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  int64_t num;
  skip_spaces(str);

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }
  num = dec_to_uint(str, f, i, &res) * sign;
  if (f->asterisk == 0 && res == 0) {
    copy_uint(num, va, f);
    res = 1;
  }
  return res;
}

int is_inf(const char* str) {
  char* s = s21_to_lower(str);
  int flag = s21_strncmp(s, "inf", 3) == 0 || s21_strncmp(s, "-inf", 4) == 0;
  free(s);
  return flag;
}

int is_nan(const char* str) {
  char* s = s21_to_lower(str);
  int flag = s21_strncmp(s, "nan", 3) == 0;
  free(s);
  return flag;
}

int process_inf(const char** str, const flags* f, va_list va) {
  int res = 0;
  long double num = INFINITY;
  if (**str == '-') {
    num = -INFINITY;
    (*str)++;
  }
  while (**str && !is_space(**str)) (*str)++;
  if (f->asterisk == 0) {
    copy_double(num, f, va);
    res = 1;
  }
  return res;
}

int process_nan(const char** str, const flags* f, va_list va) {
  int res = 0;
  while (**str && !is_space(**str)) (*str)++;
  if (f->asterisk == 0) {
    copy_double(NAN, f, va);
    res = 1;
  }
  return res;
}

int parse_float(const char** str, const flags* f, va_list va) {
  int res = -1;
  skip_spaces(str);
  if (is_inf(*str)) {
    res = process_inf(str, f, va);
  } else if (is_nan(*str)) {
    res = process_nan(str, f, va);
  } else if (f->spec == 'e' || f->spec == 'E' ||
             ((f->spec == 'g' || f->spec == 'G') && is_sci_not(*str))) {
    res = parse_e(str, f, va);
  } else {
    res = parse_f(str, f, va);
  }
  return res;
}

void copy_double(long double num, const flags* f, va_list va) {
  if (f->length == 'l') {
    double* val = va_arg(va, double*);
    *val = (double)num;
  } else if (f->length == 'L') {
    long double* val = va_arg(va, long double*);
    *val = num;
  } else if (f->length == 0 || f->length == 'h') {
    float* val = va_arg(va, float*);
    *val = (float)num;
  }
}

int parse_f(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  long double num = 0.0;

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }

  const char* s = *str;
  num = dec_to_uint(str, f, i, &res);
  i += (*str - s);

  if (**str == '.') {
    (*str)++;
    num += parse_mantissa(str, f, &i);
  }

  if (**str == 'e' || **str == 'E') {
    (*str)++;
    num = process_exp(str, f, num, i);
  }

  if (f->asterisk == 0 && res == 0) {
    copy_double(num * sign, f, va);
    res = 1;
  }

  return res;
}

int parse_e(const char** str, const flags* f, va_list va) {
  int res = -1, i = 0, sign = 1;
  long double num = 0;

  if (**str == '-') {
    sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }
  const char* s = *str;
  num = dec_to_uint(str, f, i, &res);
  i = i + (*str - s);

  if (**str == '.') {
    (*str)++;
    num += parse_mantissa(str, f, &i);
  }
  if (**str == 'e' || **str == 'E') {
    (*str)++;
    ++i;
    num = process_exp(str, f, num, i);
  }

  if (f->asterisk == 0 && res == 0) {
    copy_double(num * sign, f, va);
    res = 1;
  }

  return res;
}

long double process_exp(const char** str, const flags* f, long double num,
                        int i) {
  int exp_sign = 1;
  if (**str == '-') {
    exp_sign = -1;
    (*str)++;
    ++i;
  } else if (**str == '+') {
    (*str)++;
    ++i;
  }
  int exp = 0;
  for (; check_width(f, i) && **str && is_digit(**str); ++i) {
    exp = exp * 10 + (**str - '0');
    (*str)++;
  }
  exp *= exp_sign;
  if (exp < 0) {
    while (exp != 0) {
      num /= 10;
      ++exp;
    }
  } else {
    while (exp != 0) {
      num *= 10;
      --exp;
    }
  }
  return num;
}

long double parse_mantissa(const char** str, const flags* f, int* i) {
  long double num = 0.0;
  long double exp = 10;
  for (; **str && check_width(f, *i) && is_digit(**str); ++(*i)) {
    num += ((**str) - '0') / exp;
    (*str)++;
    exp *= 10;
  }
  return num;
}

int parse_string(const char** str, const flags* f, va_list va) {
  int res = 0;
  skip_spaces(str);

  if (**str == '\0') {
    return 0;
  }

  char tmp[BUFF_SIZE] = {'\0'};
  int i = 0;

  while (check_width(f, i) && **str && !is_space(**str)) {
    tmp[i] = **str;
    (*str)++;
    i++;
    res = 1;
  }
  tmp[i] = '\0';

  if (res == 1 && f->asterisk == 0) {
    void* dest = va_arg(va, void*);

    if (f->length == 'l') {
      wchar_t* ws = (wchar_t*)dest;
      if (ws) {
        size_t conv_res = mbstowcs(ws, tmp, BUFF_SIZE);
        if (conv_res == (size_t)-1) {
          return 0;
        }
      }
    } else {
      char* s = (char*)dest;
      if (s) {
        s21_strcpy(s, tmp);
      }
    }
    return 1;
  }

  return f->asterisk ? 0 : res;
}

void get_width_scanf(const char** format, flags* flag, va_list va) {
  if (**format == '*') {
    flag->asterisk = 1;
    (*format)++;
  } else if (is_digit(**format)) {
    process_format_num(format, &flag->width, va);
    flag->width_flag = 1;
  }
}

int is_hex_digit(const char c) {
  return is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

int is_space(const char c) { return c == ' ' || c == '\n' || c == '\t'; }

int is_sci_not(const char* s) {
  int f = 0;
  while (*s && !is_space(*s) && !f) {
    if (*s == 'e' || *s == 'E') {
      f = 1;
    }
    ++s;
  }
  return f;
}