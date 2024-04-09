#include <stdio.h>
#include <string.h>
// typedef

typedef char *string;

// Variables declaration

string DATA_FILE = "data/one_liner_notes.csv";

// Functions declaration

void help(string argv[]);

int main (int argc, char *argv[])
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
    
    if ((argc == 1) || (argv[1][0] == '-'))
    {
        help(argv);
    }  
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (i == argc - 1)
                printf("%s", argv[i]);
            else
                printf("%s ", argv[i]);
        }
    }
    
    
    return 0;
}

void help(char *argv[])
{
    printf("Usage:\n\t%s I love penguins\n\nBasic options:\n--help, -h\t\tPrints this help guide.", argv[0]);
}



