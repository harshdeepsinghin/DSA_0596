#include <stdio.h>
#include <string.h>
#define MAX 50

int main (void)
{
    char EXP[MAX], S[MAX];
    int TOP = -1, VALID = 0;
    printf("Enter a string with paranthesis: ");
    scanf("%s", EXP);

    int LEN = strlen(EXP);

    for (int i=0; i<LEN; i++)
    {
        if (EXP[i] == "(")
        {
            TOP++;
            S[TOP] = EXP[i];    //Push
        }
        else if (EXP[i] == ")")
        {
            if (TOP<0)
            {
                printf("UNDERFLOW, invalid expression");
                break;
            }
            else
            {
                TOP--;
                VALID++;
            }
        }
    }
    int LONGEST = VALID*2;

    printf("Longest length of valid substring is %d.", LONGEST);
}



