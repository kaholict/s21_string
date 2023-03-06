#include <check.h>
#include <stdio.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(s21_memchr_test) {
  char test1[] = "123456";
  char test2 = '4';
  char test3 = '7';
  char test4[] = "hello/\0";
  char test5[] = "h";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 6),
                    (unsigned long)memchr(test1, test3, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 6),
                    (unsigned long)memchr(test4, test6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 6),
                    (unsigned long)memchr(test4, test8, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 6),
                    (unsigned long)memchr(test4, test9, 6));
}
END_TEST

START_TEST(memchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_9) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_10) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = s21_strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "Apple Pay Money Day";
  char test2[] = "Apple with worm";
  char test3[] = "\0";
  char test4[] = "gud\0 job";
  char test5[] = "gud\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16) < 0,
                    memcmp(test1, test2, 16) < 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
}
END_TEST

START_TEST(memcmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 13;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_6) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 2;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_10) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 7;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_11) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 4;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 8;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_13) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  s21_size_t n = 9;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_14) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_15) {
  char s1[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2.";
  char s2[] =
      "The memcmp() function compares the first n bytes (each interpreted as "
      "unsigned char) of the memory areas s1 and s2";
  s21_size_t n = 115;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(memcmp_16) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 0;
  int n1 = memcmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_memcmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strlen_test) {
  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(strlen_1) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[] =
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  char str[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(s21_strcpy_test) {
  char test_1[] = "00000";
  char test_2[] = "     ";
  char test_3[] = "123\07";
  char test_4[] = "first_string\0second_string";
  char test_5[128] = "";
  char test_6[] = "Hello, world!!!";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST

START_TEST(memcpy_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[] = "new_strnew_string";
  char s2[] = "new_strnew_string";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_2[5] = "<<<";
  char test_4[2] = "5";
  char test_44[2] = "5";
  char test_5[] = "";

  ck_assert_str_eq(s21_strncat(test_2, test_4, 1), "<<<5");
  ck_assert_str_eq(s21_strncat(test_44, test_5, 0), strncat(test_4, test_5, 0));
}
END_TEST

START_TEST(strncat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "My name is Polina.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(strncat_15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "My name is Polina.";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(strstr_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_7) {
  char s1[] = "";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_8) {
  char s1[] = "69917020";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_9) {
  char s1[] = "69917020";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(strstr_11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

// START_TEST(strstr_12) {
//   char s1[] = "sususususpicioussusususpicious";
//   char s2[] = "susp";
//   ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
// }
// END_TEST

START_TEST(strstr_13) {
  char s1[] = "sus";
  char s2[] = "suspi";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '3', 10),
                    (unsigned long)memchr(test1, '3', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '/', 8),
                    (unsigned long)memchr(test1, '/', 8));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '0', 4),
                    (unsigned long)memchr(test1, '0', 4));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '1', 3),
                    (unsigned long)memchr(test2, '1', 3));
}
END_TEST

START_TEST(memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(s21_strcmp_test) {
  char test1[] = "12345";
  char test2[] = "12305";
  char test3[] = "/%%5#";
  char test4[] = " @";
  char test5[] = "   ";
  char test6[] = "\\\\HH";
  ck_assert_uint_eq((unsigned long)s21_strcmp(test1, test2) > 0,
                    (unsigned long)strcmp(test1, test2) > 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test3, test4) > 0,
                    (unsigned long)strcmp(test3, test4) > 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test5, test6) < 0,
                    (unsigned long)strcmp(test5, test6) < 0);
}
END_TEST

START_TEST(strcmp_1) {
  char s1[] = "Andrey";
  char s2[] = "Andrey";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_2) {
  char s1[] = "Andrey";
  char s2[] = "Roma";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_3) {
  char s1[] = "";
  char s2[] = "";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_4) {
  char s1[] = "u";
  char s2[] = "\0";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_5) {
  char s1[] = "\0";
  char s2[] = "j";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_6) {
  char s1[] = "\0";
  char s2[] = "\0";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strcmp_7) {
  char s1[] = "shf roma \0 dljfn roma";
  char s2[] = "roma";
  int n1 = strcmp(s1, s2);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strcmp(s1, s2);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "0123456789";
  char test2[] = "9876";
  char test3[] = "LOST: 4-8-15-16-23-42";
  char test4[] = "1234567890";
  char test5[] = "0/";
  char test6[] = "%%\\#";
  char test7[] = " ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST

START_TEST(strcspn_1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '\0'),
                    (unsigned long)strrchr(test2, '\0'));
}
END_TEST

START_TEST(strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

// START_TEST(s21_strerror_test) {
//   char *test1 = s21_strerror(0);
//   char *test2 = strerror(0);
//   char *test3 = s21_strerror(106);
//   char *test4 = strerror(106);
//   char *test5 = s21_strerror(2147483647);
//   char *test6 = strerror(2147483647);
//   char *test7 = s21_strerror(-214748364);
//   char *test8 = strerror(-214748364);
//   ck_assert_uint_eq((unsigned long)*test1, (unsigned long)*test2);
//   ck_assert_uint_eq((unsigned long)*test3, (unsigned long)*test4);
//   ck_assert_uint_eq((unsigned long)*test5, (unsigned long)*test6);
//   ck_assert_uint_eq((unsigned long)*test7, (unsigned long)*test8);
// }
// END_TEST

START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(strerror(n), s21_strerror(n));
}
END_TEST

START_TEST(s21_memmove_test) {
  char src[] = "1234567";
  char dest[] = "abcdefg";
  size_t n = 4;

  char csrc[] = "1234567";
  char cdest[] = "abcdefg";
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(cdest, csrc, n));
  ck_assert_str_eq(dest, cdest);
  ck_assert_str_eq(dest, "1234efg");

  char dest_cover[] = "1234567";
  char *src_cover = dest_cover + 2;
  s21_memmove(dest_cover, src_cover, n);
  ck_assert_str_eq(dest_cover, "3456567");
}
END_TEST

