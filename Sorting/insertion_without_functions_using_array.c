#include <stdio.h>

int main (void)
{
    int SIZE = 6
    int A[SIZE] = {4,1,3,9,45,23};

    for (int i=1; i<SIZE; i++)
    {
        if (A[i-1]>A[i])
        {
            int key = A[i];
            A[i] = A[i-1];
            A[i] = key;
        }
    }
    
    return 0;
}
