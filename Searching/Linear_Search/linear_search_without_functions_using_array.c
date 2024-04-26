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
