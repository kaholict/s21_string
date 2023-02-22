#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdlib.h>

typedef long unsigned s21_size_t;
#define s21_NULL ((void*)0);

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, size_t n);

#endif  // SRC_S21_STRING_H_
