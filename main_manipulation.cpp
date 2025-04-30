#include "manipulation.h"
#include <iostream>

using namespace std;

int main() {
  // Création de deux tableaux
  NDArray arr1(2, 3);
  arr1(0, 0) = 1; arr1(0, 1) = 2; arr1(0, 2) = 3;
  arr1(1, 0) = 4; arr1(1, 1) = 5; arr1(1, 2) = 6;

  NDArray arr2(2, 2);
  arr2(0, 0) = 7; arr2(0, 1) = 8;
  arr2(1, 0) = 9; arr2(1, 1) = 10;

  cout << "arr1:\n"; arr1.print();
  cout << "\narr2:\n"; arr2.print();

  // Shape
  auto sh = arr1.shape();
  cout << "\narr1.shape -> (" << sh.first << ", " << sh.second << ")" << endl;

  // Size
  cout << "arr1.size -> " << arr1.size() << endl;

  // DType
  cout << "arr1.dtype -> " << arr1.dtype() << endl;

  // Reshape
  cout << "\narr1.reshape(3,2):\n";
  NDArray reshaped = arr1.reshape(3, 2);
  reshaped.print();

  // Flatten
  cout << "\narr1.flatten():\n";
  NDArray flat = arr1.flatten();
  flat.print();

  // vstack
  cout << "\nvstack(arr1, arr1):\n";
  NDArray vs = vstack(arr1, arr1);
  vs.print();

  // hstack
  cout << "\nhstack(arr2, arr2):\n";
  NDArray hs = hstack(arr2, arr2);
  hs.print();

  return 0;
}