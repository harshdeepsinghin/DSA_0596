#include <stdio.h>

int main (void)
{
    int T, N;   // Variables

    printf("Enter total number of games: ");
    scanf(" %d", &T);
    if (!(T >= 1 && T <= 10))
    {
        printf("\nOops! Input out of constraints.\n");
        return 1;
    }
    
    for (int i=0; i<T; i++)
    {
        printf("Enter number of chocolates for game (%d): ", i+1);
        scanf(" %d", &N);
        if (!(N >= 2 && N <= 100000))
        {
            printf("\nOops! Input out of constraints.\n");
            return 1;
        }
        
        int A[T][N];   // 2D Array

        for (int j=0; j<N; j++)
        {
            scanf(" %d", &A[i][j]);
        }
    }

    for (int i=0; i<T; i++)
    {
        for (int j=0, j<N;)
    }




    return 0;
}