#include <stdio.h>   // Для printf
#include <string.h>  // Для strchr
typedef long unsigned s21_size_t;
#define s21_NULL ((void *)0)

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

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    int flag = 1;
    while (*str1 && flag) {
      if (s21_strchr(str2, *str1)) {
        flag = 0;
        result = (char *)str1;
      } else
        str1++;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  if (str != s21_NULL) {
    while (*str) {
      if (*str == c) {
        result = (char *)str;
      }
      str++;
    }
  }
  return result;
}

size_t s21_strspn(const char *str1, const char *str2) {
  size_t result = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    int flag = 1;
    while (*str1 && flag) {
      if (s21_strchr(str2, *str1) == NULL) {
        str1++;
      } else {
        int flag2 = 1;
        while (*str1 && flag2) {
          if (s21_strchr(str2, *str1)) {
            str1++;
            result++;
          } else
            flag2 = 0;
        }
        flag = 0;
      }
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len = s21_strlen(needle);
  char *result = s21_NULL;
  if (haystack != s21_NULL && needle != s21_NULL) {
    int flag = 1;
    while (*haystack != '\0' && flag) {
      if (*haystack == *needle) {
        s21_size_t counter = 0;
        char *temp = (char *)haystack;
        while (*haystack == *needle && *needle != '\0') {
          counter++;
          haystack++;
          needle++;
        }
        if (counter == len) {
          result = (char *)temp;
          flag = 0;
        }
      }
      haystack++;
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  char *result = s21_NULL;
  static char *newGen;
  if (!str) str = newGen;
  if (str) {
    while (1) {
      if (s21_strchr(delim, *str)) {
        str++;
        continue;
      }
      break;
    }
    if (*str != '\0') {
      result = str;
      while (1) {
        if (*str == '\0') {
          newGen = str;
          break;
        } else if (s21_strchr(delim, *str)) {
          *str = '\0';
          newGen = str + 1;
          break;
        }
        str++;
      }
    }
  }
  return result;
}

int main() {
  // Массив со строкой для поиска
  char str[24] = "test1/test2/test3/test4";
  char s21_str[24] = "test1/test2/test3/test4";
  // Набор символов, которые должны входить в искомый сегмент
  char sep[10] = "/";
  // Переменная, в которую будут заноситься начальные адреса частей
  // строки str
  char *istr;
  char *s21_istr;

  printf("Исходная строка: %s\n", str);
  printf("Результат разбиения:\n");
  // Выделение первой части строки
  istr = strtok(str, sep);
  s21_istr = s21_strtok(s21_str, sep);

  // Выделение последующих частей
  while (istr != NULL) {
    // Вывод очередной выделенной части
    printf("%s\n", istr);
    // Выделение очередной части строки
    istr = strtok(NULL, sep);
  }

  while (s21_istr != NULL) {
    // Вывод очередной выделенной части
    printf("%s\n", s21_istr);
    // Выделение очередной части строки
    s21_istr = s21_strtok(NULL, sep);
  }

  return 0;
}