START_TEST(memmove_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 4;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "forward";
  s21_size_t n = 0;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_4) {
  char s1[] = "100: Checks: 780, Failures: 0, Errors: 0";
  char s2[] = "100: Checks: 780, Failures: 0, Errors: 0";
  s21_size_t n = 6;
  memmove(s1, s1, n);
  s21_memmove(s2, s2, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_5) {
  char s1[] = "H";
  char s2[] = "H";
  char s3[] = "Hi";
  s21_size_t n = 2;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_6) {
  char s1[] = "jijijij";
  char s2[] = "jijijij";
  char s3[] = "\0";
  s21_size_t n = 1;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_7) {
  char s1[] = "           ";
  char s2[] = "           ";
  char s3[] = "new_string";
  s21_size_t n = strlen(s3);
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_8) {
  char s1[] = "699\017020";
  char s2[] = "699\017020";
  char s3[] = "com";
  s21_size_t n = 3;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_9) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "c";
  s21_size_t n = 1;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(memmove_10) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  char s3[] = "com";
  s21_size_t n = 4;
  memmove(s1, s3, n);
  s21_memmove(s2, s3, n);
  ck_assert_mem_eq(s1, s2, n);
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str1[] = "test of string";
  char dest1[15] = "";

  char str2[] = "test\0";
  char dest2[5] = "";

  char str3[] = "test ";
  char dest3[] = "crushcrush";

  ck_assert_str_eq(strncpy(dest1, str1, 5), s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq(strncpy(dest2, str2, 4), s21_strncpy(dest2, str2, 4));
  ck_assert_str_eq(strncpy(dest3, str3, 10), s21_strncpy(dest3, str3, 10));
}
END_TEST

START_TEST(strncpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}
END_TEST

START_TEST(strtok_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

// START_TEST(strtok_11) {
//   char *s1 = s21_NULL;
//   char *s2 = s21_NULL;
//   char s3[] = "";
//   ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
// }
// END_TEST

START_TEST(strtok_12) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
}
END_TEST

START_TEST(strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(s21_strncmp_test) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, worldj";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_3) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_4) {
  char s1[] = "f";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_5) {
  char s1[] = "";
  char s2[] = "j";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 19;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_7) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_8) {
  char s1[] = "g124243425";
  char s2[] = "124243424";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(s21_strspn_test) {
  char str1[] = "hella 1";
  char str2[] = "ell";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(strspn_1) {
  char s1[] = "123456789";
  char s2[] = "123";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_2) {
  char s1[] = "123456789";
  char s2[] = "456";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(strspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strspn(s1, s2), s21_strspn(s1, s2));
}
END_TEST

START_TEST(s21_strcat_test) {
  char test1[] = "Apple Pay Money Day";
  char test3[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test1, test3),
                    (unsigned long)strcat(test1, test3));
}
END_TEST

START_TEST(strcat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_7) {
  char s1[100] = "Hello\0world!";
  char s2[100] = "Hello\0world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_8) {
  char s1[100] = "\0";
  char s2[100] = "\0";
  char s3[] =
      "My name is Polina. I hate this\0, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "\0";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(strcat_10) {
  char s1[100] = "Hell0000\0";
  char s2[100] = "Hell0000\0";
  char s3[] = "";
  ck_assert_pstr_eq(strcat(s1, s3), s21_strcat(s2, s3));
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Hello!";
  char *str = ", world";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 15);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 10);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello!");
    free(new_str);
  }

  new_str = s21_insert("Hello!", ", world!!", 25);
  ck_assert(new_str == s21_NULL);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }
}
END_TEST

START_TEST(s21_trim_test) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

// START_TEST(s21_to_upper_test) {
//   char str1[] = "hella hello motherfucker";
//   char str2[] = "pRiVeT";

//   char *new_str = s21_to_upper(str1);

//   if (new_str) {
//     ck_assert_str_eq(new_str, "HELLA HELLO MOTHERFUCKER");
//     free(new_str);
//   }

//   new_str = s21_to_upper(str2);

//   if (new_str) {
//     ck_assert_str_eq(new_str, "PRIVET");
//     free(new_str);
//   }

//   char s1[30] = "Hello, world!";
//   char *s2 = s21_to_upper(s1);
//   char s3[] = "HELLO, WORLD!";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char s4[30] = "\nh\t\\g123123";
//   char *s5 = s21_to_upper(s4);
//   char s6[] = "\nH\t\\G123123";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char s7[30] = "ALREADY UPPER";
//   char *s8 = s21_to_upper(s1);
//   char s9[] = "ALREADY UPPER";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char s1[30] = "";
//   char *s2 = s21_to_upper(s1);
//   char s3[] = "";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char s1[30] = "abcdefghijklmnopqrstuvwxyz";
//   char *s2 = s21_to_upper(s1);
//   char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char s1[30] = "_?};!234";
//   char *s2 = s21_to_upper(s1);
//   char s3[] = "_?};!234";
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);

//   char *s1 = s21_NULL;
//   char *s2 = s21_to_upper(s1);
//   char *s3 = s21_NULL;
//   ck_assert_pstr_eq(s3, s2);
//   if (s2) free(s2);
// }
// END_TEST

START_TEST(test_to_upper_1) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "hella HELLO motherfucker";
  char str2[] = "pRiVeT";

  char *new_str = s21_to_lower(str1);

  if (new_str) {
    ck_assert_str_eq(new_str, "hella hello motherfucker");
    free(new_str);
  }

  new_str = s21_to_lower(str2);

  if (new_str) {
    ck_assert_str_eq(new_str, "privet");
    free(new_str);
  }
}
END_TEST

