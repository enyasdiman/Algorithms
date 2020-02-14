#include <iostream>
using namespace std;
int Collatz(int x) {
  if(x==1)
    return 1;
  else if(x%2==0)
    return Collatz(x/2);
  else
    return Collatz(3*x+1);
}
int main() {
  for(int i=1; i<=1000; i++) {
    cout << i << 1\tCollatz->\t" << Collatz(i) << endl;
  }
}
