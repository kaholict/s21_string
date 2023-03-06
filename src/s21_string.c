#include "s21_string.h"

#ifdef __APPLE__
#define MAX_ERRNUM 107
#define MIN_ERRNUM -1
#define ERROR "Unknown error: "
static const char *errorList[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};
#endif

#ifdef __linux__
#define MAX_ERRNUM 134
#define MIN_ERRNUM -1
#define ERROR "Unknown error "

static const char *errorList[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

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
  char *a = dest + s21_strlen(dest);
  while (*src && n--) *a++ = *src++;
  *a = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  int flag = 1;
  for (s21_size_t i = 0; i < s21_strlen(str) && flag; i++)
    if (*(str + i) == c) {
      result = (char *)str + i;
      flag = 0;
    }
  if (c == '\0') result = (char *)(str + (int)s21_strlen(str));
  return result;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  for (s21_size_t i = 0; *str1 && *str1 == *str2 && i < n; str1++, str2++, i++)
    ;
  int res = n <= 0 ? 0 : *str1 - *str2;
  return res;
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

char *s21_strncpy(char *dest, const char *src, s21_size_t len) {
  s21_size_t size = (s21_strlen(src) >= len) ? len : s21_strlen(src);
  if (size != len) s21_memset(dest + size, '\0', len - size);
  return s21_memcpy(dest, src, size);
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
    char temp[1024] = {'\0'};
#ifdef __APPLE__
    s21_sprintf(temp, "Unknown error: %d", errnum);
#endif
#ifdef __linux__
    s21_sprintf(temp, "Unknown error %d", errnum);
#endif
    s21_strcpy(result, temp);
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
  if (str != s21_NULL)
    while (*str++)
      if (*str == c) result = (char *)str;
  if (result == s21_NULL && c == '\0') result = (char *)str;
  return result;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t result = 0;
  int countStart = 0;
  int flag = 0;
  do {
    if (s21_strchr(str2, *str1) && *str1 != '\0') {
      if (flag == 0 && countStart != 0) {
        break;
      } else {
        result++;
        flag = 1;
      }
    } else {
      flag = 0;
    }
    countStart++;
  } while (*str1++);
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  size_t len = s21_strlen(needle);
  char *result = s21_NULL;
  char *temp_end = (char *)haystack;
  char *temp_needle = s21_NULL;
  char *temp = s21_NULL;
  if (haystack != s21_NULL && needle != s21_NULL) {
    if (needle[0] == '\0') {
      result = temp_end;
    } else {
      int flag = 1;
      while (*haystack != '\0' && flag) {
        int new_flag = 1;
        temp_needle = (char *)needle;
        if (*haystack == *temp_needle) {
          size_t counter = 0;
          temp = (char *)haystack;
          while (*haystack == *temp_needle && *temp_needle != '\0') {
            counter++;
            haystack++;
            temp_needle++;
            new_flag = 0;
          }
          if (counter == len) {
            result = (char *)temp;
            flag = 0;
          }
        }
        if (flag && new_flag) haystack++;
      }
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  char *result = s21_NULL;
  static char *newGen;
  if (!str) {
    str = newGen;
  }
  if (str) {
    while (1) {
      if (s21_strchr(delim, *str) && *str != '\0') {
        str++;
        continue;
      }
      if (*str == '\0') {
        return s21_NULL;
      }
      break;
    }
    result = str;
    while (1) {
      if (*str == '\0') {
        newGen = str;
        break;
      } else if (s21_strchr(delim, *str) && *str != '\0') {
        *str = '\0';
        newGen = str + 1;
        break;
      }
      str++;
    }
  }
  return result;
}

void *s21_to_upper(const char *str) {
  char *str_up = s21_NULL;
  if (str) {
    s21_size_t len = s21_strlen(str);
    str_up = (char *)calloc(len + 1, sizeof(char));
    if (str_up) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
          str_up[i] = (str[i] - 'a') + 'A';
        else
          str_up[i] = str[i];
      }
      str_up[len] = '\0';
    }
  }
  return str_up;
}

void *s21_to_lower(const char *str) {
  char *str_up = s21_NULL;
  if (str) {
    s21_size_t len = s21_strlen(str);
    str_up = (char *)calloc(len + 1, sizeof(char));
    if (str_up) {
      for (s21_size_t i = 0; i <= len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
          str_up[i] = (str[i] - 'A') + 'a';
        else
          str_up[i] = str[i];
      }
      str_up[len] = '\0';
    }
  }
  return str_up;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *ptr = s21_NULL;
  if (src != s21_NULL && str != NULL) {
    s21_size_t length_src = s21_strlen(src);
    if (start_index <= length_src) {
      s21_size_t length_str = s21_strlen(str);
      ptr = calloc(length_src + length_str + 1, sizeof(char));
      if (ptr) {
        s21_strcpy(ptr, src);
        s21_strcpy(ptr + start_index, str);
        s21_strcpy(ptr + start_index + length_str, src + start_index);
      }
    }
  }
  return ptr;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;
  if (src != s21_NULL) {
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) trim_chars = " ";
    int res_len = s21_strlen(src) + 1;
    res = (char *)calloc(res_len, sizeof(char));
    if (res != s21_NULL) {
      int len_chars = s21_strspn(src, trim_chars);
      const char *temp = src + len_chars;
      s21_strcpy(res, temp);
      int str_len = s21_strlen(res);
      if (str_len > 0) {
        res += str_len - 1;
        int i = 1;
        while (s21_strpbrk(res, trim_chars) != s21_NULL) {
          (*res) = '\0';
          if (i < str_len) res--;
          ++i;
        }
        int res_len = str_len - i;
        res -= res_len;
      }
    }
  }
  return res;
}