START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_sprintf_f_test) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%.f", b);
  int res_1_orig = sprintf(str_orig, "%.f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.00000002345;
  int res_2 = s21_sprintf(str, "%+-10.3f", b_2);
  int res_2_orig = sprintf(str_orig, "%+-10.3f", b_2);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  long double b_3 = -23.087654;
  int res_3 = s21_sprintf(str, "%20.10Lf", b_3);
  int res_3_orig = sprintf(str_orig, "%20.10Lf", b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  // double b_4 = 0;
  // int res_4 = s21_sprintf(str, "%0+.15F", b_4);
  // int res_4_orig = sprintf(str_orig, "%0+.15F", b_4);

  // ck_assert_int_eq(res_4, res_4_orig);
  // ck_assert_str_eq(str, str_orig);

  // long double b_5 = 0;
  // int res_5 = s21_sprintf(str, "%#.0Lf", b_5);
  // int res_5_orig = sprintf(str_orig, "%#.0Lf", b_5);

  // ck_assert_int_eq(res_5, res_5_orig);
  // ck_assert_str_eq(str, str_orig);

  // double b_6 = 1.0 / 0.0;

  // int res_6 = s21_sprintf(str, "%#10.0f", b_6);
  // int res_6_orig = sprintf(str_orig, "%#10.0f", b_6);

  // ck_assert_int_eq(res_6, res_6_orig);
  // ck_assert_str_eq(str, str_orig);

  double b_7 = 1234523459.123456789;
  int res_7 = s21_sprintf(str, "%.5f", b_7);
  int res_7_orig = sprintf(str_orig, "%.5f", b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_8 = 1;
  int res_8 = s21_sprintf(str, "%f", b_8);
  int res_8_orig = sprintf(str_orig, "%f", b_8);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  // double b_9 = 0.00345;
  // int res_9 = s21_sprintf(str, "%f", b_9);
  // int res_9_orig = sprintf(str_orig, "%f", b_9);

  // ck_assert_int_eq(res_9, res_9_orig);
  // ck_assert_str_eq(str, str_orig);

  double b_11 = 1234567.003459876543298;
  int res_11 = s21_sprintf(str, "%.15f", b_11);
  int res_11_orig = sprintf(str_orig, "%.15f", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// START_TEST(s21_sprintf_g_test) {
//   char str[80];
//   char str_orig[80];

//   // double b_1 = -22.25600;
//   // int res_1 = s21_sprintf(str, "%+-10.3G", b_1);
//   // int res_1_orig = sprintf(str_orig, "%+-10.3G", b_1);

//   // ck_assert_int_eq(res_1, res_1_orig);
//   // ck_assert_str_eq(str, str_orig);

//   double b_2 = 0.00000000000001;
//   int res_2 = s21_sprintf(str, "%#G", b_2);
//   int res_2_orig = sprintf(str_orig, "%#G", b_2);

//   ck_assert_int_eq(res_2, res_2_orig);
//   ck_assert_str_eq(str, str_orig);

//   int a = -10;
//   long double b_3 = 1234567.2345678;
//   int res_3 = s21_sprintf(str, "%+30.*Lg", a, b_3);
//   int res_3_orig = sprintf(str_orig, "%+30.*Lg", a, b_3);

//   ck_assert_int_eq(res_3, res_3_orig);
//   ck_assert_str_eq(str, str_orig);

//   int width = -10, precision = 2;
//   double b_4 = 0;
//   int res_4 = s21_sprintf(str, "%-#*.*g", width, precision, b_4);
//   int res_4_orig = sprintf(str_orig, "%-#*.*g", width, precision, b_4);

//   ck_assert_int_eq(res_4, res_4_orig);
//   ck_assert_str_eq(str, str_orig);

//   double b_5 = -0.000000654;
//   int res_5 = s21_sprintf(str, "%+-25g", b_5);
//   int res_5_orig = sprintf(str_orig, "%+-25g", b_5);

//   ck_assert_int_eq(res_5, res_5_orig);
//   ck_assert_str_eq(str, str_orig);

//   double b_6 = 320.0;
//   int res_6 = s21_sprintf(str, "%+-25g%g", b_5, b_6);
//   int res_6_orig = sprintf(str_orig, "%+-25g%g", b_5, b_6);

//   ck_assert_int_eq(res_6, res_6_orig);
//   ck_assert_str_eq(str, str_orig);

//   double b_7 = -120.0001;
//   int res_7 = s21_sprintf(str, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);
//   int res_7_orig = sprintf(str_orig, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);

//   ck_assert_int_eq(res_7, res_7_orig);
//   ck_assert_str_eq(str, str_orig);

//   double b_10 = 5.0, b_8 = 0.0000000012345, b_9 = 1.0;
//   int res_8 = s21_sprintf(str, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
//   int res_8_orig = sprintf(str_orig, "%-20G %010.5g %+Fhello", b_8, b_9,
//   b_10); ck_assert_int_eq(res_8, res_8_orig); ck_assert_str_eq(str,
//   str_orig);

//   double b_11 = 0.001;
//   int res_11 = s21_sprintf(str, "%0.g", b_11);
//   int res_11_orig = sprintf(str_orig, "%0.g", b_11);

//   ck_assert_int_eq(res_11, res_11_orig);
//   ck_assert_str_eq(str, str_orig);

//   double b_12 = 0.00000000001;
//   int res_12 = s21_sprintf(str, "%.10g", b_12);
//   int res_12_orig = sprintf(str_orig, "%.10g", b_12);

//   ck_assert_int_eq(res_12, res_12_orig);
//   ck_assert_str_eq(str, str_orig);
// }
// END_TEST

START_TEST(s21_sprintf_prc_test) {
  char str[80];
  char str_orig[80];

  int res_1 = s21_sprintf(str, "%%");
  int res_1_orig = sprintf(str_orig, "%%");
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_2 = s21_sprintf(str, "%10%");

  // ck_assert_int_eq(res_2, 10);
  // ck_assert_str_eq(str, "         %");

  // int a_prc = 14;
  // int res_3 = s21_sprintf(str, "hhhh%0*%", a_prc);

  // ck_assert_int_eq(res_3, 18);
  // ck_assert_str_eq(str, "hhhh0000000000000%");

  // int width_prc = 30;
  // int res_4 = s21_sprintf(str, "%-*%12345", width_prc);

  // ck_assert_int_eq(res_4, 35);
  // ck_assert_str_eq(str, "%                             12345");

  int res_5 = s21_sprintf(str, "abc%%defg");
  int res_5_orig = sprintf(str_orig, "abc%%defg");

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_n_test) {
  char str[80];
  char str_orig[80];

  int c_1, c_1_orig;
  int res_1 = s21_sprintf(str, "%n", &c_1);
  int res_1_orig = sprintf(str_orig, "%n", &c_1_orig);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_int_eq(c_1, c_1_orig);
  ck_assert_str_eq(str, str_orig);

  int c_2, c_2_orig;
  int res_2 = s21_sprintf(str, "12345%n678910", &c_2);
  int res_2_orig = sprintf(str_orig, "12345%n678910", &c_2_orig);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_int_eq(c_2, c_2_orig);
  ck_assert_str_eq(str, str_orig);

  int c_3, c_3_orig;
  int res_3 = s21_sprintf(str, "%nqwerty", &c_3);
  int res_3_orig = sprintf(str_orig, "%nqwerty", &c_3_orig);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_int_eq(c_3, c_3_orig);
  ck_assert_str_eq(str, str_orig);

  int c_4, c_4_orig;
  int res_4 = s21_sprintf(str, "hhhhh%n%%", &c_4);
  int res_4_orig = sprintf(str_orig, "hhhhh%n%%", &c_4_orig);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_int_eq(c_4, c_4_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

// START_TEST(s21_sprintf_f_g_n_prc_test) {
//   char str[80];

//   int n_1, n_2;
//   double f_1 = 1.0, f_2 = -0.1234567890;

//   int res_1 =
//        s21_sprintf(str, "qwerty%n %10.5f %#.4g %08% %n", &n_1, f_1, f_2,
//        &n_2);

//   ck_assert_int_eq(res_1, 35);
//   ck_assert_int_eq(n_1, 6);
//   ck_assert_int_eq(n_2, 35);
//   ck_assert_str_eq(str, "qwerty    1.00000 -0.1235 0000000% ");

//   long double f_3 = 0.1234500;
//   double f_4 = 12300000.0;
//   int n_3;
//   int res_2 = s21_sprintf(str, "%-20% %#0 Lf %n %-.10G g%010%", f_3, &n_3,
//   f_4);

//   ck_assert_int_eq(res_2, 52);
//   ck_assert_int_eq(n_3, 31);
//   ck_assert_str_eq(str, "%                     0.123450  12300000
//   g000000000%");
// }
// END_TEST

START_TEST(s21_sprintf_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "Hello";
  char c = 'X';
  char d = 'Y';
  int result1 = s21_sprintf(str, format_str1, c);
  int result_origin1 = sprintf(str_origin, format_str1, c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "Hello, %c %c";
  int result2 = s21_sprintf(str, format_str2, c, d);
  int result_origin2 = sprintf(str_origin, format_str2, c, d);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  char *s1 = "world!";
  char *s2 = "Hello world!";
  const char *format_str3 = "Hello, %10s %10.15s";
  int result3 = s21_sprintf(str, format_str3, s1, s2);
  int result_origin3 = sprintf(str_origin, format_str3, s1, s2);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

// START_TEST(s21_sprintf_e_test) {
//   char str[80];
//   char str_origin[80];
//   const char *format_str1 = "% 10.15LE yo";
//   long double mantissa1 = 0.0000003044058697058435;
//   int result1 = s21_sprintf(str, format_str1, mantissa1);
//   int result_origin1 = sprintf(str_origin, format_str1, mantissa1);
//   ck_assert_int_eq(result1, result_origin1);
//   ck_assert_str_eq(str, str_origin);

//   const char *format_str2 = "%-20.7e yo";
//   double mantissa2 = -4044050;
//   int result2 = s21_sprintf(str, format_str2, mantissa2);
//   int result_origin2 = sprintf(str_origin, format_str2, mantissa2);
//   ck_assert_int_eq(result2, result_origin2);
//   ck_assert_str_eq(str, str_origin);

//   const char *format_str3 = "%-.5E yo";
//   double mantissa3 = -0.00;
//   int result3 = s21_sprintf(str, format_str3, mantissa3);
//   int result_origin3 = sprintf(str_origin, format_str3, mantissa3);
//   ck_assert_int_eq(result3, result_origin3);
//   ck_assert_str_eq(str, str_origin);

//   const char *format_str4 = "Hello %+020.15E %LE yo";
//   double mantissa4 = 1.004554367;
//   long double mantissa5 = -432432455454;
//   int result4 = s21_sprintf(str, format_str4, mantissa4, mantissa5);
//   int result_origin4 = sprintf(str_origin, format_str4, mantissa4,
//   mantissa5); ck_assert_int_eq(result4, result_origin4);
//   ck_assert_str_eq(str, str_origin);

//   const char *format_str5 = "This is infinite: %-20.5e and this is nan:
//   %20e"; double infinite = 1.0 / 0.0; double not_a_number = infinite * 0.0;
//   int result5 = s21_sprintf(str, format_str5, infinite, not_a_number);
//   int result_origin5 = sprintf(str_origin, format_str5, infinite,
//   not_a_number); ck_assert_int_eq(result5, result_origin5);
//   ck_assert_str_eq(str, str_origin);

//   const char *format_str6 = "% -10.15E yo";
//   double mantissa6 = 0.00003044058697058435;
//   int result6 = s21_sprintf(str, format_str6, mantissa6);
//   int result_origin6 = sprintf(str_origin, format_str6, mantissa6);
//   ck_assert_int_eq(result6, result_origin6);
//   ck_assert_str_eq(str, str_origin);
// }
// END_TEST

START_TEST(s21_sprintf_p_test) {
  char str[80];
  char str_origin[80];
  int a = 10;
  char *format_str1 = "This is the pointer: %p\n";
  int result1 = s21_sprintf(str, format_str1, &a);
  int result_origin1 = sprintf(str_origin, format_str1, &a);

  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  char *pointer = "Test";
  double double_pointer = 84759375969;

  char *format_str2 = "To the left: %-20p!\nTo the right %20p!";

  int result2 = s21_sprintf(str, format_str2, pointer, &double_pointer);
  int result_origin2 =
      sprintf(str_origin, format_str2, pointer, &double_pointer);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  int *empty_pointer = s21_NULL;
  char *format_str3 = "This is empty pointer %p\n";
  int result3 = s21_sprintf(str, format_str3, empty_pointer);
  int result_origin3 = sprintf(str_origin, format_str3, empty_pointer);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%o", arr1[0]);
  int res1 = sprintf(str1, "%o", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-12.3lo", (unsigned long)arr1[4]);
  res1 = sprintf(str1, "%-12.3lo", (unsigned long)arr1[4]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "%010.5o", arr1[5]);
  // ck_assert_str_eq(str, "37777775231");
  // ck_assert_int_eq(res, 11);

  // res = s21_sprintf(str, "%0#3.7o gterth", arr1[6]);
  // ck_assert_str_eq(str, "0022253 gterth");
  // ck_assert_int_eq(res, 14);

  res = s21_sprintf(str, "%-.4o gterth", arr1[6]);
  res1 = sprintf(str1, "%-.4o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "%-#.9o gterth", arr1[6]);
  // res1 = sprintf(str1, "%-#.9o gterth", arr1[6]);
  // ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  // ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "hello %0.o gterth", arr1[6]);
  // ck_assert_str_eq(str, "hello 22253 gterth");
  // ck_assert_int_eq(res, 18);

  // res = s21_sprintf(str, "hello %#o gterth", arr1[6]);
  // res1 = sprintf(str1, "hello %#o gterth", arr1[6]);
  // ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  // ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "hello %*.o gterth", 5, arr1[6]);
  // res1 = sprintf(str1, "hello %*.o gterth", 5, arr1[6]);
  // ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  // ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "hello %010.7o gterth", arr1[6]);
  // ck_assert_str_eq(str, "hello    0022253 gterth");
  // ck_assert_int_eq(res, 23);

  // res = s21_sprintf(str, "%010.7ho", (unsigned short)arr1[6]);
  // ck_assert_str_eq(str, "   0022253");
  // ck_assert_int_eq(res, 10);
}
END_TEST

START_TEST(s21_sprintf_x_X_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%x", arr1[0]);
  int res1 = sprintf(str1, "%x", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7hx", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%#10.7hx", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3lx", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%-#10.3lx", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%X", arr1[0]);
  res1 = sprintf(str1, "%X", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7lX", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%#10.7lX", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3hX", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#10.3hX", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  // res = s21_sprintf(str, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  // res1 = sprintf(str1, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  // ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  // ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  char str[80];
  char str1[80];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str[80];
  char str1[80];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%-11.10s", x);
  int res1 = sprintf(str1, "%-11.10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%11.8s", x);
  res1 = sprintf(str1, "%11.8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%0u", a);
  int res_4_orig = sprintf(str_orig, "%0u", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-u", a);
  int res_5_orig = sprintf(str_orig, "%-u", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%u", a);
  int res_6_orig = sprintf(str_orig, "%u", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%5u", a);
  int res_7_orig = sprintf(str_orig, "%5u", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_8 = s21_sprintf(str, "%05u", a);
  // int res_8_orig = sprintf(str_orig, "%05u", a);

  // ck_assert_int_eq(res_8, res_8_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5u", a);
  int res_9_orig = sprintf(str_orig, "%-5u", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%.5u", a);
  int res_10_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%.5u", a);
  int res_11_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%-.5u", a);
  int res_12_orig = sprintf(str_orig, "%-.5u", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%-10.5u", a);
  int res_13_orig = sprintf(str_orig, "%-10.5u", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%3.5u", a);
  int res_14_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%-3.5u", a);
  int res_15_orig = sprintf(str_orig, "%-3.5u", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "%6.2u", a);
  int res_16_orig = sprintf(str_orig, "%6.2u", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%3.2u", a);
  int res_17_orig = sprintf(str_orig, "%3.2u", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%01u", a);
  int res_18_orig = sprintf(str_orig, "%01u", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%hu", (unsigned short)a);
  int res_19_orig = sprintf(str_orig, "%hu", (unsigned short)a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%lu", (unsigned long)a);
  int res_20_orig = sprintf(str_orig, "%lu", (unsigned long)a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[80];
  char str_orig[80];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_10 = s21_sprintf(str, "%05d", a);
  // int res_10_orig = sprintf(str_orig, "%05d", a);

  // ck_assert_int_eq(res_10, res_10_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_15 = s21_sprintf(str, "%05d", a);
  // int res_15_orig = sprintf(str_orig, "%.5d", a);

  // ck_assert_int_eq(res_15, res_15_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%hd", (unsigned short)a);
  int res_26_orig = sprintf(str_orig, "%hd", (unsigned short)a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%ld", (unsigned long)a);
  int res_27_orig = sprintf(str_orig, "%ld", (unsigned long)a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_2) {
  char str[80];
  char str_orig[80];
  int a = -23454546;

  // int res_1 = s21_sprintf(str, "%10.*d", 5, a);
  // int res_1_orig = sprintf(str_orig, "%10.*d", 5, a);

  // ck_assert_int_eq(res_1, res_1_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_10 = s21_sprintf(str, "%0*d", 5, a);
  // int res_10_orig = sprintf(str_orig, "%0*d", 5, a);

  // ck_assert_int_eq(res_10, res_10_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_3) {
  char str[80];
  char str_orig[80];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_10 = s21_sprintf(str, "%05d", a);
  // int res_10_orig = sprintf(str_orig, "%05d", a);

  // ck_assert_int_eq(res_10, res_10_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_30 = s21_sprintf(str, "%+05d", a);
  // int res_30_orig = sprintf(str_orig, "%+05d", a);

  // ck_assert_int_eq(res_30, res_30_orig);
  // ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_4) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_10 = s21_sprintf(str, "%05d", a);
  // int res_10_orig = sprintf(str_orig, "%05d", a);

  // ck_assert_int_eq(res_10, res_10_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_26 = s21_sprintf(str, "%+05d", a);
  // int res_26_orig = sprintf(str_orig, "%+05d", a);

  // ck_assert_int_eq(res_26, res_26_orig);
  // ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_5) {
  char str[80];
  char str_orig[80];
  int a = -2344;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_6) {
  char str[80];
  char str_orig[80];
  int a = 23;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%+0d", a);
  int res_5_orig = sprintf(str_orig, "%+0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-+d", a);
  int res_6_orig = sprintf(str_orig, "%-+d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-+5d", a);
  int res_11_orig = sprintf(str_orig, "%-+5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-+.5d", a);
  int res_18_orig = sprintf(str_orig, "%-+.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-+10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-+10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-+3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-+3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_26 = s21_sprintf(str, "%+05d", a);
  // int res_26_orig = sprintf(str_orig, "%+05d", a);

  // ck_assert_int_eq(res_26, res_26_orig);
  // ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_0) {
  char str[80];
  char str_orig[80];
  int a = 0;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_5 = s21_sprintf(str, "%05d", a);
  // int res_5_orig = sprintf(str_orig, "%05d", a);

  // ck_assert_int_eq(res_5, res_5_orig);
  // ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  // int res_26 = s21_sprintf(str, "%+05d", a);
  // int res_26_orig = sprintf(str_orig, "%+05d", a);

  // ck_assert_int_eq(res_26, res_26_orig);
  // ck_assert_str_eq(str, str_orig);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *tc1_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, memchr_1);
  tcase_add_test(tc1_1, memchr_2);
  tcase_add_test(tc1_1, memchr_3);
  tcase_add_test(tc1_1, memchr_4);
  tcase_add_test(tc1_1, memchr_5);
  tcase_add_test(tc1_1, memchr_6);
  tcase_add_test(tc1_1, memchr_7);
  tcase_add_test(tc1_1, memchr_8);
  tcase_add_test(tc1_1, memchr_9);
  tcase_add_test(tc1_1, memchr_10);

  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, memcmp_1);
  tcase_add_test(tc1_1, memcmp_2);
  tcase_add_test(tc1_1, memcmp_3);
  tcase_add_test(tc1_1, memcmp_4);
  tcase_add_test(tc1_1, memcmp_5);
  tcase_add_test(tc1_1, memcmp_6);
  tcase_add_test(tc1_1, memcmp_7);
  tcase_add_test(tc1_1, memcmp_8);
  tcase_add_test(tc1_1, memcmp_9);
  tcase_add_test(tc1_1, memcmp_10);
  tcase_add_test(tc1_1, memcmp_11);
  tcase_add_test(tc1_1, memcmp_12);
  tcase_add_test(tc1_1, memcmp_13);
  tcase_add_test(tc1_1, memcmp_14);
  tcase_add_test(tc1_1, memcmp_15);
  tcase_add_test(tc1_1, memcmp_16);

  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, strlen_1);
  tcase_add_test(tc1_1, strlen_2);
  tcase_add_test(tc1_1, strlen_3);
  tcase_add_test(tc1_1, strlen_4);
  tcase_add_test(tc1_1, strlen_5);
  tcase_add_test(tc1_1, strlen_6);
  tcase_add_test(tc1_1, strlen_7);
  tcase_add_test(tc1_1, strlen_8);
  tcase_add_test(tc1_1, strlen_9);
  tcase_add_test(tc1_1, strlen_10);
  tcase_add_test(tc1_1, strlen_11);
  tcase_add_test(tc1_1, strlen_12);
  tcase_add_test(tc1_1, strlen_13);
  tcase_add_test(tc1_1, strlen_14);

  tcase_add_test(tc1_1, s21_strcpy_test);

  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, memcpy_1);
  tcase_add_test(tc1_1, memcpy_2);
  tcase_add_test(tc1_1, memcpy_3);
  tcase_add_test(tc1_1, memcpy_4);
  tcase_add_test(tc1_1, memcpy_5);
  tcase_add_test(tc1_1, memcpy_6);
  tcase_add_test(tc1_1, memcpy_7);
  tcase_add_test(tc1_1, memcpy_8);
  tcase_add_test(tc1_1, memcpy_9);
  tcase_add_test(tc1_1, memcpy_10);

  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, strncat_1);
  tcase_add_test(tc1_1, strncat_2);
  tcase_add_test(tc1_1, strncat_3);
  tcase_add_test(tc1_1, strncat_4);
  tcase_add_test(tc1_1, strncat_5);
  tcase_add_test(tc1_1, strncat_6);
  tcase_add_test(tc1_1, strncat_7);
  tcase_add_test(tc1_1, strncat_8);
  tcase_add_test(tc1_1, strncat_9);
  tcase_add_test(tc1_1, strncat_10);
  tcase_add_test(tc1_1, strncat_11);
  tcase_add_test(tc1_1, strncat_12);
  tcase_add_test(tc1_1, strncat_13);
  tcase_add_test(tc1_1, strncat_14);
  tcase_add_test(tc1_1, strncat_15);

  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, strstr_1);
  tcase_add_test(tc1_1, strstr_2);
  tcase_add_test(tc1_1, strstr_3);
  tcase_add_test(tc1_1, strstr_4);
  tcase_add_test(tc1_1, strstr_5);
  tcase_add_test(tc1_1, strstr_6);
  tcase_add_test(tc1_1, strstr_7);
  tcase_add_test(tc1_1, strstr_8);
  tcase_add_test(tc1_1, strstr_9);
  tcase_add_test(tc1_1, strstr_10);
  tcase_add_test(tc1_1, strstr_11);
  // tcase_add_test(tc1_1, strstr_12);
  tcase_add_test(tc1_1, strstr_13);

  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, memset_1);
  tcase_add_test(tc1_1, memset_2);
  tcase_add_test(tc1_1, memset_3);
  tcase_add_test(tc1_1, memset_4);
  tcase_add_test(tc1_1, memset_5);
  tcase_add_test(tc1_1, memset_6);

  tcase_add_test(tc1_1, s21_strcmp_test);
  tcase_add_test(tc1_1, strcmp_1);
  tcase_add_test(tc1_1, strcmp_2);
  tcase_add_test(tc1_1, strcmp_3);
  tcase_add_test(tc1_1, strcmp_4);
  tcase_add_test(tc1_1, strcmp_5);
  tcase_add_test(tc1_1, strcmp_6);
  tcase_add_test(tc1_1, strcmp_7);

  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, strcspn_1);
  tcase_add_test(tc1_1, strcspn_2);
  tcase_add_test(tc1_1, strcspn_3);
  tcase_add_test(tc1_1, strcspn_4);
  tcase_add_test(tc1_1, strcspn_5);
  tcase_add_test(tc1_1, strcspn_6);
  tcase_add_test(tc1_1, strcspn_7);
  tcase_add_test(tc1_1, strcspn_8);
  tcase_add_test(tc1_1, strcspn_9);
  tcase_add_test(tc1_1, strcspn_10);
  tcase_add_test(tc1_1, strcspn_11);
  tcase_add_test(tc1_1, strcspn_12);

  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, strrchr_1);
  tcase_add_test(tc1_1, strrchr_2);
  tcase_add_test(tc1_1, strrchr_3);
  tcase_add_test(tc1_1, strrchr_4);
  tcase_add_test(tc1_1, strrchr_5);
  tcase_add_test(tc1_1, strrchr_6);
  tcase_add_test(tc1_1, strrchr_7);
  tcase_add_test(tc1_1, strrchr_8);

  // tcase_add_test(tc1_1, s21_strerror_test);
  tcase_add_test(tc1_1, strerror_1);
  tcase_add_test(tc1_1, strerror_2);

  tcase_add_test(tc1_1, s21_memmove_test);
  tcase_add_test(tc1_1, memmove_1);
  tcase_add_test(tc1_1, memmove_2);
  tcase_add_test(tc1_1, memmove_3);
  tcase_add_test(tc1_1, memmove_4);
  tcase_add_test(tc1_1, memmove_5);
  tcase_add_test(tc1_1, memmove_6);
  tcase_add_test(tc1_1, memmove_7);
  tcase_add_test(tc1_1, memmove_8);
  tcase_add_test(tc1_1, memmove_9);
  tcase_add_test(tc1_1, memmove_10);

  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, strchr_1);
  tcase_add_test(tc1_1, strchr_2);
  tcase_add_test(tc1_1, strchr_3);
  tcase_add_test(tc1_1, strchr_4);
  tcase_add_test(tc1_1, strchr_5);
  tcase_add_test(tc1_1, strchr_6);
  tcase_add_test(tc1_1, strchr_7);
  tcase_add_test(tc1_1, strchr_8);

  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, strncpy_1);
  tcase_add_test(tc1_1, strncpy_2);
  tcase_add_test(tc1_1, strncpy_3);
  tcase_add_test(tc1_1, strncpy_4);
  tcase_add_test(tc1_1, strncpy_5);
  tcase_add_test(tc1_1, strncpy_6);

  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, strpbrk_1);
  tcase_add_test(tc1_1, strpbrk_2);
  tcase_add_test(tc1_1, strpbrk_3);
  tcase_add_test(tc1_1, strpbrk_4);
  tcase_add_test(tc1_1, strpbrk_5);
  tcase_add_test(tc1_1, strpbrk_6);

  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, strtok_1);
  tcase_add_test(tc1_1, strtok_2);
  tcase_add_test(tc1_1, strtok_3);
  tcase_add_test(tc1_1, strtok_4);
  tcase_add_test(tc1_1, strtok_5);
  tcase_add_test(tc1_1, strtok_6);
  tcase_add_test(tc1_1, strtok_7);
  tcase_add_test(tc1_1, strtok_8);
  tcase_add_test(tc1_1, strtok_9);
  tcase_add_test(tc1_1, strtok_10);
  // tcase_add_test(tc1_1, strtok_11);
  tcase_add_test(tc1_1, strtok_12);
  tcase_add_test(tc1_1, strtok_13);
  tcase_add_test(tc1_1, strtok_14);
  tcase_add_test(tc1_1, strtok_15);
  tcase_add_test(tc1_1, strtok_16);
  tcase_add_test(tc1_1, strtok_17);
  tcase_add_test(tc1_1, strtok_18);
  tcase_add_test(tc1_1, strtok_19);
  tcase_add_test(tc1_1, strtok_20);

  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, strncmp_1);
  tcase_add_test(tc1_1, strncmp_2);
  tcase_add_test(tc1_1, strncmp_3);
  tcase_add_test(tc1_1, strncmp_4);
  tcase_add_test(tc1_1, strncmp_5);
  tcase_add_test(tc1_1, strncmp_6);
  tcase_add_test(tc1_1, strncmp_7);
  tcase_add_test(tc1_1, strncmp_8);
  tcase_add_test(tc1_1, strncmp_9);

  tcase_add_test(tc1_1, s21_strspn_test);
  tcase_add_test(tc1_1, strspn_1);
  tcase_add_test(tc1_1, strspn_2);
  tcase_add_test(tc1_1, strspn_3);
  tcase_add_test(tc1_1, strspn_4);
  tcase_add_test(tc1_1, strspn_5);
  tcase_add_test(tc1_1, strspn_6);
  tcase_add_test(tc1_1, strspn_7);
  tcase_add_test(tc1_1, strspn_8);
  tcase_add_test(tc1_1, strspn_9);
  tcase_add_test(tc1_1, strspn_10);
  tcase_add_test(tc1_1, strspn_11);
  tcase_add_test(tc1_1, strspn_12);

  tcase_add_test(tc1_1, s21_strcat_test);
  tcase_add_test(tc1_1, strcat_1);
  tcase_add_test(tc1_1, strcat_2);
  tcase_add_test(tc1_1, strcat_3);
  tcase_add_test(tc1_1, strcat_4);
  tcase_add_test(tc1_1, strcat_5);
  tcase_add_test(tc1_1, strcat_6);
  tcase_add_test(tc1_1, strcat_7);
  tcase_add_test(tc1_1, strcat_8);
  tcase_add_test(tc1_1, strcat_9);
  tcase_add_test(tc1_1, strcat_10);

  // tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, test_to_upper_1);
  tcase_add_test(tc1_1, test_to_upper_2);
  tcase_add_test(tc1_1, test_to_upper_3);
  tcase_add_test(tc1_1, test_to_upper_4);
  tcase_add_test(tc1_1, test_to_upper_5);
  tcase_add_test(tc1_1, test_to_upper_6);
  tcase_add_test(tc1_1, test_to_upper_7);

  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, test_to_lower_1);
  tcase_add_test(tc1_1, test_to_lower_2);
  tcase_add_test(tc1_1, test_to_lower_3);
  tcase_add_test(tc1_1, test_to_lower_4);
  tcase_add_test(tc1_1, test_to_lower_5);
  tcase_add_test(tc1_1, test_to_lower_6);
  tcase_add_test(tc1_1, test_to_lower_7);

  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);

  tcase_add_test(tc1_1, s21_sprintf_o_test);
  tcase_add_test(tc1_1, s21_sprintf_f_test);
  // tcase_add_test(tc1_1, s21_sprintf_g_test);
  tcase_add_test(tc1_1, s21_sprintf_prc_test);
  tcase_add_test(tc1_1, s21_sprintf_n_test);
  // tcase_add_test(tc1_1, s21_sprintf_f_g_n_prc_test);
  tcase_add_test(tc1_1, s21_sprintf_test);
  // tcase_add_test(tc1_1, s21_sprintf_e_test);
  tcase_add_test(tc1_1, s21_sprintf_p_test);
  tcase_add_test(tc1_1, s21_sprintf_o_test);
  tcase_add_test(tc1_1, s21_sprintf_x_X_test);
  tcase_add_test(tc1_1, s21_sprintf_c_test);
  tcase_add_test(tc1_1, s21_sprintf_s_test);
  tcase_add_test(tc1_1, s21_sprintf_u_test);
  tcase_add_test(tc1_1, s21_sprintf_d_test);
  tcase_add_test(tc1_1, s21_sprintf_d_test_2);
  tcase_add_test(tc1_1, s21_sprintf_d_test_3);
  tcase_add_test(tc1_1, s21_sprintf_d_test_4);
  tcase_add_test(tc1_1, s21_sprintf_d_test_5);
  tcase_add_test(tc1_1, s21_sprintf_d_test_6);
  tcase_add_test(tc1_1, s21_sprintf_d_test_0);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  printf("\nHAND TESTER:\n\n");

  // char test_1[] = "<<<5>>>";
  // char test_2[] = "5";
  // char test_3[] = "QwertyQwertyQwerty";
  // char test_4[] = "Qwerty";
  // char test_5[] = "abcd";
  // char test_6[] = "";
  // char test_7[] = "aaaaa123aaa1234aaa";
  // char test_8[] = "1234";
  // //s21_strstr(test_5, test_6), strstr(test_5, test_6)
  // printf("ORIGINAL: %s\nS21: %s", strstr(test_5, test_6), s21_strstr(test_5,
  // test_6));

  // char test1[] = "0163456769";
  // char test2[] = ";;;;;;H%%//#HH";
  // char test3[] = "     /";

  // printf("ORIGINAL: %s\nS21: %s", s21_strrchr(test1, '6'), strrchr(test1,
  // '6'));
  //   char str3[] = "Abcdefg";
  //   int symbol3 = '\0';
  //   char *ach3 = s21_strchr(str3, symbol3);
  //   char str4[] = "Abcdefg";
  //   int symbol4 = '\0';
  //   char *ach4 = strchr(str4, symbol4);
  // printf("ORIGINAL: %s\nS21: %s", ach3, ach4);
  // char str1[] = "test of string";
  //   char dest1[15] = "";

  //   char str2[] = "test\0";
  //   char dest2[5] = "";

  //   char str3[] = "test ";
  //   char dest3[] = "crushcrush";

  // printf("ORIGINAL: \n%s-\nS21: \n%s-", strncpy(dest3, str3, 10),
  // s21_strncpy(dest3, str3, 10));

  printf("\n\nEND TESTER.\n\n");
  return nf == 0 ? 0 : 1;
}