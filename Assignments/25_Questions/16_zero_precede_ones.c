#include <stdio.h>

/* Program to arrange binary digits such that all 0's precede all 1's: */


int main (void)
{
    int BIN;    // Binary number

    printf("Enter a binary number: ");
    scanf(" %d", &BIN);

    do
    {
        int d = BIN%10;
        printf("d is %d\n", d);
    } while (BIN/=10);

    return 0;
}