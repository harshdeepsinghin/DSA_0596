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

<div style="page-break-after: always;"></div>

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

<div style="page-break-after: always;"></div>

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


<div style="page-break-after: always;"></div>

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

<div style="page-break-after: always;"></div>

## insertion_sort_with_functions_using_array.c
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

<div style="page-break-after: always;"></div>

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

<div style="page-break-after: always;"></div>

# Selection Sort
## selection_sort_without_functions_using_array.c
### Code
```C
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

    printf("\nOriginal Array: ");
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
    }

    printf("Sorted Array: ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
```
### Output
```
Enter size for Array: 5
Enter element (0): -35
Enter element (1): 76
Enter element (2): -88
Enter element (3): 3
Enter element (4): 56

Original Array: -35 76 -88 3 56 

Sorted Array: -88 -35 3 56 76 
```

<div style="page-break-after: always;"></div>

## selection_sort_with_functions_using_array.c
### Code
```C
#include <stdio.h>

void traverse(int ARRAY[], int size, int option);

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

    traverse(A, size, 1);

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
    }

    traverse(A, size, 2);

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
Enter element (0): 23
Enter element (1): -12
Enter element (2): 67
Enter element (3): 3
Enter element (4): 9

Original Array: 23 -12 67 3 9 

Sorted Array: -12 3 9 23 67 
```

<div style="page-break-after: always;"></div>

## selection_sort_with_functions_using_array_with_observations.c
### Code
```C
#include <stdio.h>

void traverse(int ARRAY[], int size, int option);

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

    traverse(A, size, 1);

    for (int i=sorted; i<size; i++)
    {
        printf("Pass %d:\n", i+1);
        smallest = i;
        tmp_smallest=i;
        for (int j=i, k=1; j<size-1; j++,k++)
        {
            printf("\tComparison %d:\n", k);
            printf("\t\tA[%d]: %d",j, A[j]);
            if (A[tmp_smallest] > A[j+1])
            {
                printf("\n\t\t\tA[tmp_smallest] > A[j+1]\n");
                printf("\n\t\t\t%d > %d\n", A[tmp_smallest], A[j+1]);
                tmp_smallest=j+1;
                printf("\t\t\ttmp_smallest: %d\t", tmp_smallest);
                printf("A[tmp_smallest]: %d\n", A[tmp_smallest]);
            }
            else
            {
                printf("\n\t\t\tA[tmp_smallest] > A[j+1]\n");
                printf("\n\t\t\t%d < %d\n", A[tmp_smallest], A[j+1]);
                printf("\t\t\ttmp_smallest: %d\t", tmp_smallest);
                printf("A[tmp_smallest]: %d\n", A[tmp_smallest]);
            }
        }

        printf("\tsmallest: %d\t", smallest);
        printf("A[smallest]: %d\n", A[smallest]);
        printf("\ttmp_smallest: %d\t", tmp_smallest);
        printf("A[tmp_smallest]: %d\n", A[tmp_smallest]);

        // swapping
        int tmp = A[smallest];
        A[smallest] = A[tmp_smallest];
        A[tmp_smallest] = tmp;

        sorted++;
        traverse(A, size, 3);
    }

    traverse(A, size, 2);
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
Enter element (0): 45
Enter element (1): -23
Enter element (2): 4
Enter element (3): 7
Enter element (4): 1

Original Array: 45 -23 4 7 1 
Pass 1:
        Comparison 1:
                A[0]: 45
                        A[tmp_smallest] > A[j+1]

                        45 > -23
                        tmp_smallest: 1 A[tmp_smallest]: -23
        Comparison 2:
                A[1]: -23
                        A[tmp_smallest] > A[j+1]

                        -23 < 4
                        tmp_smallest: 1 A[tmp_smallest]: -23
        Comparison 3:
                A[2]: 4
                        A[tmp_smallest] > A[j+1]

                        -23 < 7
                        tmp_smallest: 1 A[tmp_smallest]: -23
        Comparison 4:
                A[3]: 7
                        A[tmp_smallest] > A[j+1]

                        -23 < 1
                        tmp_smallest: 1 A[tmp_smallest]: -23
        smallest: 0     A[smallest]: 45
        tmp_smallest: 1 A[tmp_smallest]: -23

        Partially Sorted Array: -23 45 4 7 1 
Pass 2:
        Comparison 1:
                A[1]: 45
                        A[tmp_smallest] > A[j+1]

                        45 > 4
                        tmp_smallest: 2 A[tmp_smallest]: 4
        Comparison 2:
                A[2]: 4
                        A[tmp_smallest] > A[j+1]

                        4 < 7
                        tmp_smallest: 2 A[tmp_smallest]: 4
        Comparison 3:
                A[3]: 7
                        A[tmp_smallest] > A[j+1]

                        4 > 1
                        tmp_smallest: 4 A[tmp_smallest]: 1
        smallest: 1     A[smallest]: 45
        tmp_smallest: 4 A[tmp_smallest]: 1

        Partially Sorted Array: -23 1 4 7 45 
Pass 3:
        Comparison 1:
                A[2]: 4
                        A[tmp_smallest] > A[j+1]

                        4 < 7
                        tmp_smallest: 2 A[tmp_smallest]: 4
        Comparison 2:
                A[3]: 7
                        A[tmp_smallest] > A[j+1]

                        4 < 45
                        tmp_smallest: 2 A[tmp_smallest]: 4
        smallest: 2     A[smallest]: 4
        tmp_smallest: 2 A[tmp_smallest]: 4

        Partially Sorted Array: -23 1 4 7 45 
Pass 4:
        Comparison 1:
                A[3]: 7
                        A[tmp_smallest] > A[j+1]

                        7 < 45
                        tmp_smallest: 3 A[tmp_smallest]: 7
        smallest: 3     A[smallest]: 7
        tmp_smallest: 3 A[tmp_smallest]: 7

        Partially Sorted Array: -23 1 4 7 45 
Pass 5:
        smallest: 4     A[smallest]: 45
        tmp_smallest: 4 A[tmp_smallest]: 45

        Partially Sorted Array: -23 1 4 7 45 

Sorted Array: -23 1 4 7 45 
```

<div style="page-break-after: always;"></div>