#include <stdio.h>

void traverse(int ARRAY[], int size, int option);

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

    traverse(ARRAY,size,1);     // original array

    // outer loop will iterate from 1 to n-1 as pass
    for (int pass=1; pass<size; pass++)
    {
        // inner loop will iterate from pass to 1 as comp
        for (int comp=pass; comp>0; comp--)
        {
            if (ARRAY[comp]<ARRAY[comp-1])
            {
                // Swapping
                int tmp = ARRAY[comp-1];
                ARRAY[comp-1] = ARRAY[comp];
                ARRAY[comp] = tmp;
            }
        }
    }

    traverse(ARRAY,size,2);     // sorted array
}

void traverse(int ARRAY[], int size, int option)
{
    switch (option)
    {
        case 1:
            printf("\nOriginal Array: ");
            for (int i=0; i<size; i++)
            {
                printf("%d ", ARRAY[i]);
            }
            printf("\n");
            break;

        case 2:
            printf("\nSorted Array: ");
            for (int i=0; i<size; i++)
            {
                printf("%d ", ARRAY[i]);
            }
            printf("\n");
            break;
    }
}