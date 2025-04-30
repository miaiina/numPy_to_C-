#ifndef CREATE_H
#define CREATE_H

#include <vector>
#include <random>
#include <iostream>
#include <variant>
#include <any>

using namespace std;

// Type alias for n-dimensional array (nested vectors or scalar)
using NDArray = variant<double, vector<any>>;

class NumPyLike {
private:
    mt19937 rng; // Random number generator

public:
    NumPyLike() {
        rng.seed(random_device()()); // Seed random number generator
    }

    /*// 1D array from vector
    std::vector<double> array(const std::vector<double>& values) {
        return values; // Simply return a copy of the input vector
    }

    // 2D array from vector of vectors
    std::vector<std::vector<double>> array(const std::vector<std::vector<double>>& values) {
        return values; // Simply return a copy of the input 2D vector
    }

    // N-dimensional array from nested vector structure
    NDArray array_n(const std::vector<std::any>& values) {
        std::vector<std::any> result;
        for (const auto& val : values) {
            if (val.type() == typeid(double)) {
                result.push_back(std::any_cast<double>(val));
            } else if (val.type() == typeid(std::vector<std::any>)) {
                result.push_back(array_n(std::any_cast<std::vector<std::any>>(val)));
            } else {
                throw std::invalid_argument("Invalid type in n-dimensional array");
            }
        }
        return result;
    }*/

    // Zeros matrix
    vector<vector<double>> zeros(int rows, int cols) {
        return vector<vector<double>>(rows, vector<double>(cols, 0.0));
    }

    // Ones matrix
    vector<vector<double>> ones(int rows, int cols) {
        return vector<vector<double>>(rows, vector<double>(cols, 1.0));
    }

    // Full matrix with specified value
    vector<vector<double>> full(int rows, int cols, double value) {
        return vector<vector<double>>(rows, vector<double>(cols, value));
    }

    // Identity matrix
    vector<vector<double>> eye(int n) {
        vector<vector<double>> mat(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; ++i) {
            mat[i][i] = 1.0;
        }
        return mat;
    }

    // Arange: start to stop with step
    vector<double> arange(double start, double stop, double step) {
        int size = static_cast<int>((stop - start) / step);
        vector<double> vec(size);
        for (int i = 0; i < size; ++i) {
            vec[i] = start + i * step;
        }
        return vec;
    }

    // Linspace: n evenly spaced values from start to stop
    vector<double> linspace(double start, double stop, int n) {
        vector<double> vec(n);
        double step = (stop - start) / (n - 1);
        for (int i = 0; i < n; ++i) {
            vec[i] = start + i * step;
        }
        return vec;
    }

    // Random uniform [0, 1) matrix
    vector<vector<double>> random_rand(int rows, int cols) {
        uniform_real_distribution<double> dist(0.0, 1.0);
        vector<vector<double>> mat(rows, vector<double>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = dist(rng);
            }
        }
        return mat;
    }

    // Random integers in [low, high) matrix
    vector<vector<int>> random_randint(int low, int high, int rows, int cols) {
        uniform_int_distribution<int> dist(low, high);
        vector<vector<int>> mat(rows, vector<int>(cols));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = dist(rng);
            }
        }
        return mat;
    }
};

void print(const vector<double>& vec);
void print(const vector<vector<double>>& mat);
void print(const vector<vector<int>>& mat);
void print_n(const NDArray& arr, int indent = 0);

#endif