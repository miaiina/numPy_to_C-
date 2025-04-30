#include "create.h"
#include <iostream>

using namespace std;

// Utility to print vectors and matrices
void print(const vector<double>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void print(const vector<vector<double>>& mat) {
    for (const auto& row : mat) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

void print(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

// Utility to print n-dimensional array
void print_n(const NDArray& arr, int indent = 0) {
    if (holds_alternative<double>(arr)) {
        cout << get<double>(arr);
    } else if (holds_alternative<vector<any>>(arr)) {
        const auto& vec = get<vector<any>>(arr);
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            if (vec[i].type() == typeid(double)) {
                cout << any_cast<double>(vec[i]);
            } else if (vec[i].type() == typeid(vector<any>)) {
                print_n(NDArray(any_cast<vector<any>>(vec[i])), indent + 1);
            } else {
                cout << "Invalid type";
            }
            if (i < vec.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    if (indent == 0) cout << endl;
}

