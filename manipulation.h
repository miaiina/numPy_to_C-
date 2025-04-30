#ifndef MANIPULATION_H
#define MANIPULATION_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>

using namespace std;

class NDArray {
private:
    vector<double> data;
    int rows, cols;

public:
    NDArray(int r, int c) : rows(r), cols(c), data(r * c, 0.0) {}

    // Constructeur par copie
    NDArray(const NDArray& other)
        : rows(other.rows), cols(other.cols), data(other.data) {}

    // Accès aux éléments
    double& operator()(int i, int j) {
        if (i >= rows || j >= cols)
            throw out_of_range("Index out of bounds");
        return data[i * cols + j];
    }

    double operator()(int i, int j) const {
        if (i >= rows || j >= cols)
            throw out_of_range("Index out of bounds");
        return data[i * cols + j];
    }

    // Dimensions
    pair<int, int> shape() const { return make_pair(rows, cols); }
    int size() const { return rows * cols; }
    string dtype() const { return "double"; }

    // Redimensionnement
    NDArray reshape(int new_rows, int new_cols) const {
        if (new_rows * new_cols != size())
            throw invalid_argument("Total size remains constant");
        NDArray result(new_rows, new_cols);
        for (int i = 0; i < size(); ++i)
            result.data[i] = this->data[i];
        return result;
    }

    // Aplatir en 1D
    NDArray flatten() const {
        NDArray result(1, size());
        for (int i = 0; i < size(); ++i)
            result.data[i] = data[i];
        return result;
    }

    // Affichage
    void print() const {
        cout << "[\n";
        for (int i = 0; i < rows; ++i) {
            cout << "  [ ";
            for (int j = 0; j < cols; ++j) {
                cout << fixed << setprecision(4) << (*this)(i, j);
                if (j != cols - 1) cout << ", ";
            }
            cout << " ]\n";
        }
        cout << "]\n";
    }

    // Surcharge de l’opérateur =
    NDArray& operator=(const NDArray& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    friend NDArray concat(const NDArray& a, const NDArray& b, int axis);
    friend NDArray hstack(const NDArray& a, const NDArray& b);
    friend NDArray vstack(const NDArray& a, const NDArray& b);
};

NDArray concat(const NDArray& a, const NDArray& b, int axis);
NDArray hstack(const NDArray& a, const NDArray& b);
NDArray vstack(const NDArray& a, const NDArray& b);

#endif