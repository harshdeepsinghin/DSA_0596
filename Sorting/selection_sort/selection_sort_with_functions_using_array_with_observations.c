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