void Specifier_c(StructFormat my_struct, va_list arguments, char *str,
                 int *count) {
  char c = va_arg(arguments, int);
  char temp_str[2] = {'\0'};
  temp_str[0] = c;
  if (my_struct.flagMinus == -1) {
    space_record(my_struct, str, temp_str, 1, count);
    str[(*count)++] = temp_str[0];
  } else {
    str[(*count)++] = temp_str[0];
    space_record(my_struct, str, temp_str, 1, count);
  }
  str[(*count)] = '\0';
}

void Specifier_di(StructFormat my_struct, va_list arguments, char *str,
                  int *count) {
  long long int d = va_arg(arguments, long long int);
  if (my_struct.length == 1)
    d = (short int)d;
  else if (my_struct.length == 3)
    d = (long int)d;
  else
    d = (int)d;
  int check = 1;  // cyber crutch
  if (d == 0 && my_struct.accuracy == 0) check = 0;
  char temp_str[1024] = {'\0'};
  int sign = 1;
  if (d < 0) {
    sign = -1;
    d = -d;
  }
  int i = 0;
  while (d > 9) {
    temp_str[i] = d % 10 + '0';
    d /= 10;
    i++;
  }
  if (check) temp_str[i++] = d % 10 + '0';
  while (i < my_struct.accuracy) temp_str[i++] = '0';
  if (sign == -1) temp_str[i++] = '-';
  line_reversal(temp_str);
  record_to_string(my_struct, str, temp_str, sign, count);
}

void Specifier_double(StructFormat my_struct, va_list arguments, char *str,
                      int *count) {
  long double f = 0.0;
  char temp_str[1024] = {'\0'};
  if (my_struct.length == 5)
    f = va_arg(arguments, long double);
  else
    f = va_arg(arguments, double);
  double_to_string(f, temp_str, my_struct.accuracy);
  record_to_string(my_struct, str, temp_str, (f >= 0) ? 1 : -1, count);
}

void Specifier_string(StructFormat my_struct, va_list arguments, char *str,
                      int *count) {
  char *temp_str = va_arg(arguments, char *);
  if (my_struct.accuracy != -1) {
    char temp[1024] = {'\0'};
    for (int i = 0; i < my_struct.accuracy && i < (int)s21_strlen(temp_str);
         i++)
      temp[i] = temp_str[i];
    record_to_string(my_struct, str, temp, 1, count);
  }
  if (my_struct.accuracy == -1 && my_struct.Error != 1)
    record_to_string(my_struct, str, temp_str, 1, count);
}

