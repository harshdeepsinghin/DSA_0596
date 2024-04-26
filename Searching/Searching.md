# Binary Search
## binary_search_without_functions_using_array.c
### Code
```C
#include <stdio.h>

int main(void)
{
    // Size from user
    int size;
    int KEY;
    int found = 0;
    printf("Enter size for Array: ");
    scanf(" %d", &size);

    // Array declaration
    int ARRAY[size];

    // Elements input
    for (int i = 0; i < size; i++)
    {
        printf("Enter element (%d): ", i);
        scanf(" %d", &ARRAY[i]);
    }

    printf("\nArray: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ARRAY[i]);
    }

    // Sort
    for (int sorted = 0; sorted < size; sorted++)
    {
        // inner loop will iterate from pass to 1 as comp
        for (int comp = 0; comp < size - sorted - 1; comp++)
        {
            if (ARRAY[comp] > ARRAY[comp + 1])
            {
                // Swapping
                int tmp = ARRAY[comp + 1];
                ARRAY[comp + 1] = ARRAY[comp];
                ARRAY[comp] = tmp;
            }
        }
    }

    // Binary Search
    printf("\n\nEnter the element to search: ");
    scanf(" %d", &KEY);

    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ARRAY[mid] == KEY)
        {
            found = 1;
            printf("\nElement (%d) found at index (%d)\n\n", KEY, mid);
            break; // If found, no need to continue searching
        }
        else if (ARRAY[mid] < KEY)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
    {
        printf("\nOops! Element not found!\n");
    }

    return 0;
}

```

### Output
```
Enter size for Array: 5
Enter element (0): 1
Enter element (1): 2
Enter element (2): 3
Enter element (3): 4
Enter element (4): 5

Array: 1 2 3 4 5 


Enter the element to search: 3

Element (3) found at index (2)

---

Enter size for Array: 5
Enter element (0): 1
Enter element (1): 2
Enter element (2): 3
Enter element (3): 4
Enter element (4): 5

Array: 1 2 3 4 5 


Enter the element to search: 6

Oops! Element not found!
```

<div style="page-break-after: always;"></div>

## binary_search_with_functions_using_array.c
### Code
```C
#include <stdio.h>

void traverse(int ARRAY[], int size);
void linear_search (int ARRAYPARAM[], int ARRAYSIZE, int KEY);

int main (void)
{
    // Size from user
    int size;
    int KEY;
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

    traverse(ARRAY, size);     // original array

    // Linear Search

    printf("\n\nEnter the element to search: ");
    scanf(" %d", &KEY);

    linear_search(ARRAY, size, KEY);

    
}

void traverse(int ARRAY[], int ARRAYSIZE)
{
    printf("\nArray: ");
    for (int i=0; i < ARRAYSIZE; i++)
    {
        printf("%d ", ARRAY[i]);
    }
    printf("\n");

}

void linear_search (int ARRAYPARAM[], int ARRAYSIZE, int KEY)
{
    int found = 0;
    for ( int i = 0; i < ARRAYSIZE; i++ )
    {
        if ( ARRAYPARAM[i] == KEY )
        {
            printf("\nElement (%d) found at index (%d)\n\n", KEY, i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nOops! Element not found!\n");
    }

}
```
### Output
```
Enter size for Array: 5
Enter element (0): 1
Enter element (1): 2
Enter element (2): 3
Enter element (3): 4
Enter element (4): 5

Array: 1 2 3 4 5 


Enter the element to search: 3

Element (3) found at index (2)

---

Enter size for Array: 5
Enter element (0): 1
Enter element (1): 2
Enter element (2): 3
Enter element (3): 4
Enter element (4): 5

Array: 1 2 3 4 5 


Enter the element to search: 6

Oops! Element not found!
```

<div style="page-break-after: always;"></div>


# Linear Search
## linear_search_without_functions_using_array.c
### Code
```C
#include <stdio.h>

int main (void)
{
    // Size from user
    int size;
    int KEY;
    int found = 0;
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

    printf("\nArray: ");
    for (int i=0; i<size; i++)
    {
        printf("%d ", ARRAY[i]);
    }

    // Linear Search
    
    printf("\n\nEnter the element to search: ");
    scanf(" %d", &KEY);

    for ( int i = 0; i < size; i++ )
    {
        if ( ARRAY[i] == KEY )
        {
            printf("\nElement (%d) found at index (%d)\n\n", KEY, i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("\nOops! Element not found!\n");
    }

    return 0;
}

```

### Output
```
Enter size for Array: 5
Enter element (0): 2
Enter element (1): 3
Enter element (2): 4
Enter element (3): 5
Enter element (4): 6

Array: 2 3 4 5 6 

Enter the element to search: 5

Element (5) found at index (3)

---

Enter size for Array: 5
Enter element (0): 3
Enter element (1): 4
Enter element (2): 5
Enter element (3): 6
Enter element (4): 7

Array: 3 4 5 6 7 

Enter the element to search: 1

Oops! Element not found!
```

<div style="page-break-after: always;"></div>

## linear_search_with_functions_using_array.c
### Code
```C
#include <stdio.h>

void traverse(int ARRAY[], int size);
void binary_search(int ARRAY[], int size, int KEY);

int main(void)
{
    // Size from user
    int size;
    int KEY;
    printf("Enter size for Array: ");
    scanf(" %d", &size);

    // Array declaration
    int ARRAY[size];

    // Elements input
    for (int i = 0; i < size; i++)
    {
        printf("Enter element (%d): ", i);
        scanf(" %d", &ARRAY[i]);
    }

    traverse(ARRAY, size); // original array

    // Binary Search
    printf("\n\nEnter the element to search: ");
    scanf(" %d", &KEY);

    binary_search(ARRAY, size, KEY);

    return 0;
}

void traverse(int ARRAY[], int ARRAYSIZE)
{
    printf("\nArray: ");
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        printf("%d ", ARRAY[i]);
    }
    printf("\n");
}

void binary_search(int ARRAY[], int size, int KEY)
{
    int found = 0;
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ARRAY[mid] == KEY)
        {
            found = 1;
            printf("\nElement (%d) found at index (%d)\n\n", KEY, mid);
            break; // If found, no need to continue searching
        }
        else if (ARRAY[mid] < KEY)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
    {
        printf("\nOops! Element not found!\n");
    }
}

```

### Output
```
Enter size for Array: 5
Enter element (0): 2
Enter element (1): 3
Enter element (2): 4
Enter element (3): 5
Enter element (4): 6

Array: 2 3 4 5 6 

Enter the element to search: 5

Element (5) found at index (3)

---

Enter size for Array: 5
Enter element (0): 3
Enter element (1): 4
Enter element (2): 5
Enter element (3): 6
Enter element (4): 7

Array: 3 4 5 6 7 

Enter the element to search: 1

Oops! Element not found!
```

<div style="page-break-after: always;"></div>

