#include <stdio.h>  // Для printf
#include <string.h> // Для strchr
typedef long unsigned s21_size_t;
#define s21_NULL ((void*)0)

s21_size_t s21_strlen(const char *str) {
    s21_size_t i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *s21_strchr(const char *str, int c) {
    char *ach = s21_NULL;
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
        if (*(str + i) == c) {
            ach = (char *)str + i;
            break;
        }
    }
    return ach;
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

int main() {
    char str [10] = "0123456789";
    // Набор символов, которые не должны входить в искомый сегмент
    char sym [10] = "9876";

    // Определяем длину начального сегмента, не содержащего символы “9876”
    printf ("Длина сегмента: %ld\n",s21_strcspn (str,sym));

    return 0;
}
