#include "ndarray.h"
#include <iostream>

using namespace std;

// Fonction utilitaire pour créer un array rempli de zéros
template<typename T>
NDArray<T> zeros(const vector<int>& shape) {
    return NDArray<T>(shape, T(0));
}

// Créer un array rempli de uns
template<typename T>
NDArray<T> ones(const vector<int>& shape) {
    return NDArray<T>(shape, T(1));
}

