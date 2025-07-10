#include "s21_sprintf.h"

#include <math.h>
#include <wchar.h>

int s21_sprintf(char* str, const char* format, ...) {
  va_list va;
  va_start(va, format);
  char* res = str;

  while (*format != '\0') {
    if (*format != '%') {
      *res++ = *format++;
    } else {
      format++;
      if (*format && *format == '%') {
        *res++ = *format++;
      } else if (*format) {
        flags flag = {0};

        fun_flags(&format, &flag);
        get_width(&format, &flag, va);
        get_precision(&format, &flag, va);
        get_length(&format, &flag);

        if (*format) {
          flag.spec = *format;
          format++;
          if (flag.spec == 'n') {
            int* count = va_arg(va, int*);
            *count = res - str;
          } else {
            char buffer[BUFF_SIZE] = {0};
            form_str(buffer, &flag, va);
            for (s21_size_t i = 0; buffer[i] != '\0'; ++i, ++res) {
              *res = buffer[i];
            }
          }
        }
      }
    }
  }

  va_end(va);
  *res = '\0';
  return res - str;
}

void form_str(char* buffer, flags* flag, va_list va) {
  char tmp[BUFF_SIZE] = {'\0'};
  if (flag->spec == 'c') {
    if (flag->length == 'l') {
      wchar_t c = va_arg(va, wchar_t);
      wcstombs(tmp, &c, BUFF_SIZE);
    } else {
      tmp[0] = va_arg(va, int);
    }
  } else if (is_int_spec(flag->spec)) {
    process_int(tmp, flag, va);
  } else if (flag->spec == 'x' || flag->spec == 'X') {
    process_hex(tmp, flag, va);
  } else if (is_float_spec(flag->spec)) {
    process_float(tmp, flag, va);
  } else if (flag->spec == 'p') {
    process_pointer(tmp, va);
  } else if (flag->spec == 's') {
    process_string(tmp, flag, va);
  } else if (flag->spec == 'u') {
    process_unsigned(tmp, flag, va);
  }
  if (flag->spec == 'X' || flag->spec == 'G' || flag->spec == 'E') {
    to_upper(tmp);
  }
  postprocess(buffer, tmp, flag);
}

void reverse(char* str) {
  s21_size_t len = s21_strlen(str);
  s21_size_t i = 0, j = len - 1;

  while (j > 0 && i < j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    ++i;
    --j;
  }
}

void process_pointer(char* tmp, va_list va) {
  uint64_t address = va_arg(va, uint64_t);
  if (address == 0) {
    s21_strcpy(tmp, "(nil)");
  } else {
    int idx = uint_to_str(tmp, address, 16);
    tmp[idx++] = 'x';
    tmp[idx] = '0';
    reverse(tmp);
  }
}

void postprocess(char* dest, char* src, flags* f) {
  s21_size_t len = s21_strlen(src);
  int shift = f->width - len;

  if (f->minus && shift > 0) {
    s21_strcpy(dest, src);
    s21_memset(dest + len, ' ', shift);
  } else if (shift > 0) {
    char c = (f->zero) ? '0' : ' ';
    s21_memset(dest, c, shift);
    s21_strcpy(dest + shift, src);
  } else {
    s21_strcpy(dest, src);
  }
}

void to_upper(char* s) {
  for (s21_size_t i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - ('a' - 'A');
    }
  }
}

void process_float(char* buffer, flags* f, va_list va) {
  long double val = 0;
  if (f->length == 0 || f->length == 'l' || f->length == 'h') {
    val = va_arg(va, double);
  } else if (f->length == 'L') {
    val = va_arg(va, long double);
  }
  if (isnan(val)) {
    s21_strcpy(buffer, "-nan");
  } else if (isinf(val)) {
    if (val < 0) {
      s21_strcpy(buffer, "-inf");
    } else if (f->plus) {
      s21_strcpy(buffer, "+inf");
    } else {
      s21_strcpy(buffer, "inf");
    }
  } else {
    f->precision = (f->prec_flag) ? f->precision : 6;

    switch (f->spec) {
      case 'f':
        format_f(buffer, f, val);
        break;
      case 'g':
      case 'G':
        format_g(buffer, f, val);
        break;
      case 'e':
      case 'E':
        format_e(buffer, f, val);
    }
  }
}

