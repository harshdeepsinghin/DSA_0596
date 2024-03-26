#include <stdio.h>

int main (void)
{
    // Variable declarations
    int smallest, tmp_smallest;     // indices
    const int size = 6;
    int A[size] = {23,12,8,2,26,0};
    int sorted = 0;     // number of sorted elements
    int unsorted = size - sorted;

    for (int i=sorted; i<size; i++)
    {
        smallest = i;
        for (int j=i; j<size; j++)
        {
            if (A[i] > A[j+1])
            {
                tmp_smallest=i+1;
            }
        }
        printf("tmp_smallest: %d\n", tmp_smallest);

        // swapping
        int tmp = A[smallest];
        A[smallest] = A[tmp_smallest];
        A[tmp_smallest] = tmp;

        sorted++;
    }

    for (int i=0; i<size; i++)
    {
        printf("%d\n", A[i]);
    }
}