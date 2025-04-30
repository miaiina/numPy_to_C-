#include "create.h"
#include <iostream>

using namespace std;

int main() {
  NumPyLike np;

  /*// np.array([1, 2, 3])
  std::cout << "1D Array:" << std::endl;
  auto arr1 = np.array({1.0, 2.0, 3.0});
  print(arr1);

  // np.array([[1, 2], [3, 4]])
  std::cout << "\n2D Array:" << std::endl;
  auto arr2 = np.array({{1.0, 2.0}, {3.0, 4.0}});
  print(arr2);

  // N-dimensional array: 3D example [[[1, 2], [3, 4]], [[5, 6], [7, 8]]]
  std::cout << "\n3D Array:" << std::endl;
  std::vector<std::any> layer1 = {
      std::vector<std::any>{1.0, 2.0},
      std::vector<std::any>{3.0, 4.0}
  };
  std::vector<std::any> layer2 = {
      std::vector<std::any>{5.0, 6.0},
      std::vector<std::any>{7.0, 8.0}
  };
  std::vector<std::any> arr3d = {layer1, layer2};
  auto arr_n = np.array_n(arr3d);
  print_n(arr_n);*/

  // np.zeros((3, 3)):crée un tableau rempli de zéros 
  cout << "\nZeros (3x3):" << endl;
  auto zeros = np.zeros(3, 3);
  print(zeros);

  // np.ones((2, 2)):crée un tableau remplis de un
  cout << "\nOnes (2x2):" << endl;
  auto ones = np.ones(2, 2);
  print(ones);

  // np.full((2, 3), 7):crée un tableau rempli de la valeur spécifiée
  cout << "\nFull (2x3, 7):" << endl;
  auto full = np.full(2, 3, 7.0);
  print(full);

  // np.eye(4):matrice identité 4*4
  cout << "\nIdentity (4x4):" << endl;
  auto eye = np.eye(4);
  print(eye);

  // np.arange(0, 10, 2):tableau de 0 à 10 avec un pas de 2
  cout << "\nArange (0 to 10, step 2):" << endl;
  auto arange = np.arange(0.0, 10.0, 2.0);
  print(arange);

  // np.linspace(0, 1, 5):5 valeurs espacées uniformément entre 0 et 1 
  cout << "\nLinspace (0 to 1, 5 points):" << endl;
  auto linspace = np.linspace(0.0, 1.0, 5);
  print(linspace);

  // np.random.rand(3, 3):Tableau de nombres aléatoires uniformes entre 0 et 1
  cout << "\nRandom uniform [0, 1) (3x3):" << endl;
  auto rand = np.random_rand(3, 3);
  print(rand);

  // np.random.randint(0, 10, (2, 3)):Tableau 2*3 d'entiers aléatoires entre 0 et 10
  cout << "\nRandom integers [0, 10) (2x3):" << endl;
  auto randint = np.random_randint(0, 10, 2, 3);
  print(randint);

  return 0;
}