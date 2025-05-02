#ifndef INDEXSLICE_H
#define INDEXSLICE_H

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    std::vector<T> data;
    size_t rows_;
    size_t cols_;

public:
    // Constructeur
    Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols), data(rows * cols);

    // Accès aux éléments avec opérateur()
    T& operator()(size_t i, size_t j);

    const T& operator()(size_t i, size_t j) const;

    // Extraction d'une ligne
    std::vector<T> row(size_t i) const;

    // Extraction d'une colonne
    std::vector<T> column(size_t j) const;

    // Extraction d'une sous-matrice
    Matrix submatrix(size_t row_start, size_t col_start, size_t row_end, size_t col_end) const;

    // Affichage de la matrice
    void print() const;

    // Accesseurs pour les dimensions
    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }
};

#endif