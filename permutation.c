#include <stdio.h>

void permut(), swap();

main() {
    char hill[4]={'1', '2', '3', '4'};
    permut(hill,0,3);
    }
    
void permut(X,x0,xn)
char X[];
int x0, xn;
{
    int i;
    if(x0==xn) {
    for(i=0; i<= xn; i++)
    printf("%c ", X[i]);
    printf("\n");
    }
        else
        for(i=x0; i<=xn; i++) {
        swap(&X[x0], &X[i]);
        permut(X, (x0+1), xn);
        swap(&X[x0], &X[i]);
        }
    }
    
void swap(char *m, char *n)
{
        char t= *m;*m=*n;
        *n=t;
}
