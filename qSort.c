/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    quickSort(int D[], int left, int right) {
    int k, j;
    int middle, temp;
    
    k = left; j = right;
    
    middle = D[(right+left)/2];
    do {
        while(D[k]<middle && k<right)
        k++;
        while(middle<D[j] && j>left)
        j--;
        if(k<=j) {
            temp = D[k];
            D[k] = D[j];
            D[j] = temp;
            k++;
            j--;
        }
    } while(k<=j);
    if(left<j)
    quickSort(D, left, j);
    if(k<right)
    quickSort(D, k, right);
    }
}

//Worst cade => O(n^2)
//Average case => O(nlog2n)
