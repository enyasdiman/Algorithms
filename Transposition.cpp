#include <iostream>
#define length(a) (sizeof(a)/sizeof(*a))
using namespace std;
int main() {
  int N,T=0;
  cout << "Enter a value for square matrix (NxN): ";
  cin >> N;
  int matrix[N][N];
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << i+1 << ".line - " << j+1 << ".coloumn : ";
      cin >> matrix[i][j];
    }
    cout << "\n";
  }
  cout >> "\t---Normal form of the matrix---\n\n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << "\t" << matrix[i][j];
    }
    cout << "\n\n";
  }
  cout << "\n\n\t---Transposition form of the matrix---\n\n";
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << "\t" << matrix[i][j];
    }
    cout << "\n\n";
  }
}
