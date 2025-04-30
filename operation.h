#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

class NDArray {
private:
    vector<vector<double>> data;
    int rows, cols;

public:
    NDArray(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0.0)) {}

    // Accès aux éléments
    double& operator()(int i, int j) {
        if (i >= rows || j >= cols)
            throw out_of_range("Index out of bounds");
        return data[i][j];
    }

    // Version const pour les objets constants
    double operator()(int i, int j) const {
        if (i >= rows || j >= cols)
            throw out_of_range("Index out of bounds");
        return data[i][j];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void print() const {
        cout << "[\n";
        for (int i = 0; i < rows; ++i) {
            cout << "  [ ";
            for (int j = 0; j < cols; ++j) {
                cout.precision(4);
                cout << fixed << data[i][j];
                if (j != cols - 1) cout << ", ";
            }
            cout << " ]\n";
        }
        cout << "]\n";
    }
};

NDArray operator+(const NDArray& A, const NDArray& B);
NDArray operator-(const NDArray& A, const NDArray& B);
NDArray multiply(const NDArray& A, const NDArray& B);
NDArray dot(const NDArray& A, const NDArray& B) ;
NDArray exp(const NDArray& A);
NDArray sqrt(const NDArray& A) ;
NDArray log(const NDArray& A) ;
NDArray abs(const NDArray& A);
NDArray power(const NDArray& A, double exponent) ;

#endif