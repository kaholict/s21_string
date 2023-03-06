CC = gcc
# CFLAGS = -c -Wall -Werror -Wextra
CFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
TEST_LIBS = -lcheck -lm
SOURCE = $(wildcard *.c)
HEADER = s21_string.h
OBJ := $(patsubst %.c, %.o, $(SOURCE))
OS = $(shell uname)

ifeq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lm
else
	TEST_LIBS = -lcheck -lsubunit -lpthread -lrt -lm -D_GNU_SOURCE
endif

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -g -c $< -o $@

all: s21_string.a test gcov_report

s21_string.a: $(OBJ) $(HEADER)
	ar rcs s21_string.a $(OBJ)
	ranlib s21_string.a
	rm -rf FUNC/*.o

test: s21_string.a 
	gcc $(CFLAGS) Tests/string_test1.c s21_string.a $(TEST_LIBS) -o test.out
	./test.out

valgrind: clean s21_string.a
	$(CC) Tests/string_test1.c s21_string.a -o test $(TEST_LIBS)
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT_VALGRIND.txt ./test

gcov_report: s21_string.a test
	gcc $(GCOVFLAGS) Tests/string_test1.c $(SOURCE) -o report.out $(TEST_LIBS)
	./report.out
	gcov -f $(SOURCE)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html

clean: 
	rm -rf *.o *.out *.gcov *.gcno *.info *.gcda *.a

rebuild: clean all

clang:
	clang-format -style=google -n *.c *.h Tests/*.c
