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