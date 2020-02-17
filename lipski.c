#include <stdio.h>
#include <conio.h>
main() {
    int i, n, d, P[10], R[10], sum, b;
clrscr();
printf("Enter the numver to crumble: ");
scanf(%d", &n);

P[1]=n;
R[1]=1;
d=1;
printf("%dx%d\n", P[1], R[1]);

while(P[1]>1) {
sum=0;
        if(P[d]==1) {
              sum = sum+R[d];
              d=d-1;
        }
        sum = sum+P[d];
        R[d]=R[d]-1;
              b=P[d]-1;

        if(R[d]>0)
              d = d+1;
              P[d]=b;
              R[d]=sum/b;
              b=sum%b;

        if(b!=0) {
              d=d+1;
              P[d]=b;
              R[d]=1;
}

      for(i=1; i<=d; i++)
          printf("%dx%d ", P[i], R[i]);
              printf("\n");
              }
}
