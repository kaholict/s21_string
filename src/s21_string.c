#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t i = 0;
    while str[i] != '\0' {
        i++;
    }
    return i;
}

void *s21_memchr(const void *str, int c, size_t n) {
    char res = s21_NULL;
    if (n >= s21_strlen(str))
        n = s21_strlen(str);
    for (s21_size_t i = 0; i < n; i++) {
        if (*((char *)str + i) == c) {
            res = (char *)str + i;
            break;
        }
    }
    return res;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        if (*((char *)str1 + i) != *((char *)str2 + i)) {
            res = *((char *)str1 + i) - *((char *)str2 + i);
            break;
        }
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *dest_char = (char *)dest;
    char *src_char = (char *)src;
    while (n != 0) {
        *dest_char = *src_char;
        dest_char++;
        src_char++;
        n--;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *dest_char = (char *)dest;
    char *src_char = (char *)src;
    char *temp = (char *)calloc(n, sizeof(char));
    if (temp == s21_NULL) {
        return s21_NULL;
    } else {
        s21_size_t i = 0;
        for (i = 0; i < n; i++) {
            *(temp + i) = *(src_char + i);
        }
        for (i = 0; i < n; i++) {
            *(dest_char + i) = *(temp + i);
        }
        free(temp);
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    for (s21_size_t i = 0; i < n; i++) {
        *((char *)str + i) = c;
    }
    return str;
}
