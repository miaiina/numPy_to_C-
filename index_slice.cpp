#include "indexslice.h"
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
    // Constructeur
    Matrix<T>::Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data(rows * cols) {}

    // Accès aux éléments avec opérateur()
    template <typename T>
    T& Matrix<T>::operator()(size_t i, size_t j) {
        if (i >= rows_ || j >= cols_)
            throw std::out_of_range("Indices hors limites");
        return data[i * cols_ + j];
    }

    template <typename T>
    const T& Matrix<T>::operator()(size_t i, size_t j) const {
        if (i >= rows_ || j >= cols_)
            throw std::out_of_range("Indices hors limites");
        return data[i * cols_ + j];
    }

    // Extraction d'une ligne
    template <typename T>
    std::vector<T> Matrix<T>::row(size_t i) const {
        std::vector<T> res(cols_);
        for (size_t j = 0; j < cols_; ++j)
            res[j] = (*this)(i, j);
        return res;
    }

    // Extraction d'une colonne
    template <typename T>
    std::vector<T> Matrix<T>::column(size_t j) const {
        std::vector<T> res(rows_);
        for (size_t i = 0; i < rows_; ++i)
            res[i] = (*this)(i, j);
        return res;
    }

    // Extraction d'une sous-matrice
    template <typename T>
    Matrix<T> Matrix<T>::submatrix(size_t row_start, size_t col_start, size_t row_end, size_t col_end) const {
        Matrix Matrix<T>::res(row_end - row_start, col_end - col_start);
        for (size_t i = row_start; i < row_end; ++i)
            for (size_t j = col_start; j < col_end; ++j)
                res(i - row_start, j - col_start) = (*this)(i, j);
        return res;
    }

    // Affichage de la matrice
    template <typename T>
    void Matrix<T>::print() const {
        for (size_t i = 0; i < rows_; ++i) {
            for (size_t j = 0; j < cols_; ++j)
                std::cout << (*this)(i, j) << " ";
            std::cout << std::endl;
        }
    }

    // Accesseurs pour les dimensions
    template <typename T>
    size_t Matrix<T>::rows() const { return rows_; }

    template <typename T>
    size_t Matrix<T>::cols() const { return cols_; }

