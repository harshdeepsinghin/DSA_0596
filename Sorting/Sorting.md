# Bubble Sort
## bubble_sort_without_functions_using_array.c
### Code
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
### Code
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
### Code
```C
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
                printf("\t\t%d is greater than %d, therefore\n", ARRAY[comp], ARRAY[comp+1]);
                // Swapping
                int tmp = ARRAY[comp+1];
                ARRAY[comp+1] = ARRAY[comp];
                ARRAY[comp] = tmp;
                printf("\t\t%d and %d swapped!\n", ARRAY[comp+1], ARRAY[comp]);
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
```

### Output

```
Enter size for Array: 5
Size you entered: 5
Enter element (0): 56
Enter element (1): -45
Enter element (2): 7
Enter element (3): 1
Enter element (4): 34

Original Array: 56 -45 7 1 34 


Pass 1:

        Comparison 1:
                56 is greater than -45, therefore
                56 and -45 swapped!

        Partially Sorted Array: -45 56 7 1 34 

        Comparison 2:
                56 is greater than 7, therefore
                56 and 7 swapped!

        Partially Sorted Array: -45 7 56 1 34 

        Comparison 3:
                56 is greater than 1, therefore
                56 and 1 swapped!

        Partially Sorted Array: -45 7 1 56 34 

        Comparison 4:
                56 is greater than 34, therefore
                56 and 34 swapped!

        Partially Sorted Array: -45 7 1 34 56 


Pass 2:

        Comparison 1:
                -45 is not greater than 7, therefore
                -45 and 7 not swapped!

        Partially Sorted Array: -45 7 1 34 56 

        Comparison 2:
                7 is greater than 1, therefore
                7 and 1 swapped!

        Partially Sorted Array: -45 1 7 34 56 

        Comparison 3:
                7 is not greater than 34, therefore
                7 and 34 not swapped!

        Partially Sorted Array: -45 1 7 34 56 


Pass 3:

        Comparison 1:
                -45 is not greater than 1, therefore
                -45 and 1 not swapped!

        Partially Sorted Array: -45 1 7 34 56 

        Comparison 2:
                1 is not greater than 7, therefore
                1 and 7 not swapped!

        Partially Sorted Array: -45 1 7 34 56 


Pass 4:

        Comparison 1:
                -45 is not greater than 1, therefore
                -45 and 1 not swapped!

        Partially Sorted Array: -45 1 7 34 56 

Sorted Array: -45 1 7 34 56
```

# Insertion Sort
## insertion_sort_without_functions_using_array.c
### Code
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
Enter element (0): 34
Enter element (1): -12
Enter element (2): 4
Enter element (3): 66
Enter element (4): 3

Original Array: 34 -12 4 66 3 

Sorted Array: -12 3 4 34 66 
```

## insertion_sort_with_functions_using_array
### Code
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
```
### Output
```
Enter size for Array: 5
Enter element (0): 12
Enter element (1): -4
Enter element (2): 65
Enter element (3): 22
Enter element (4): 9

Original Array: 12 -4 65 22 9 

Sorted Array: -4 9 12 22 65 
```

## insertion_sort_with_functions_using_array_with_observations.c
### Code
```C
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

    traverse(ARRAY,size,1);     // original array

    // outer loop will iterate from 1 to n-1 as pass
    for (int pass=1; pass<size; pass++)
    {
        printf("\n\nPass %d:\n", pass);
        // inner loop will iterate from pass to 1 as comp
        for (int comp=pass; comp>0; comp--)
        {
            printf("\n\tComparison %d:\n", pass - comp + 1);
            if (ARRAY[comp]<ARRAY[comp-1])
            {
                printf("\t\t%d is less than %d, therefore\n", ARRAY[comp], ARRAY[comp-1]);
                // Swapping
                int tmp = ARRAY[comp-1];
                ARRAY[comp-1] = ARRAY[comp];
                ARRAY[comp] = tmp;
                printf("\t\t%d and %d swapped!\n", ARRAY[comp], ARRAY[comp-1]);
            }
            else
            {
                printf("\t\t%d is not less than %d, therefore\n", ARRAY[comp], ARRAY[comp-1]);
                printf("\t\t%d and %d not swapped!\n", ARRAY[comp], ARRAY[comp-1]);
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
```
### Output
```
Enter size for Array: 5
Size you entered: 5
Enter element (0): 34
Enter element (1): -12
Enter element (2): 6
Enter element (3): 7
Enter element (4): 2

Original Array: 34 -12 6 7 2 


Pass 1:

        Comparison 1:
                -12 is less than 34, therefore
                34 and -12 swapped!

        Partially Sorted Array: -12 34 6 7 2 


Pass 2:

        Comparison 1:
                6 is less than 34, therefore
                34 and 6 swapped!

        Partially Sorted Array: -12 6 34 7 2 

        Comparison 2:
                6 is not less than -12, therefore
                6 and -12 not swapped!

        Partially Sorted Array: -12 6 34 7 2 


Pass 3:

        Comparison 1:
                7 is less than 34, therefore
                34 and 7 swapped!

        Partially Sorted Array: -12 6 7 34 2 

        Comparison 2:
                7 is not less than 6, therefore
                7 and 6 not swapped!

        Partially Sorted Array: -12 6 7 34 2 

        Comparison 3:
                6 is not less than -12, therefore
                6 and -12 not swapped!

        Partially Sorted Array: -12 6 7 34 2 


Pass 4:

        Comparison 1:
                2 is less than 34, therefore
                34 and 2 swapped!

        Partially Sorted Array: -12 6 7 2 34 

        Comparison 2:
                2 is less than 7, therefore
                7 and 2 swapped!

        Partially Sorted Array: -12 6 2 7 34 

        Comparison 3:
                2 is less than 6, therefore
                6 and 2 swapped!

        Partially Sorted Array: -12 2 6 7 34 

        Comparison 4:
                2 is not less than -12, therefore
                2 and -12 not swapped!

        Partially Sorted Array: -12 2 6 7 34 

Sorted Array: -12 2 6 7 34 
```
# Selection Sort
## 