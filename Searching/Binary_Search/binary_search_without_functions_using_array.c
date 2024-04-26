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
