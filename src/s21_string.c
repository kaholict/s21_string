#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  void *result = s21_NULL;
  if (n >= s21_strlen(str)) n = s21_strlen(str);
  for (s21_size_t i = 0; i < n; i++) {
    if (*((char *)str + i) == c) {
      result = (char *)str + i;
      break;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; i++)
    if (*((char *)str1 + i) != *((char *)str2 + i)) {
      result = *((char *)str1 + i) - *((char *)str2 + i);
      break;
    }
  return result;
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
    for (i = 0; i < n; i++) *(temp + i) = *(src_char + i);
    for (i = 0; i < n; i++) *(dest_char + i) = *(temp + i);
    free(temp);
  }
  return dest;
}

void *s21_memset(void *str, int c, size_t n) {
  for (s21_size_t i = 0; i < n; i++) *((char *)str + i) = c;
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
  for (s21_size_t i = len_dest; i < n + len_dest; i++) *(dest + i) = *src++;
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str); i++)
    if (*(str + i) == c) {
      result = (char *)str + i;
      break;
    }
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  if (len1 == len2) {
    for (s21_size_t i = 0; i < len1; i++)
      if (*((char *)str1 + i) != *((char *)str2 + i)) {
        result = *((char *)str1 + i) - *((char *)str2 + i);
        break;
      }
  } else {
    if (len1 < len2)
      result = *((char *)str1 + len1 + 1);
    else
      result = *((char *)str2 + len2 + 1);
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n; i++)
    if (*((char *)str1 + i) != *((char *)str2 + i)) {
      result = *((char *)str1 + i) - *((char *)str2 + i);
      break;
    }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *result = s21_NULL;
  if (dest != s21_NULL) {
    result = dest;
    while (*src != '\0') *dest++ = *src++;
    *dest = '\0';
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *result = s21_NULL;
  if (dest != s21_NULL) {
    result = dest;
    while (--n) *dest++ = *src++;
    *dest = '\0';
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    int flag = 1;
    while (*str1 && flag) {
      if (s21_strchr(str2, *str1) == NULL) {
        str1++;
        result++;
      } else
        flag = 0;
    }
  }
  return result;
}

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};
  if (errnum <= MIN_ERRNUM || errnum >= MAX_ERRNUM) {
    s21_strcpy(result, "Unknown error");
  } else {
    s21_strcpy(result, ((char *)errorList[errnum]));
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') i++;
  return i;
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


