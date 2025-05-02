#include "indexslice.h"
#include <iostream>

using namespace std;

int main() {
  // Création d'une matrice 3x3
  Matrix<int> mat(3, 3);
  
  // Initialisation
  int val = 0;
  for (size_t i = 0; i < mat.rows(); ++i)
      for (size_t j = 0; j < mat.cols(); ++j)
          mat(i, j) = val++;

  std::cout << "Matrice originale:" << std::endl;
  mat.print();

  // accès à l'élément d'index (1,2)
  std::cout << "\nAccès à l'élément (1,2): " << mat(1, 2) << std::endl;

  // Extraction des trois premiers éléments (première ligne)
  std::vector<int> first_row = mat.row(0);
  std::cout << "\nPremière ligne:" << std::endl;
  for (int x : first_row) std::cout << x << " ";
  std::cout << std::endl;

  // Extraction de la deuxième colonne
  std::vector<int> second_col = mat.column(1);
  std::cout << "\nDeuxième colonne:" << std::endl;
  for (int x : second_col) std::cout << x << " ";
  std::cout << std::endl;

  // Extraction de sous-matrice (dernières 2 lignes et 2 premières colonnes)
  Matrix<int> sub = mat.submatrix(1, 0, mat.rows(), 2);
  std::cout << "\nSous-matrice (dernières 2 lignes et 2 premières colonnes):" << std::endl;
  sub.print();

  return 0;
}