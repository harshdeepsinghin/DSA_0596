#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    // Variables Declaration
    int SIZE;   // Stack Size
    

    printf("Enter the max length of an expression for stack: ");
    scanf(" %d", &SIZE);

    char EXP[SIZE];    // Expression
    
    printf("Enter a valid expression: ");
    scanf(" %s ", &EXP);

    int LEN = strlen(EXP);    // Length of expression

    printf("%s", LEN);
    printf("%d", LEN);

    return 0;
}

int infix_to_postfix(char EXP[])
{
    char POSTFIX[100];

    int i = 0;
    while ( EXP[i] != ")" )
    {

        
    }
    return POSTFIX;
}










