#include <iostream>
#include <string.h>
using namespace std;
int addStep(int num) {
  int sum=0;
  while(num!=0) {
    sum+=sum%10;
    num/=10;
  }
  return sum;
}
int main() {
  string cnum;
  cout << "Enter the number of the credit card:" ";
    cin >> cnum;
  int odd=0, even=0;
  for(int i=0; i<16; i++) {
    if(i%2==0)
      even += addStep(2*((int)(cnum[i]-'0')));
    else
      odd += ((int)(cnum[i]-'0'));
  }
  if((odd+even)%10==0)
    cout << "Correct credit card number!";
  else
    cout << "Wrong credit card number!";
}
