#include "ndarray.h"
#include <iostream>

using namespace std;

int main() {
  // Tableau 1D : Vecteur
  auto arr1D = zeros<int>({5});
  for (int i = 0; i < 5; ++i)
      arr1D.at({i}) = i + 1;
  cout << "\nTableau 1D [Vecteur]:\n";
  arr1D.print();

  // Tableau 2D : Matrice
  auto arr2D = zeros<int>({2, 3});
  int val = 1;
  for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 3; ++j)
          arr2D.at({i, j}) = val++;
  cout << "\nTableau 2D [Matrice]:\n";
  arr2D.print();

  // Tableau 3D
  auto arr3D = ones<int>({2, 2, 2});
  val = 1;
  for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
          for (int k = 0; k < 2; ++k)
              arr3D.at({i, j, k}) = val++;
  cout << "\nTableau 3D:\n";
  arr3D.print();

  // Tableau 4D
  auto arr4D = zeros<int>({2, 2, 2, 2});
  val = 10;
  for (int a = 0; a < 2; ++a)
      for (int b = 0; b < 2; ++b)
          for (int c = 0; c < 2; ++c)
              for (int d = 0; d < 2; ++d) {
                  arr4D.at({a, b, c, d}) = val++;
              }
  cout << "\nTableau 4D:\n";
  arr4D.print();

  return 0;
}