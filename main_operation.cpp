#include "operation.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
  NDArray A(2, 2);
  A(0, 0) = 1; A(0, 1) = 2;
  A(1, 0) = 3; A(1, 1) = 4;

  NDArray B(2, 2);
  B(0, 0) = 5; B(0, 1) = 6;
  B(1, 0) = 7; B(1, 1) = 8;

  cout << "Voici les deux tableaux 2D A et B: " << endl;
  cout << "A:\n"; A.print();
  cout << "B:\n"; B.print();

  cout << "Les différentes opérations mathématiques: " << endl;
  cout << "Addition A + B:\n";
  NDArray add_AB = A + B;
  add_AB.print();

  cout << "Soustraction A - B:\n";
  NDArray sub_AB = A - B;
  sub_AB.print();

  cout << "Multiplication élément par élément A .* B:\n";
  NDArray mul_AB = multiply(A, B);
  mul_AB.print();
  
  NDArray dot_product = dot(A, B);
  cout << "A · B (dot product):\n"; dot_product.print();

  NDArray exp_A = exp(A);
  cout << "exp(A):\n"; exp_A.print();

  NDArray sqrt_B = sqrt(B);
  cout << "sqrt(B):\n"; sqrt_B.print();

  NDArray log_B = log(B);
  cout << "log(B):\n"; log_B.print();

  NDArray abs_A = abs(A);
  cout << "abs(A):\n"; abs_A.print();

  NDArray square_A = power(A, 2);
  cout << "A^2:\n"; square_A.print();

  return 0;
}