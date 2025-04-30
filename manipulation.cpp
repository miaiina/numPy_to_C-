#include "manipulation.h"
#include <iostream>

using namespace std;

// Concaténation générale selon axis
NDArray concat(const NDArray& a, const NDArray& b, int axis) {
  if (axis == 0) { // Axe vertical
      if (a.shape().second != b.shape().second)
          throw invalid_argument("Columns must match for vertical concat");

      NDArray res(a.shape().first + b.shape().first, a.shape().second);

      int index = 0;
      for (int i = 0; i < a.shape().first; ++i)
          for (int j = 0; j < a.shape().second; ++j)
              res(index++, j) = a(i, j);

      index = a.shape().first;
      for (int i = 0; i < b.shape().first; ++i)
          for (int j = 0; j < b.shape().second; ++j)
              res(index++, j) = b(i, j);

      return res;

  } else if (axis == 1) { // Axe horizontal
      if (a.shape().first != b.shape().first)
          throw invalid_argument("Rows must match for horizontal concat");

      NDArray res(a.shape().first, a.shape().second + b.shape().second);

      for (int i = 0; i < a.shape().first; ++i) {
          int index = 0;
          for (int j = 0; j < a.shape().second; ++j)
              res(i, index++) = a(i, j);
          for (int j = 0; j < b.shape().second; ++j)
              res(i, index++) = b(i, j);
      }

      return res;

  } else {
      throw invalid_argument("Axis must be 0 or 1");
  }
}

NDArray hstack(const NDArray& a, const NDArray& b) {
  return concat(a, b, 1);
}

NDArray vstack(const NDArray& a, const NDArray& b) {
  return concat(a, b, 0);
}
