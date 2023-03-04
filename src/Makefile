.PHONY = all s21_string.a test gcov_report check clean
CC = gcc
FLAG_C = -c
FLAG_O = -o
ASAN = -g -fsanitize=address
FLAG_COV = --coverage
FLAG_ER = -Wall -Werror -Wextra -std=c11
GCOV = -fprofile-arcs -ftest-coverage
# ifeq ($(OS), Darwin)
# TEST_LIBS = -lcheck -lgcov
# else
# TEST_LIBS = `pkg-config --cflags --libs check` -lm -lgcov -c
# endif
# TST_LIBS = -lcheck -pthread -lrt -lm -lsubunit -lgcov
TST_LIBS = -lcheck -lm -lpthread -lgcov --coverage
ifeq ($(shell uname), Linux)
TST_LIBS = -lcheck -lsubunit -lrt -lm -lpthread -lgcov --coverage
endif
s21_string_C = s21_string.c 
s21_string_O = s21_string.o

all: clean gcov_report

s21_string.a:
	$(CC) $(FLAG_C) $(FLAG_ER) $(ASAN) $(TST_LIBS) $(s21_string_C)
	ar rc s21_string.a $(s21_string_O)
	ranlib s21_string.a

test: clean s21_string.a
	$(CC) $(FLAG_ER) $(FLAG_O) test $(s21_string_C) string_test.c s21_string.a $(TST_LIBS)
	./test

gcov_report: clean s21_string.a
	$(CC) $(FLAG_ER) $(GCOV) string_test.c $(TST_LIBS) s21_*.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	open /report/index.html
 
check:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f test
	-rm -f report gcovreport
	find . -type d -name 'tests.dSYM' -exec rm -r {} +