int get_exponent(long double val) {
  int exponent = 0;
  if (val != 0) {
    while (val >= 10.0) {
      val /= 10.0;
      exponent++;
    }
    while (val < 1.0) {
      val *= 10.0;
      exponent--;
    }
  }
  return exponent;
}

void remove_zeros(char* buffer) {
  char* dot = s21_strchr(buffer, '.');
  if (dot) {
    s21_size_t i = s21_strlen(buffer) - 1;
    while (buffer[i] == '0') {
      buffer[i--] = '\0';
    }
  }
}

void format_g(char* buffer, flags* f, long double val) {
  if (val == 0) {
    buffer[0] = '0';
  } else {
    if (f->precision == 0) {
      f->precision = 1;
    }
    int exponent = get_exponent(val);
    if (exponent >= f->precision || exponent < -4) {
      f->precision -= 1;
      format_e(buffer, f, val);
    } else {
      f->precision = f->precision - exponent - 1;
      format_f(buffer, f, val);
      remove_zeros(buffer);
    }
  }
}

void write_reverse_num(int num, char* buffer, int* idx) {
  while (num) {
    buffer[*idx] = (num % 10) + '0';
    (*idx)++;
    num /= 10;
  }
}

void write_exponent(char* buffer, int exp, char exp_sign) {
  int idx = 0;
  char tmp[BUFF_SIZE] = {'\0'};

  if (exp < 10) {
    tmp[idx++] = '0' + exp;
    tmp[idx++] = '0';
  } else {
    write_reverse_num(exp, tmp, &idx);
  }
  tmp[idx++] = exp_sign;
  tmp[idx++] = 'e';
  s21_strrcpy(buffer, tmp);
}

void format_e(char* buffer, flags* f, long double val) {
  int idx = 0;
  int neg = (val < 0);
  val = neg ? -val : val;
  int exponent = 0;
  if (val != 0) {
    while (val >= 10.0) {
      val /= 10.0;
      exponent++;
    }
    while (val < 1.0) {
      val *= 10.0;
      exponent--;
    }
  }
  val += f->precision == 0 ? 0.5 : 0.0;
  long double int_part, frac_part = modfl(val, &int_part);
  char exp_sign = (exponent >= 0) ? '+' : '-';
  exponent = (exponent < 0) ? -exponent : exponent;
  if (neg) {
    buffer[idx++] = '-';
  } else if (f->plus) {
    buffer[idx++] = '+';
  } else if (f->space) {
    buffer[idx++] = ' ';
  }
  idx += double_int_to_str(buffer + idx, int_part);
  if (f->precision > 0 &&
      ((f->spec != 'g' && f->spec != 'G') || frac_part > 1e-10)) {
    buffer[idx++] = '.';
    process_mantissa(buffer, f, frac_part, idx);
    idx += f->precision;
  }
  write_exponent(buffer + idx, exponent, exp_sign);
}

s21_size_t double_int_to_str(char* buffer, long double val) {
  char tmp[BUFF_SIZE] = {'\0'};
  tmp[0] = '0';
  s21_size_t i = 0;

  while (val >= 1) {
    tmp[i++] = fmodl(val, 10) + '0';
    val /= 10;
  }
  reverse(tmp);
  s21_strcpy(buffer, tmp);
  return i ? i : 1;
}

void process_mantissa(char* str, flags* f, long double val, s21_size_t idx) {
  val += 5 * pow(10, -(f->precision + 1));
  for (int i = 0; i < f->precision; i++) {
    val *= 10;
    int digit = (int)(val);
    str[idx++] = '0' + digit;
    val -= digit;
  }
  if (f->spec == 'g' || f->spec == 'G') remove_zeros(str);
}

