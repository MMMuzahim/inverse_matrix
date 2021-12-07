#ifndef SOLVE_H
#define SOLVE_H
#include <vector>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;

void swap_columns(vector<vector<double>> *X, unsigned int x1, unsigned int x2);
void swap_rows(vector<vector<double>> *X, size_t y1, size_t y2);
void add_row(vector<vector<double>> *X, unsigned int y1, unsigned int y2, double k);
size_t index_of_max_in_row(vector<vector<double>> *A, unsigned int row_index);
void multiply_row(vector<vector<double>> *X, unsigned int row_index, double k);
void inverse_matrix(int n, vector<vector<double>> A, vector<vector<double>> *X);

#endif
