CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
ifeq ($(MAKECMDGOALS), gcov_report)
	CFLAGS += --coverage
endif
TEST_DIR = tests

CSRC = $(wildcard s21*.c)
TEST_CSRC = $(wildcard $(TEST_DIR)/*.c)
COBJ = $(CSRC:.c=.o)
LIBNAME = s21_string.a

.PHONY: all clean test gcov_report

all: rebuild

test: rebuild 
	$(CC) $(CFLAGS) $(TEST_CSRC) -L . $(LIBNAME) -o ./$(TEST_DIR)/run_tests -lcheck -lsubunit -g -lm
	./$(TEST_DIR)/run_tests 

valgrind: rebuild 
	$(CC) $(CFLAGS) $(TEST_CSRC) -L . $(LIBNAME) -o ./$(TEST_DIR)/run_tests -lcheck -lsubunit -lm
	valgrind --tool=memcheck --leak-check=yes  ./$(TEST_DIR)/run_tests 

$(LIBNAME): $(COBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -g -lm

gcov_report: rebuild $(LIBNAME)
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST_CSRC) -L . $(LIBNAME) -o $(TEST_DIR)/run_tests -lgcov -lcheck -lsubunit -lm
	./$(TEST_DIR)/run_tests
	rm -rf $(TEST_DIR)/*gcda $(TEST_DIR)/*gcno
	lcov -t "s21_test" -o $(TEST_DIR)/s21_test.info -c -d .
	genhtml -o report $(TEST_DIR)/s21_test.info

clean:
	rm -rf $(COBJ) $(LIBNAME) /$(TEST_DIR)/run_tests $(TEST_DIR)/s21_test.info ./report/ 
	rm -rf $(TEST_DIR)/run_tests *gcda *gcno */*gcda */*gcno

rebuild: clean $(LIBNAME)