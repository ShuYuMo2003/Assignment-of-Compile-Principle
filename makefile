.PHONY: all

all:
	bison -d matrix_calc.y
	flex matrix_calc.l
	gcc matrix_calc.tab.c lex.yy.c -Wall -o main -lm
