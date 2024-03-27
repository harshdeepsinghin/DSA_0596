#include <stdio.h>

void traverse(int ARRAY[], int size, int option);

int main (void)
{
    // Size from user
    int size;
    printf("Enter size for Array: ");
    scanf(" %d", &size);

    printf("Size you entered: %d\n", size);

    // Array declaration
    int ARRAY[size];

    // Elements input
    for (int i=0; i<size; i++)
    {
        printf("Enter element (%d): ", i);
        scanf(" %d", &ARRAY[i]);
    }

    traverse(ARRAY, size, 1);     // original array

    // outer loop will iterate from 0 to n-1 as sorted
    for (int sorted=0; sorted<size-1; sorted++)
    {
        printf("\n\nPass %d:\n", sorted+1);
        // inner loop will iterate from pass to 1 as comp
        for (int comp=0; comp<size-sorted-1; comp++)
        {
            printf("\n\tComparison %d:\n", comp+1);
            if (ARRAY[comp]>ARRAY[comp+1])
            {
                // Swapping
                int tmp = ARRAY[comp+1];
                ARRAY[comp+1] = ARRAY[comp];
                ARRAY[comp] = tmp;
                printf("\t\t%d is greater than %d, therefore\n", ARRAY[comp], ARRAY[comp+1]);
                printf("\t\t%d and %d swapped!\n", ARRAY[comp], ARRAY[comp+1]);
            }
            else
            {
                printf("\t\t%d is not greater than %d, therefore\n", ARRAY[comp], ARRAY[comp+1]);
                printf("\t\t%d and %d not swapped!\n", ARRAY[comp], ARRAY[comp+1]);
            }
            traverse(ARRAY,size,3);
        }
    }

    traverse(ARRAY, size, 2);     // sorted array
    return 0;
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

        case 3:
            printf("\n\tPartially Sorted Array: ");
            for (int i=0; i<size; i++)
            {
                printf("%d ", ARRAY[i]);
            }
            printf("\n");
            break;
    }
}
