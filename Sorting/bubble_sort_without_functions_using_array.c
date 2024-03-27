#include <stdio.h>

int main (void)
{
    // Size from user
    int size;
    printf("Enter size for Array: ");
    scanf(" %d", &size);

    // Array declaration
    int ARRAY[size];

    // Elements input
    for (int i=0; i<size; i++)
    {
        printf("Enter element (%d): ", i);
        scanf(" %d", &ARRAY[i]);
    }

    printf("\nOriginal Array: ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", ARRAY[i]);
    }

    // outer loop will iterate from 0 to n-1 as sorted
    for (int sorted=0; sorted<size; sorted++)
    {
        // inner loop will iterate from pass to 1 as comp
        for (int comp=0; comp<size-sorted-1; comp++)
        {
            if (ARRAY[comp]>ARRAY[comp+1])
            {
                // Swapping
                int tmp = ARRAY[comp+1];
                ARRAY[comp+1] = ARRAY[comp];
                ARRAY[comp] = tmp;
            }
        }
    }

    printf("\n\nSorted Array: ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", ARRAY[i]);
    }
    printf("\n");
}