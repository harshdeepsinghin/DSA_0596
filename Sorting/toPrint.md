## bubble_sort_without_functions_using_array.c
```C
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
```

### Output
```
Enter size for Array: 5
Enter element (0): 23
Enter element (1): -45
Enter element (2): 6
Enter element (3): 235
Enter element (4): 5

Original Array: 23 -45 6 235 5 

Sorted Array: -45 5 6 23 235 
```

## bubble_sort_with_functions_using_array.c
```C
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

    traverse(ARRAY, size, 1);     // original array

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

    traverse(ARRAY, size, 2);     // sorted array
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
```

### Output
```
Enter size for Array: 5
Enter element (0): 6
Enter element (1): 2
Enter element (2): 45
Enter element (3): -2
Enter element (4): 46

Original Array: 6 2 45 -2 46 

Sorted Array: -2 2 6 45 46 
```

## bubble_sort_with_functions_using_array_with_observations.c