void format_f(char* buffer, flags* f, long double val) {
  s21_size_t idx = 0;
  int8_t neg = (val < 0);
  val = neg ? -val : val;
  val += f->precision ? 0 : 0.5;
  long double int_part, frac_part = modfl(val, &int_part);
  if (neg) {
    buffer[idx++] = '-';
  } else if (f->plus) {
    buffer[idx++] = '+';
  } else if (f->space) {
    buffer[idx++] = ' ';
  }

  idx += double_int_to_str(buffer + idx, int_part);
  if (f->precision) {
    buffer[idx++] = '.';
    process_mantissa(buffer, f, frac_part, idx);
  }
}

void process_string(char* tmp, flags* f, va_list va) {
  if (f->length == 'l') {
    wchar_t* wstr = va_arg(va, wchar_t*);
    wcstombs(tmp, wstr, BUFF_SIZE);
  } else {
    char* str = va_arg(va, char*);
    s21_strcpy(tmp, str);
  }
  int len = s21_strlen(tmp);
  if (f->prec_flag && len > f->precision) {
    tmp[f->precision] = '\0';
  }
}

void process_unsigned(char* buf, flags* f, va_list va) {
  uint64_t val = va_arg(va, uint64_t);

  switch (f->length) {
    case 'h':
      val = (uint16_t)val;
      break;
    case 0:
      val = (uint32_t)val;
      break;
  }
  int idx = uint_to_str(buf, val, 10);
  add_zeros(buf, f->precision, &idx);
  reverse(buf);
}

int uint_to_str(char* buff, uint64_t val, int base) {
  int idx = 0;
  if (val == 0) {
    buff[idx++] = '0';
  } else {
    while (val > 0) {
      buff[idx] = "0123456789abcdef"[val % base];
      val /= base;
      ++idx;
    }
  }
  return idx;
}

void add_zeros(char* str, int num, int* idx) {
  while (*idx < num) {
    str[*idx] = '0';
    (*idx)++;
  }
}

void int_to_str(char* buff, flags* f, int64_t val, int base) {
  int8_t neg = (val < 0);
  val = neg ? -val : val;
  int idx = uint_to_str(buff, val, base);
  int zeros_to_add =
      f->precision -
      (f->hash * base == 8 + f->hash * 2 * (base == 16 && val != 0));
  add_zeros(buff, zeros_to_add, &idx);
  if (base == 8 && f->hash) {
    buff[idx++] = '0';
  } else if (base == 16 && f->hash && val != 0) {
    buff[idx++] = 'x';
    buff[idx++] = '0';
  }
  if (neg) {
    buff[idx] = '-';
  } else if (f->plus && base == 10) {
    buff[idx] = '+';
  } else if (f->space && base == 10) {
    buff[idx] = ' ';
  }
  reverse(buff);
}

void process_hex(char* tmp, flags* f, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  if (val != 0 || f->precision != 0 || !f->prec_flag) {
    switch (f->length) {
      case 'h':
        val = (uint16_t)val;
        break;
      case 0:
        val = (uint32_t)val;
        break;
    }
    int_to_str(tmp, f, val, 16);
  }
}

void process_int(char* tmp, flags* f, va_list va) {
  int64_t val = va_arg(va, int64_t);
  if (val != 0 || f->precision != 0 || !f->prec_flag) {
    switch (f->length) {
      case 'h':
        val = (int16_t)val;
        break;
      case 0:
        val = (int32_t)val;
        break;
    }
    if (f->spec == 'o') {
      int_to_str(tmp, f, val, 8);
    } else if (f->spec == 'd' || f->spec == 'i') {
      int_to_str(tmp, f, val, 10);
    }
  }
}

void get_precision(const char** format, flags* flag, va_list va) {
  if (**format == '.') {
    flag->prec_flag = 1;
    (*format)++;
    process_format_num(format, &flag->precision, va);
  }
}

void get_width(const char** format, flags* flag, va_list va) {
  process_format_num(format, &flag->width, va);
}

void fun_flags(const char** format, flags* flag) {
  while (**format && is_flag(**format)) {
    switch (**format) {
      case '-':
        flag->minus = 1;
        flag->zero = 0;
        break;
      case '+':
        flag->plus = 1;
        flag->space = 0;
        break;
      case '#':
        flag->hash = 1;
        break;
      case ' ':
        flag->space = !flag->plus;
        break;
      case '0':
        flag->zero = !flag->minus;
        break;
    }
    (*format)++;
  }
}