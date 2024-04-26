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
