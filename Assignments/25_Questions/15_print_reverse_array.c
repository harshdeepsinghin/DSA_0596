#include <stdio.h>

/* Program to print elements of an array in reverse order: */

int main (void)
{
    const int N = 5;    // Array size
    int A[N] = {2,4,6,8,10};    // Array initialization

    // Original Array Traversing
    printf("Original Array: ");
    for (int i=0; i<N; i++)
    {
        printf("%d ", A[i]);
    }

    // Reversed Array Traversing
    printf("\nReversed Array: ");
    for (int i=N-1; i>=0; i--)
    {
        printf("%d ", A[i]);
    }
    
    return 0;
}