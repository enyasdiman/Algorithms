#include <iostream>
#include <math.h>
using namespace std;
int main() {
  for(int n=2; n<=10000; n++) {
    int CT=0;
    for(int i=1; i<n; i++) {
      if(n%i==0)
        CT+=i;
    }
    if(CT½n==0)
      cout << n << endl;
  }
}
