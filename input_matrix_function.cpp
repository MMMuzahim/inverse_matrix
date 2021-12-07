#include "input_matrix_function.h"

vector<vector<double>> input_function(short k, int n)
{
    vector<vector<double>> matrix;
    for (int j = 1; j <= n; j++)
    {
        vector<double> temp;
        for (int i = 1; i <= n; i++)
        {
            if (k == 1)
            {
                temp.push_back(n - max(i, j) + 1);
            } else if (k == 2)
            {
                temp.push_back(max(i, j));
            } else if (k == 3)
            {
                temp.push_back(abs(i - j));
            } else if (k == 4)
            {
                temp.push_back(1/(i + j - 1.));
            }
        }
        matrix.push_back(temp);
        temp.clear();
    }
    return matrix;
}

/*void input_file(char const filename[])
{
    ofstream matrix;
    matrix.open("matrix.txt");
    matrix.clear();
    ifstream input_file;
    input_file.open(filename);
    
    input_file.seekg (0, input_file.end);
    int length = input_file.tellg();
    input_file.seekg (0, input_file.beg);

    char * buffer = new char [length];
    input_file.read(buffer, length);
    matrix << buffer;
}*/

vector<vector<double>> read_matrix(char const filename[])
{
    vector<vector<double>> matrix;
    vector<double> temp;
    ifstream fmatrix;
    fmatrix.open(filename);
    
    string line;
    while (getline(fmatrix, line))
    {
        istringstream iss(line);
        double d;
        while (!(iss.eof()))
        {
            iss >> d;
            temp.push_back(d);         
        }
        //temp.pop_back();
        matrix.push_back(temp);
        temp.clear();
    }
    return matrix;
}

vector<vector<double>> identity_matrix(int n)
{
    vector<vector<double>> matrix;
    vector<double> temp;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    
    return matrix;
}
