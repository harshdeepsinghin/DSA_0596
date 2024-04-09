#include <stdio.h>

// typedef

typedef char *string;

// Variables declaration

string DATA_FILE = "data/one_liner_notes.csv";


int main (int argc, char* argv[])
{
    FILE *checker, *fptr;   // FILE pointers declaration

    checker = fopen(DATA_FILE, "r");

    if (checker == NULL)
    {
        fclose(checker);
        string attributes = "hey, hi, hello";
        fptr = fopen(DATA_FILE, "a+");
        fputs(attributes, fptr);
        fclose(fptr);
    }
    printf("You have entered %d arguments.\n", argc);
    
    while (argc > 1)
    {
        while (argv[1][0] == '-')
        {
            switch (argv[1][1])
            {
                case 'a':
                    printf("a is %s\n", argv[2]);
                    break;
                case 'b':
                    printf("b is %s\n", argv[2]);
                    break;
                default:
                    printf("default\n");
                    break;
            }
            argv++;
            argc--;
        }
        argv++;
        argc--;
    }
    
    return 0;
}



