#include <studio.h>
#include <conio.h>

void hanoi(int n, char c, char y, char z) {
  if(n==1)
    printf("Put the disk from %c to the %c stick." \n\n", x, z);
  else {
    hanoi(n-1, x, z, y);
    hanoi(1, x, y, z);
    hanoi(n-1, y, x, z);
    }
}

int main() {
  clrscr();
  int n;
  printf("Number of the disks N: ");
  scanf("%d", &n);
  hanoi(n, 'A', 'B', 'C');
  getch();
    return 0;
}
