#include <stdio.h>

/*Q5. Write a program to input a matrix and to determine if it is an asymmetrical matrix.
*/

int main (void)
{
    int N;      // Row and Column size of matrix

    printf("Enter the N for NxN square matrix: ");
    scanf(" %d", &N);

    int M[N][N];    // Matrix of NxN size
    int C=0;        // Counter

    // Takes Matrix element's input
    for (int i=0; i<N; i++)
    {
            for (int j=0; j<N; j++)
            {
                printf("Enter element (M[%d][%d]): ", i, j);
                scanf(" %d", &M[i][j]);
            }
    }

    // Display Matrix
    printf("\nMatrix:\n");
    for (int i=0; i<N; i++)
    {
            for (int j=0; j<N; j++)
            {
                printf("%d ", M[i][j]);
                if (M[i][j] == M[j][i])
                    C++;
            }
            printf("\n");
    }
    printf("\n");

    // Asymmetrical Matrix check
    if (C == (N*N))
        printf("The matrix is a Symmetrical Matrix.\n");
    else
        printf("The matrix is an Asymmetrical Matrix.\n");
    
    return 0;
}