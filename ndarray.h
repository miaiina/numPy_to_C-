#ifndef NDARRAY_H
#define NDARRAY_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class NDArray {
private:
    vector<T> data;
    vector<int> shape;
    int totalSize;

    int computeTotalSize(const vector<int>& shape) const {
        int size = 1;
        for (int dim : shape)
            size *= dim;
        return size;
    }

    string shapeToString() const {
        stringstream ss;
        ss << "(";
        for (size_t i = 0; i < shape.size(); ++i) {
            ss << shape[i];
            if (i != shape.size() - 1) ss << ", ";
        }
        ss << ")";
        return ss.str();
    }

public:
    NDArray(const vector<int>& shape) {
        this->shape = shape;
        totalSize = computeTotalSize(shape);
        data.resize(totalSize);
    }

    // Initialisation avec une valeur initiale
    NDArray(const vector<int>& shape, T value) {
        this->shape = shape;
        totalSize = computeTotalSize(shape);
        data.resize(totalSize, value);
    }

    T& at(const vector<int>& indices) {
        int index = 0;
        int stride = 1;
        for (int i = shape.size() - 1; i >= 0; --i) {
            index += indices[i] * stride;
            stride *= shape[i];
        }
        return data[index];
    }

    void print() const {
        cout << "NDArray" << shapeToString() << ":\n";
        printRecursive(0, 0, 0);
        cout << "\n";
    }

    void setValue(T value) {
        for (int i = 0; i < totalSize; ++i)
            data[i] = value;
    }

    void setLinear(int index, T value) {
        data[index] = value;
    }

private:
    void printRecursive(int dim, int offset, int depth) const {
        if (dim == shape.size() - 1) {
            cout << "[";
            for (int i = 0; i < shape[dim]; ++i) {
                cout << data[offset + i];
                if (i != shape[dim] - 1) cout << ", ";
            }
            cout << "]";
            if (depth == 0) cout << "\n";
            return;
        }

        cout << "[";
        int stride = 1;
        for (int i = shape.size() - 1; i > dim; --i)
            stride *= shape[i];

        for (int i = 0; i < shape[dim]; ++i) {
            printRecursive(dim + 1, offset + i * stride, depth + 1);
            if (i != shape[dim] - 1)
                cout << ",\n" << string(depth * 2, ' ');
        }
        cout << "]";
    }
};

template<typename T>
NDArray<T> zeros(const vector<int>& shape);

template<typename T>
NDArray<T> ones(const vector<int>& shape);

#endif