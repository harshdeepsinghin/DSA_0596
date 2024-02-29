#include <stdio.h>

// int ROW, COLUMN;    // identifiers for inputting elements into an array
int ROWS, COLUMNS;    // identifiers for inputting elements into an array

int input_array_elements (int ARRAY[ROWS][COLUMNS]);    // function declaration for inputting elements into an array. 
int traverse (int ARRAY[ROWS][COLUMNS]);    // function declaration for traversing an array. 

int main (void)
{
    int R1, C1, R2, C2;
    printf("Enter the row size for 1st array: ");
    scanf(" %d", &R1);
    printf("Enter the column size for 1st array: ");
    scanf(" %d", &C1);
    printf("Enter the row size for 2nd array: ");
    scanf(" %d", &R2);
    printf("Enter the row size for 2nd array: ");
    scanf(" %d", &C2);

    int A[R1][C1], B[R2][C2];

    printf("\n");
    printf("Inputs for First Array:\n\n");
    input_array_elements(A);

    printf("\nFirst Array of order %dx%d:\n\n", R1, C1);
    traverse(B);    
    
    printf("\n");

    // printf("1st ROW: %d \n1st COLUMN: %d\n2nd ROW: %d\n2nd COLUMN: %d", R1, C1, R2, C2);

    /*
    // Code for traversing the matrix
    printf("\n");
    for (int R = 0; R < R1; R++)
    {
        for (int C = 0; C < C1; C++)
        {
            printf("%d\t",A[R][C]);
        }
        printf("\n");
    }
    printf("\n");
    */
    return 0;
}

/*
Below traverse function will print an array.
*/


int input_array_elements (int ARRAY[ROWS][COLUMNS])
{
    printf("%d\n", ROWS);
    printf("%d\n", COLUMNS);
    for (int R = 0; R < ROWS; R++)
    {
        for (int C = 0; C < COLUMNS; C++)
        {
            printf("Enter the value for row %d and column %d: ", R, C);
            scanf("%d", &ARRAY[R][C]);
        }
        printf("\n");
    }
    return 0;
}

int traverse (int ARRAY[ROWS][COLUMNS])
{
    printf("%d\n", ROWS);
    printf("%d\n", COLUMNS);
    for (int R = 0; R < ROWS; R++)
    {
        for (int C = 0; C < COLUMNS; C++)
        {
            printf("%d\t",ARRAY[R][C]);
        }
        printf("\n");
    }
    return 0;
}