void Specifier_nusigned_int(StructFormat my_struct, va_list arguments,
                            char *str, int *count) {  // не работает
  unsigned long long d = 0;
  if (my_struct.length == 1) {
    d = va_arg(arguments, unsigned int);
    d = (unsigned short)d;
  } else if (my_struct.length == 3) {
    d = va_arg(arguments, unsigned long int);
  } else if (my_struct.length == 3) {
    d = va_arg(arguments, unsigned long long int);
  } else {
    d = va_arg(arguments, unsigned int);
  }
  char temp_str[1024] = {'\0'};
  number_to_string(d, temp_str, 10);
  int i = s21_strlen(temp_str);
  while (i < my_struct.accuracy) temp_str[i++] = '0';
  line_reversal(temp_str);
  record_to_string(my_struct, str, temp_str, 1, count);
}

void Specifier_persent(StructFormat my_struct, char *str, int *count) {
  char temp_str[2] = {'\0'};
  temp_str[0] = '%';
  record_to_string(my_struct, str, temp_str, 1, count);
  str[(*count)] = '\0';
}

void Specifier_n(va_list arguments, char *str, int *count) {
  int *n = va_arg(arguments, int *);
  *n = *count;
  str[(*count)] = '\0';
}

void Specifier_octal(StructFormat my_struct, va_list arguments, char *str,
                     int *count) {
  long long int d = va_arg(arguments, long long int);
  if (my_struct.length == 1)
    d = (short int)d;
  else if (my_struct.length == 3)
    d = (long int)d;
  else
    d = (int)d;
  char temp_str[1024] = {'\0'};
  number_to_string(d, temp_str, 8);
  int i = s21_strlen(temp_str);
  if (my_struct.flagReshotca == 1 && d != 0) temp_str[i++] = '0';
  while (i < my_struct.accuracy) temp_str[i++] = '0';
  line_reversal(temp_str);
  record_to_string(my_struct, str, temp_str, 1, count);
}

void Specifier_hex_pointer(StructFormat my_struct, va_list arguments, char *str,
                           int *count) {
  unsigned long d = 0;
  int reg = (my_struct.option == 'x') ? 1 : 0;
  if (my_struct.length == 5 || my_struct.option == 'p') {
    d = va_arg(arguments, unsigned long);
    reg = 1;
  } else if (my_struct.length == 1) {
    d = va_arg(arguments, int);
    d = (unsigned short)d;
  } else if (my_struct.length == 3) {
    d = va_arg(arguments, unsigned long);
  } else
    d = va_arg(arguments, unsigned);
  char temp_str[1024] = {'\0'};
  int i = 0;
  while (d > 15) {
    ;
    temp_str[i] = hex_fitting(d, reg);
    d /= 16;
    i++;
    temp_str[i] = '\0';
  }
  temp_str[i++] = hex_fitting(d, reg);
  if (my_struct.option == 'p') {
    temp_str[i++] = 'x';
    temp_str[i++] = '0';
    line_reversal(temp_str);
    temp_str[i] = '\0';
  } else {
    while (i < my_struct.accuracy) temp_str[i++] = '0';
    if (my_struct.flagReshotca == 1 && d != 0) {
      temp_str[i++] = (reg) ? 'x' : 'X';
      temp_str[i++] = '0';
    }
    temp_str[i] = '\0';
    line_reversal(temp_str);
  }
  record_to_string(my_struct, str, temp_str, 1, count);
}

void record_to_string(StructFormat my_struct, char *str, char *temp_string,
                      int sign, int *count) {
  if (my_struct.flagMinus == -1) {
    space_record(my_struct, str, temp_string, sign, count);
    flags_symb_record(my_struct, str, temp_string, sign, count);
  } else {
    flags_symb_record(my_struct, str, temp_string, sign, count);
    space_record(my_struct, str, temp_string, sign, count);
  }
  str[(*count)] = '\0';
}

void space_record(StructFormat my_struct, char *str, char *temp_string,
                  int sign, int *count) {
  if (my_struct.width > (int)s21_strlen(temp_string)) {
    int rasstoyanie = my_struct.width - (int)s21_strlen(temp_string);
    if ((my_struct.flagSpace == 1 || my_struct.flagPlus == 1) && sign == 1)
      rasstoyanie--;
    for (int j = 0; j < rasstoyanie; j++) str[(*count)++] = ' ';
  }
}

