#include <stdio.h>

int main (void)
{
    // Variable declarations
    int smallest, tmp_smallest;     // indices
    int sorted = 0;     // number of sorted elements
    int size;

    // Size from user
    printf("Enter size for Array: ");
    scanf(" %d", &size);

    // Array declaration
    int A[size];
    int unsorted = size - sorted;

    // Array definition
    for (int i=0; i<size; i++)
    {
        printf("Enter element (%d): ", i);
        scanf(" %d", &A[i]);
    }

    printf("\nOriginal Array:\n\n");
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n");
    for (int i=sorted; i<size; i++)
    {
        smallest = i;
        tmp_smallest=i;
        for (int j=i, k=1; j<size-1; j++,k++)
        {
            if (A[tmp_smallest] > A[j+1])
                tmp_smallest=j+1;
        }

        // swapping
        int tmp = A[smallest];
        A[smallest] = A[tmp_smallest];
        A[tmp_smallest] = tmp;

        sorted++;
        printf("\tArray after %d pass:\n\n\t", sorted);
        for (int i=0; i<size; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n\n");
    }

    printf("Sorted Array: ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}