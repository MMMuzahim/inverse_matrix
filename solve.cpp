#include "solve.h"

void swap_columns(vector<vector<double>> *X, unsigned int x1, unsigned int x2)
{
    for (size_t i = 0; i < X->size(); i++)
    {
        double temp = X->at(i).at(x1);
        X->at(i).at(x1) = X->at(i).at(x2);
        X->at(i).at(x2) = temp;
    }
}

void swap_rows(vector<vector<double>> *X, size_t y1, size_t y2)
{
    for (size_t i = 0; i < X->size(); i++)
    {
        double temp = X->at(y1).at(i);
        X->at(y1).at(i) = X->at(y2).at(i);
        X->at(y2).at(i) = temp;
    }
}

void add_row(vector<vector<double>> *X, unsigned int y1, unsigned int y2, double k)
{
    for (size_t i = 0; i < X->at(0).size(); i++)
        X->at(y1).at(i) += k * X->at(y2).at(i);
}

size_t index_of_max_in_row(vector<vector<double>> *A, unsigned int row_index)
{
    double max = A->at(row_index)[0];
    size_t index_of_max = 0;

    
    for (size_t i = 1; i < A->at(row_index).size(); i++)
    {
        if (abs(A->at(row_index).at(i)) > max)
        {
            max = abs(A->at(row_index)[i]);
            index_of_max = i;
        }
    }

    return index_of_max;
}

void multiply_row(vector<vector<double>> *X, unsigned int row_index, double k)
{
    for (size_t i = 0; i < X->size(); i++)
        X->at(row_index)[i] *= k;
}

void inverse_matrix(int n, vector<vector<double>> A, vector<vector<double>> *X)
{
    //прямой ход
    vector<vector<size_t>> swaps;
    for (size_t i = 0; i < A.size(); i++)
    {
        size_t x = index_of_max_in_row(&A, i);
        swap_columns(&A, i, x);
        vector<size_t> temp = {i, x};
        swaps.push_back(temp);
        multiply_row(X, i, 1/A[i][i]);
        multiply_row(&A, i, 1/A[i][i]);
        
        for (int j = i + 1; j < n; j++)
        {
            add_row(X, j, i, -A[j][i]);
            add_row(&A, j, i, -A[j][i]);
        }
    }

    //обратный ход
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            add_row(X, j, i, -A[j][i]);
            add_row(&A, j, i, -A[j][i]);
        }
    }

    for (size_t i = X->size() - 1; i > 0; --i)
    {
        swap_rows(X, swaps[i][0], swaps[i][1]);
    }
    swap_rows(X, swaps[0][0], swaps[0][1]);
}
