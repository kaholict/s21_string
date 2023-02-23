#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

void *s21_memchr(const void *str, int c, size_t n) {
    char res = s21_NULL;
    if (n >= s21_strlen(str))
        n = s21_strlen(str);
    for (s21_size_t i = 0; i < n; i++)
        if (*((char *)str + i) == c) {
            res = (char *)str + i;
            break;
        }
    return res;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n; i++)
        if (*((char *)str1 + i) != *((char *)str2 + i)) {
            res = *((char *)str1 + i) - *((char *)str2 + i);
            break;
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
    if (temp == s21_NULL)
        return s21_NULL;
    else {
        s21_size_t i = 0;
        for (i = 0; i < n; i++)
            *(temp + i) = *(src_char + i);
        for (i = 0; i < n; i++)
            *(dest_char + i) = *(temp + i);
        free(temp);
    }
    return dest;
}

void *s21_memset(void *str, int c, size_t n) {
    for (s21_size_t i = 0; i < n; i++)
        *((char *)str + i) = c;
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_dest = s21_strlen(dest);
    for (s21_size_t i = len_dest; i < len_src + len_dest; i++)
        *(dest + i) = *src++;
    *(dest + len_src + len_dest) = '\0';
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_size_t len_dest = s21_strlen(dest);
    for (s21_size_t i = len_dest; i < n + len_dest; i++)
        *(dest + i) = *src++;
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *res = s21_NULL;
    for (s21_size_t i = 0; i < s21_strlen(str); i++)
        if (*(str + i) == c) {
            res = (char *)str + i;
            break;
        }
    return res;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
    s21_size_t len1 = s21_strlen(str1);
    s21_size_t len2 = s21_strlen(str2);
    if (len1 == len2)
        for (s21_size_t i = 0; i < len1; i++)
            if (*((char *)str1 + i) != *((char *)str2 + i)) {
                res = *((char *)str1 + i) - *((char *)str2 + i);
                break;
            }
    else {
        if (len1 < len2)
            res = *((char *)str1 + len1 + 1);
        else
            res = *((char *)str2 + len2 + 1);
    }
    return res;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n; i++)
        if (*((char *)str1 + i) != *((char *)str2 + i)) {
            res = *((char *)str1 + i) - *((char *)str2 + i);
            break;
        }
    return res;
}

char *s21_strcpy(char *dest, const char *src) {
    char *res = s21_NULL;
    if (dest != s21_NULL) {
        res = dest;
        while (*src != '\0')
            *dest++ = *src++;
        *dest = '\0';
    }
    return res;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
    char *res = s21_NULL;
    if (dest != s21_NULL) {
        res = dest;
        while (--n)
            *dest++ = *src++;
        *dest = '\0';
    }
    return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t res = 0;
    if (str1 != s21_NULL && str2 != s21_NULL) {
        int flag = 1;
        while (*str1 && flag) {
            if (s21_strchr(str2, *str1) == NULL) {
                str1++;
                res++;
            }
            else
                flag = 0;
        }
    }
    return res;
}

