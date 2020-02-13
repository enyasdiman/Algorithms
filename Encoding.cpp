#include <iostream>
#include <string.h>
#define length(a) (sizeof(a)/sizeof(*a))
using namespace std;
int main() {
  string word;
  cout << "Enter a word: ";
  cin >> word;
  for(int i=0; i<word.size(); i++) {
    word[i] = (char) ((int)word[i])+15);
  }
  cout << endl << "Encrypted word: " << word;
}
