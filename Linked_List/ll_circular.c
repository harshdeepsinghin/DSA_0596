#include <stdio.h>

int menu (int submenu); // menu function declaration

int main (void)
{
    int QUERY; // input literal for the main menu loop
    struct node
    {
        int data;
        struct node *next;
    };
    menu(1); // menu(1);
    QUERY = 0;
    while ( QUERY != 4 )
    {
        printf("Query: ");
        scanf("%d",&QUERY);
        switch (QUERY)
        {  
            case 0:
                menu(1);
                break;
            case 1:
                printf("insert to be implement...\n");
                break;
            case 2:
                printf("delete to be implement...\n");
                break;
            case 3:
                printf("traverse to be implement...\n");
                break;
            case 4:
                printf("\nTata! See you soon...\n");
                break;
            default:
                printf("Invalid option!");
                break;
        }
    }       
}

int menu (int submenu)
    {
        switch (submenu)
        {
            case 1:
                printf("\n\n###--- MAIN MENU ---###\n\n0 - Main Menu (this).\n1 - Insert data.\n2 - Delete data.\n3 - Traverse linked list.\n4 - Exit\n\n\n");
                break;
        }
        
        return 0;
    }