CC=gcc -g
FLAGS = -Wall -Werror -Wextra -std=c11 
DIR = back/
FUNC = s21_calc.c s21_parcer.c
FUNC_C = $(addprefix $(DIR), $(FUNC))
TESTS_C = tests/test_calc.c
VAR = $(shell pkg-config --cflags --libs check)


all: install tests

install:
	mkdir build
	cd ./build; cmake ../Calculator/CMakeLists.txt; cmake --build .

uninstall:
	rm -rf build

dvi:
#	doxygen
	open ./html/index.html

dist:
	cd ..; tar -cvf archive.tar src


tests: clean
#	ноут:
#	$(CC) -o test $(TESTS_C) -fprofile-arcs -ftest-coverage $(FUNC_C) -lcheck -lpthread -lrt -lm -lsubunit
#	3 этаж:
#	$(CC) $(VAR) $(FLAGS) -fprofile-arcs -ftest-coverage -o test $(FUNC_C) $(TESTS_C) -lcheck -lm -lpthread
#	просто:
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage -o test $(FUNC_C) $(TESTS_C) -lcheck -lpthread 
	./test

gcov_report: tests
	gcov $(TESTS_C)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	open report/index.html


clean:
	rm -rf *.o report *.info *.gcda *.gcno *.gcov *.gch *.out *.a *.dSYM test
#	rm -rf build-Calculator*
#	rm -rf Calculator/CMakeLists.txt.user

main:
	$(CC) $(FLAGS) $(DIR)main.c $(FUNC_C) 
#	$(CC) $(FLAGS) $(DIR)main.c $(FUNC_C) -lm 
	./a.out

valgrind:
	valgrind --leak-check=full -s --track-origins=yes --log-file=valgrind-out.txt ./test

style:
	cp ../materials/linters/.clang-format ./
#	clang-format -i $(FUNC_C) back/s21_calc.h tests/test_calc.c
	clang-format -n $(FUNC_C) back/s21_calc.h



