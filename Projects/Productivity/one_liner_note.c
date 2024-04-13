#include <stdio.h>
#include <string.h>
#include <cjson/cJSON.h>
#include <time.h>

// typedef
typedef char *string;

// Variables declaration
string DATA_FILE = "data/one_liner_notes.csv";

// Functions declaration
void help(string argv[]);

// main function
int main (int argc, string argv[])
{
    FILE *checker, *fptr;   // FILE pointers declaration

    checker = fopen(DATA_FILE, "r");

    if (checker == NULL)
    {
        fclose(checker);
        string attributes = "Date,Time,Note,Category";
        fptr = fopen(DATA_FILE, "a+");
        fputs(attributes, fptr);
    }

    cJSON *json = cJSON_CreateObject(); 
    cJSON_AddStringToObject(json, "name", "John Doe"); 
    cJSON_AddNumberToObject(json, "age", 30); 
    cJSON_AddStringToObject(json, "email", "john.doe@example.com");
    
    if ((argc == 1) || (strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"-h") == 0))
    {
        help(argv);
    }  
    else
    {
        while (argc > 1)
        {
            while (argv[1][0] == '-')
            {
                switch (argv[1][1])
                {
                    case 'c':
                        printf("c is %s\n", argv[2]);
                        break;
                    case 'v':
                        printf("v is %s\n", argv[2]);
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
    }
    // TODO

    fclose(fptr);

    return 0;
}

void help(char *argv[])
{
    printf("Usage:\n\t%s I love penguins\n\nBasic options:\n--help, -h\t\tPrints this help guide.", argv[0]);
}



