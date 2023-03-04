#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)
typedef long unsigned int s21_size_t;
#define UNSIGNED_INT_MAX_VALUE 4294967296

typedef struct {
  int flagMinus;
  int flagPlus;
  int flagSpace;
  int flagReshotca;
  int width;
  int accuracy;
  int length;
  char option;
  int Error;
} StructFormat;

// string.h
s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// s21_C#
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

// s21_stdio.h
int s21_sprintf(char *str, const char *format, ...);

// some function
void line_reversal(char *str);
int hex_fitting(long long prototype, int reg);
void record_to_string(StructFormat my_struct, char *str, char *temp_string,
                      int sign, int *count);
void space_record(StructFormat my_struct, char *str, char *temp_string, int sign,
                  int *count);
void flags_symb_record(StructFormat my_struct, char *str, char *temp_string,
                       int sign, int *count);

char *number_to_string(long int d, int base);
char *double_to_string(long double f, StructFormat my_struct);

// ilya`s parse
int func_to_parse_num(char *format, int counter, int point_position,
                      StructFormat *my_struct);
StructFormat parserformat(int start, int end, char *format);
void unit_format(char *format, int *start, int *end, StructFormat *my_struct);
void func_to_parse_len(char *format, int counter, char *first_length,
                       StructFormat *my_struct, int last_ind);

// base of sprintf
void Specifiers(StructFormat my_struct, va_list arguments, char *str,
                int *count);
void Specifier_c(StructFormat my_struct, va_list arguments, char *str,
                 int *count);
void Specifier_double(StructFormat my_struct, va_list arguments, char *str,
                     int *count);
void Specifier_string(StructFormat my_struct, va_list arguments, char *str,
                      int *count);
void Specifier_nusigned_int(StructFormat my_struct, va_list arguments,
                            char *str, int *count);
void Specifier_persent(StructFormat my_struct, char *str, int *count);
void Specifier_n(va_list arguments, int *count);
void Specifier_octal(StructFormat my_struct, va_list arguments, char *str, int *count);
void Specifier_hex_pointer(StructFormat my_struct, va_list arguments, char *str, int *count);

void ftoa(double f, char *buf, int precision);  //  надо переделать
void add_spaces_or_zeros(char *str, int value, char ch, int *i_str);
void itoa(long long n, char *buf);

#endif  // SRC_S21_STRING_H_
