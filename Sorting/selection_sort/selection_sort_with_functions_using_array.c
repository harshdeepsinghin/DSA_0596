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