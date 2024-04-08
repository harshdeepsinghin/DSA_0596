#include <stdio.h>

int main (void)
{
    FILE *checker, *fptr;

    checker = fopen("data/one_liner_notes.csv", "r");

    if (checker == NULL)
    {
        char *str = "hey, hi, hello";
        fptr = fopen("data/one_liner_notes.csv", "a+");
        fputs(str, fptr);
    }

    fclose(checker);
    fclose(fptr);
    
}