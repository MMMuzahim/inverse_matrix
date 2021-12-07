CC = g++
CFLAGS = -Wall -g

a.out: main.o input_matrix_function.o norm.o solve.o
	$(CC) $(CFLAGS) -o a.out main.o input_matrix_function.o norm.o solve.o

main.o: main.cpp input_matrix_function.h norm.o solve.h
	$(CC) -c main.cpp

input_matrix_function.o: input_matrix_function.h

norm.o: norm.h

solve.o: solve.h
