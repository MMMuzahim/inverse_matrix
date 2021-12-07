#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;

#include "input_matrix_function.h"
#include "norm.h"
#include "solve.h"


void print_matrix(vector<vector<double>> matrix, int m, int l, int n)
{
    if (m != 0)
    {
        
        if (l > m && m != -1)
            l = m;
        if (n > m && m != -1)
            n = m;
        
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%10.3E ", matrix[i][j]);
            cout << endl;
        }
        cout << endl;
    }
}


int main(int argc, char const *argv[])
{
    if (argc != 4 && argc != 5)
        return -1;

    int n, m;
    short k;

    if (!(istringstream(argv[1]) >> n)) {
        cerr << "Invalid number: " << argv[1] << '\n';
    }
    if (!(istringstream(argv[2]) >> m)) {
        cerr << "Invalid number: " << argv[2] << '\n';
    }
    if (!(istringstream(argv[3]) >> k)) {
        cerr << "Invalid number k: " << argv[3] << '\n';
    }

    //input and output matrix
    vector<vector<double>> matrix;
    if (k != 0)
        matrix = input_function(k, n);
    if (k == 0)
        matrix = read_matrix(argv[4]);
    if (k > 4 || k < 0)
        return -1;

    print_matrix(matrix, m, n, n);
    vector<vector<double>> X = identity_matrix(n);
    
    time_t start_time = time(NULL);
    inverse_matrix(n, matrix, &X);
    time_t end_time = time(NULL);
    print_matrix(X, m, n, n);
    
    if (m != -1) {
        printf("%f\n", difftime(end_time, start_time));
        printf("%10.3E\n", norm(matrix, X));
    }
    return 0;
}
