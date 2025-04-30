#include "operation.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

using namespace std;

/*Additon soustraction multiplication*/
// Addition de matrices
NDArray operator+(const NDArray& A, const NDArray& B) {
  int rows = A.getRows();
  int cols = A.getCols();

  if (rows != B.getRows() || cols != B.getCols())
      throw invalid_argument("Matrix dimensions must match for addition");

  NDArray result(rows, cols);
  for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
          result(i, j) = A(i, j) + B(i, j);

  return result;
}

// Soustraction de matrices
NDArray operator-(const NDArray& A, const NDArray& B) {
  int rows = A.getRows();
  int cols = A.getCols();

  if (rows != B.getRows() || cols != B.getCols())
      throw invalid_argument("Matrix dimensions must match for subtraction");

  NDArray result(rows, cols);
  for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
          result(i, j) = A(i, j) - B(i, j);

  return result;
}

// Multiplication élément par élément (pas le dot product)
NDArray multiply(const NDArray& A, const NDArray& B) {
  int rows = A.getRows();
  int cols = A.getCols();

  if (rows != B.getRows() || cols != B.getCols())
      throw invalid_argument("Matrix dimensions must match for element-wise multiplication");

  NDArray result(rows, cols);
  for (int i = 0; i < rows; ++i)
      for (int j = 0; j < cols; ++j)
          result(i, j) = A(i, j) * B(i, j);

  return result;
}

// Produit matriciel
NDArray dot(const NDArray& A, const NDArray& B) {
    int a_rows = A.getRows();
    int a_cols = A.getCols();
    int b_rows = B.getRows();
    int b_cols = B.getCols();

    if (a_cols != b_rows)
        throw invalid_argument("Inner dimensions must match for matrix multiplication");

    NDArray result(a_rows, b_cols);

    for (int i = 0; i < a_rows; ++i)
        for (int j = 0; j < b_cols; ++j)
            for (int k = 0; k < a_cols; ++k)
                result(i, j) += A(i, k) * B(k, j);  // Utilise la version const ici

    return result;
}

// Fonction exp
NDArray exp(const NDArray& A) {
    int rows = A.getRows();
    int cols = A.getCols();
    NDArray result(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result(i, j) = std::exp(A(i, j));

    return result;
}

// Fonction sqrt
NDArray sqrt(const NDArray& A) {
    int rows = A.getRows();
    int cols = A.getCols();
    NDArray result(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (A(i, j) < 0)
                throw runtime_error("Square root of negative number");
            result(i, j) = std::sqrt(A(i, j));
        }

    return result;
}

// Fonction log
NDArray log(const NDArray& A) {
    int rows = A.getRows();
    int cols = A.getCols();
    NDArray result(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if (A(i, j) <= 0)
                throw runtime_error("Logarithm of non-positive number");
            result(i, j) = std::log(A(i, j));
        }

    return result;
}

// Fonction abs
NDArray abs(const NDArray& A) {
    int rows = A.getRows();
    int cols = A.getCols();
    NDArray result(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result(i, j) = std::abs(A(i, j));

    return result;
}

// Fonction power
NDArray power(const NDArray& A, double exponent) {
    int rows = A.getRows();
    int cols = A.getCols();
    NDArray result(rows, cols);

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result(i, j) = std::pow(A(i, j), exponent);

    return result;
}
