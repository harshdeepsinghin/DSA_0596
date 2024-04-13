#include <stdio.h>

/* Write a C program to display the content of pointers using arrays of pointers.*/

int main (void)
{
    int A=3, B=4, C=5;
    int *P1=&A, *P2=&B, *P3=&C;
    int *P[3] = {P1, P2, P3};

    printf("P[0] = A = %d\n", *P[0]);
    printf("P[1] = B = %d\n", *P[1]);
    printf("P[2] = C = %d\n", *P[2]);

    return 0;
}