#ifndef INPUT_MATRIX_FUNCTION_H
#define INPUT_MATRIX_FUNCTION_H
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
using namespace std;

vector<vector<double>> input_function(short k, int n);
//void input_file();
vector<vector<double>> read_matrix(char const filename[]);
vector<vector<double>> identity_matrix(int n);

#endif