void flags_symb_record(StructFormat my_struct, char *str, char *temp_string,
                       int sign, int *count) {
  if (s21_strchr("dieEfgG", (int)my_struct.option) != s21_NULL) {
    if (my_struct.flagSpace == 1 && my_struct.flagPlus == -1 && sign == 1)
      str[(*count)++] = ' ';
    if (my_struct.flagPlus == 1 && sign == 1) str[(*count)++] = '+';
  }
  for (s21_size_t l = 0; l < s21_strlen(temp_string); l++)
    str[(*count)++] = temp_string[l];
}

void Specifiers(StructFormat my_struct, va_list arguments, char *str,
                int *count) {
  switch (my_struct.option) {
    case 'c':  // начало обязаловки
      Specifier_c(my_struct, arguments, str, count);
      break;
    case 'd':
    case 'i':
      Specifier_di(my_struct, arguments, str, count);
      break;
    case 'f':
      Specifier_double(my_struct, arguments, str, count);
      break;
    case 's':
      Specifier_string(my_struct, arguments, str, count);
      break;
    case 'u':
      Specifier_nusigned_int(my_struct, arguments, str, count);
      break;
    case '%':
      Specifier_persent(my_struct, str, count);
      break;  // конец обязаловки
    case 'n':
      Specifier_n(arguments, str, count);
      break;
    case 'o':
      Specifier_octal(my_struct, arguments, str, count);
      break;
    case 'x':
    case 'X':
    case 'p':
      Specifier_hex_pointer(my_struct, arguments, str, count);
      break;
    default:
      break;
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  va_list arguments = {0};
  va_start(arguments, format);
  int start = 0;
  int end = 0;
  int count = 0;
  StructFormat my_struct = {-1, -1, -1, -1, -1, -1, -1, '$', 0};
  char temp[1024] = {'\0'};
  char *format_copy = s21_strcpy(temp, format);
  while (format_copy[start] != '\0') {
    if (format_copy[start] != '%') {
      str[count++] = format_copy[start++];
      str[count] = '\0';
    } else {
      unit_format(format_copy, &start, &end, &my_struct);
      my_struct = parserformat(start, end, format_copy);
      if (format[start + 1] == '%') {
        end = start + 1;
        my_struct.option = '%';
      }
      start = end + 1;
      Specifiers(my_struct, arguments, str, &count);
    }
  }
  va_end(arguments);
  return count;
}

void double_to_string(long double f, char *temp_str, int accuracy) {
  if (accuracy == -1) accuracy = 6;
  int sign = 1;
  if (f < 0) {
    f = -f;
    sign = -1;
  }
  long double integer = 0.0, fraction = 0.0;
  fraction = modfl(f, &integer);
  number_to_string(integer, temp_str, 10);
  if (sign == -1) temp_str[s21_strlen(temp_str)] = '-';
  line_reversal(temp_str);
  if (accuracy != 0) temp_str[s21_strlen(temp_str)] = '.';
  int i = 0;
  while (i < accuracy) {
    fraction *= 10.0;
    i++;
  }
  fraction = round(fraction);
  char temp[512] = {'\0'};
  number_to_string(fraction, temp, 10);
  line_reversal(temp);
  i = s21_strlen(temp) - 1;
  int lenght = s21_strlen(temp_str);
  i = 0;
  while (i < accuracy - (int)s21_strlen(temp)) temp_str[lenght + i++] = '0';
  s21_strcat(temp_str, temp);
  temp_str[accuracy + lenght] = '\0';
}

void number_to_string(long int integer, char *temp_str, int base) {
  int i = 0;
  while (integer > base - 1) {
    temp_str[i++] = (long int)integer % base + '0';
    integer /= base;
  }
  temp_str[i++] = (long int)integer % base + '0';
}

int hex_fitting(unsigned long long prototype, int reg) {
  prototype %= 16;
  int integer = prototype + '0';
  if (prototype == 10) integer = (reg) ? 'a' : 'A';  // 97 - 65
  if (prototype == 11) integer = (reg) ? 'b' : 'B';  // 98 - 66
  if (prototype == 12) integer = (reg) ? 'c' : 'C';  // 99 - 67
  if (prototype == 13) integer = (reg) ? 'd' : 'D';  // 100 - 68
  if (prototype == 14) integer = (reg) ? 'e' : 'E';  // 101 - 69
  if (prototype == 15) integer = (reg) ? 'f' : 'F';  // 102 - 70
  return integer;
}

void line_reversal(char *str) {
  char temp = '\0';
  int i = 0, lenght = s21_strlen(str);
  for (i = 0; i < (lenght) / 2; i++) {
    temp = str[i];
    str[i] = str[lenght - i - 1];
    str[lenght - i - 1] = temp;
  }
}

int func_to_parse_num(char *format, int counter, int point_position,
                      StructFormat *my_struct) {
  float rang = 1;
  float result = 0;
  int len_res = 0;
  if ('0' <= format[counter] && format[counter] <= '9') {
    while ('0' <= format[counter] && format[counter] <= '9') {
      rang = rang / 10;
      result = result + rang * ((int)format[counter] - 48);
      counter++;
      len_res++;
    }
    counter--;
    while (len_res) {
      result = result * 10;
      len_res--;
    }
    if (counter > point_position) {
      my_struct->accuracy = (int)result;
    } else
      my_struct->width = (int)result;
  } else
    my_struct->Error = 1;
  return counter;
}

void func_to_parse_len(char *str, int counter, char *first_length,
                       StructFormat *my_struct, int last_ind) {
  if (counter == last_ind - 2)
    *first_length = str[counter];
  else {
    if (str[counter] == 'h') {
      if (*first_length == 'h')
        my_struct->length = 2;
      else
        my_struct->length = 1;
    }
    if (str[counter] == 'l') {
      if (*first_length == 'l')
        my_struct->length = 4;
      else
        my_struct->length = 3;
    }
    if (str[counter] == 'L') my_struct->length = 5;
    *first_length = '$';
  }
}
// 1   h
// 2   hh
// 3   l
// 4   ll
// 5   L
StructFormat parserformat(int start, int end, char *format) {
  StructFormat my_struct = {-1, -1, -1, -1, -1, -1, -1, '$', 0};
  int last_ind = end;
  if (last_ind >= 1) {
    int counter = start + 1;
    int point_position = 1025;
    char first_length = '$';
    my_struct.option = format[last_ind];
    while (counter != last_ind && !my_struct.Error) {
      switch (format[counter]) {
        case '-':
          my_struct.flagMinus = 1;
          break;
        case '+':
          my_struct.flagPlus = 1;
          break;
        case ' ':
          my_struct.flagSpace = 1;
          break;
        case '#':
          my_struct.flagReshotca = 1;
          break;
        case 'h':
          func_to_parse_len(format, counter, &first_length, &my_struct,
                            last_ind);
          break;
        case 'l':
          func_to_parse_len(format, counter, &first_length, &my_struct,
                            last_ind);
          break;
        case 'L':
          func_to_parse_len(format, counter, &first_length, &my_struct,
                            last_ind);
          break;
        case '.':
          point_position = counter;
          if (s21_strchr("cdifsunoxXp", format[counter + 1]) != s21_NULL)
            my_struct.accuracy = 0;
          if ('0' > format[counter + 1] || format[counter + 1] > '9')
            my_struct.Error = 1;
          break;
        default:
          counter =
              func_to_parse_num(format, counter, point_position, &my_struct);
          break;
      }
      counter++;
    }
    if (point_position != 1025 && my_struct.accuracy == -1) my_struct.Error = 1;
  }
  return my_struct;
}

void unit_format(char *format, int *start, int *end, StructFormat *my_struct) {
  if (format[*start + 1] != '%') {
    *end = *start;
    while (format[*end] != '\0' &&
           (s21_strchr("cdifsunoxXp", format[*end]) == s21_NULL))
      (*end)++;
    if (format[*end] == '\0') my_struct->Error = 1;
  }
}
