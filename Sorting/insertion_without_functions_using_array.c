#include <stdio.h>

int main (void)
{
    int size = 6;
    int A[size] = {4,1,3,9,45,23};

    for (int i=1; i<SIZE; i++)
    {
        if (A[i-1]>A[i])
        {
            int key = A[i];
            // Shifting
            for (int j=i; j>sorted; j--)
            {
                A[j]=A[j-1];
            }
            A[sorted] = key;
        }
    }
    
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
