#ifndef s21_cat
#define s21_cat

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags {
  int bflag;
  int eflag;
  int Eflag;
  int vflag;
  int nflag;
  int sflag;
  int tflag;
  int Tflag;
  int defaultflag;
};

// функция парсинга
int get_opt(int argc, char **argv, struct flags *flag);

// функция обработки файла и текстового потока
void cat(char *path, struct flags);

// флаги
int s(struct flags flag, int *prev, int *ch, int *str);
void b(struct flags flag, int *prev, int *ch, int *current_line);
void n(struct flags flag, int *prev, int *current_line);
void E(struct flags flag, int *prev, int *ch);
void T(struct flags flag, int *ch);
void v(struct flags flag, int *ch);

#endif