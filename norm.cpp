#include "norm.h"

double norm(vector<vector<double>> A, vector<vector<double>> X)
{
    double norm = 0, d;
    //cout << A.size();
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j < A[i].size(); j++)
        {
            d = 0;
            for (size_t k = 0; k < A[i].size(); k++)
                d += A[i][k] * X[k][j];
            
            if (i == j)
                d--;
            
            norm += d * d;
        }
    }
    return sqrt(norm);
}
