#include <stdio.h>
#include <stdlib.h>

// Functions Declaration

int menu (int submenu);    // menu function declaration
int traverse (int ARRAYPARAM[], int ARRAYSIZE, int LOWERBOUND, int UPPERBOUND);       // traverse function declaration

              
/*
TODO

- [ ] Insertion deletion amount

*/

int main (void)
{   
    // Variables Declaration

    int QUERY1;  // input identifier for the main menu loop
    int QUERY11; // input identifier for the creation menu loop
    int QUERY13; // input identifier for the insertion menu loop
    int QUERY134; // input identifier for the insertion - before or after menu loop
    int QUERY14; // input identifier for the deletion menu loop
    int PREV1;   // indentifier to go to previous menu (MAIN MENU)
    QUERY1 = QUERY11 = QUERY13 = QUERY134 = QUERY14 = PREV1 = -1;
    int SIZE;            // SIZE is the max size of array
    int INPUT_NUMBER;    // INPUT_NUMBER is the number of elements to input or generate randomly
    int INPUT_ZERO;      // to check if the input numbers are zero or not
    int LB = 0;     // LB containing index 0
    int UB = -1;    // UB contains the index till the elements are filled
    int ARRAY_DECLARED = 0;       // identifier to check whether the Array is declared or not 
    int ARRAY_DEFINED = 0;        // identifier to check whether the Array is defined or not
    int ELEMENT_FOUND = 0;        // identifier to find element in linear search while insertion or deletion
    int tmp = -1;      // to store the index
    int value = -1;    // to store the value
    
    menu(1);
    while ( ARRAY_DECLARED != 1)
    {
        printf("Query: ");
        scanf(" %d",&QUERY1);
        switch (QUERY1)
        {
            case 0:    // 0 - Main Menu
                menu(1);
                break;
            case 1:    // 1 - Create an array
                ARRAY_DECLARED = 1;
                break;
            case 2:    // 2 - Traverse an array
            case 3:    // 3 - Insert elements into an array
            case 4:    // 4 - Delete elements from an array
                printf("\nArray is not created yet!\n\n");
                break;
            case 5:    // 5 - Exit
                printf("\nTata! See you soon..\n\n");
                return 0;
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;

        }
    }

    printf("Enter the array size: ");
    scanf(" %d", &SIZE);
    int ARRAY[SIZE];    // Array declaration with size SIZE

    menu(11);
    QUERY11 = -1;
    while ( QUERY11 != 4 )    // CREATION MENU LOOP
    {
        printf("Query (Creation): ");
        scanf("%d",&QUERY11);
        switch (QUERY11)
        {
            case 0:    // 0 - Creation Menu (this)
                menu(11);
                break;
            case 1:    // 1 - Input elements
                do
                {
                    printf("Enter the number of elements to input: ");
                    scanf(" %d", &INPUT_NUMBER);
                    if ( INPUT_NUMBER > SIZE || INPUT_NUMBER < 0)
                    {
                        printf("\nInvalid Input! Out of array bound.\n\n");
                    }
                    else if ( INPUT_NUMBER == 0 )
                    {
                        printf("\n0 (zero) elements to input, therefore skipped!\n\n");
                        break;
                    }
                    else
                        break;
                } while (1);
                
                if ( INPUT_NUMBER != 0 )
                {
                    for (int i = LB;i < INPUT_NUMBER;i++)
                    {
                        printf("Enter element (%d): ", i);
                        scanf(" %d", &ARRAY[i]);
                    }
                }
                UB = INPUT_NUMBER - 1;    // UB contains the index of last filled element
                PREV1 = 1;
                break;
            case 2:    // 2 - Random elements
                do
                {
                    printf("Enter the number of elements to generate randomly: ");
                    scanf(" %d", &INPUT_NUMBER);
                    if ( INPUT_NUMBER > SIZE || INPUT_NUMBER < 0)
                    {
                        printf("\nInvalid Input! Out of array bound.\n\n");
                    }
                    else if ( INPUT_NUMBER == 0 )
                    {
                        printf("\n0 (zero) elements to input, therefore skipped!\n\n");
                        break;
                    }
                    else
                        break;
                } while (1);
                
                if ( INPUT_NUMBER != 0 )
                {
                    for (int i = LB;i < INPUT_NUMBER;i++)
                    {
                        ARRAY[i] = rand() % 1000;    // it will return random numbers from 0 to 999
                    }
                }
                UB = INPUT_NUMBER - 1;    // UB contains the index of last filled element
                PREV1 = 1;
                break;
            case 3:    // 3 - Exit
                printf("\nTata! See you soon...\n\n");
                return 0;
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;
        }
        if ( PREV1 == 1 )
        {
            PREV1 = 0;
            break;
        }
    }

// MAIN MENU LOOP
    
    menu(1);
    QUERY1 = -1;
    while ( QUERY1 != 5 )
    {
        printf("Query: ");
        scanf(" %d",&QUERY1);
        switch (QUERY1)
        {  
            case 0:
                menu(1);
                break;
            case 1:    // 1 - Create an array
                printf("\nArray is already created!\n\n");
                break;
            case 2:    // 2 - Traverse an array
                if ( UB == -1 )
                {
                    printf("\nArray is empty (UNDERFLOW). Ready for operations.\n\n");
                }
                else
                {
                    printf("\nArray's elements:");
                    traverse(ARRAY,SIZE,LB,UB);
                }
                
                break;
            case 3:    // 3 - Insert elements into an array
                printf("\nArray's elements:");
                traverse(ARRAY,SIZE,LB,UB);
                menu(13);
                QUERY13 = -1;
                while ( QUERY13 != 6 )
                {
                    if ( UB-LB+1 == SIZE )
                    {
                        printf("\nArray is full! (OVERFLOW) No more elements can be inserted.\n\n");
                        break;
                    } 
                    printf("Query (Insertion): ");
                    scanf("%d",&QUERY13);
                    switch (QUERY13)
                    {
                        case 0:    // 0 - Insertion Menu (this)
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            menu(13);
                            break;
                        case 1:    // 1 - At the beginning
                            for (int i=UB; i>=LB; i--)
                            {
                                ARRAY[i+1] = ARRAY[i];
                            }
                            printf("Enter the element to insert: ");
                            scanf(" %d", &ARRAY[LB]);
                            UB++;
                            break;
                        case 2:    // 2 - At the end
                            printf("Enter the element to insert: ");
                            scanf(" %d", &ARRAY[UB+1]);
                            UB++;
                            break;
                        case 3:    // 3 - At a particular location
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            printf("Enter the index where element to insert: ");
                            scanf(" %d", &tmp);
                            for (int i=UB; i>=tmp; i--)
                            {
                                ARRAY[i+1] = ARRAY[i];
                            }
                            printf("Enter the element to insert: ");
                            scanf(" %d", &ARRAY[tmp]);
                            UB++;
                            break
                        case 4:    // 4 - Before or after an element
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            menu(134);
                            QUERY134 = -1;
                            while ( QUERY134 != 4 )
                            {
                                printf("Query (Insertion - Before or After an element): ");
                                scanf("%d",&QUERY134);
                                switch (QUERY134)
                                {
                                    case 0:    // 0 - Before or after an element Menu (this)
                                        menu(134);
                                        break;
                                    case 1:    // 1 - Before an element
                                        printf("Enter the index of the element before which you want to insert: ");
                                        scanf(" %d", &tmp);
                                        for (int i=UB; i>=tmp; i--)
                                        {
                                            ARRAY[i+1] = ARRAY[i];
                                        }
                                        printf("Enter the element to insert: ");
                                        scanf(" %d", &ARRAY[tmp]);
                                        UB++;
                                        break;
                                    case 2:    // 2 - After an element
                                        printf("Enter the index of the element before which you want to insert: ");
                                        scanf(" %d", &tmp);
                                        for (int i=UB; i>tmp; i--)
                                        {
                                            ARRAY[i+1] = ARRAY[i];
                                        }
                                        printf("Enter the element to insert: ");
                                        scanf(" %d", &ARRAY[tmp+1]);
                                        UB++;
                                        break;
                                    case 3:    // 3 - Back to Main Menu
                                        PREV1 = 1;
                                        break;
                                    case 4:    // 4 - Exit
                                        printf("\nTata! See you soon...\n\n");
                                        return 0;
                                        break;
                                    default:
                                        printf("\nInvalid option!\n\n");
                                        break;
                                }
                                if ( PREV1 == 1 )
                                {
                                    PREV1 = 0;
                                    break;
                                }
                            }
                            break;
                        case 5:    // 5 - Back to Main Menu
                            PREV1 = 1;
                            break;
                        case 6:
                            printf("\nTata! See you soon...\n\n");
                            return 0;
                            break;
                        default:
                            printf("\nInvalid option!\n\n");
                            break;
                    }
                    if ( PREV1 == 1 )
                    {
                        PREV1 = 0;
                        break;
                    }
                }
                break;
            case 4:    // 4 - Delete elements from an array
                printf("\nArray's elements:");
                traverse(ARRAY,SIZE,LB,UB);
                menu(14);
                while ( QUERY14 != 6 )
                {
                    if ( UB < LB )
                    {
                        printf("\nArray is empty! (UNDERFLOW) No more elements can be deleted.\n\n");
                        break;
                    } 
                    printf("Query (Deletion): ");
                    scanf("%d",&QUERY14);
                    switch (QUERY14)
                    {
                        case 0:    // 0 - Deletion Menu (this)
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            menu(14);
                            break;
                        case 1:    // 1 - At the beginning
                            // free(ARRAY[LB]);
                            for (int i=LB; i<=UB; i++)
                            {
                                ARRAY[i] = ARRAY[i+1];    // Array shifted towards left
                            }
                            UB--;
                            printf("Element at the beginning deleted!\n");
                            break;
                        case 2:    // 2 - At the end
                            // free(ARRAY[UB]);
                            UB--;
                            printf("Element at the end deleted!\n");
                            break;
                        case 3:    // 3 - At a particular location
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            tmp = -1;
                            printf("Enter the index of the element to delete: ");
                            scanf(" %d", &tmp);
                            // free(ARRAY[tmp]);
                            for (int i=tmp; i<=UB; i++)
                            {
                                ARRAY[i] = ARRAY[i+1];
                            }
                            UB--;
                            printf("Element at the particular location (index: %d) deleted!\n", tmp);
                            break;
                        case 4:    // 4 - Before or after an element
                            printf("\nArray's elements:");
                            traverse(ARRAY,SIZE,LB,UB);
                            menu(134);
                            QUERY134 = -1;
                            while ( QUERY134 != 4 )
                            {
                                printf("Query (Deletion - Before or After an element): ");
                                scanf("%d",&QUERY134);
                                switch (QUERY134)
                                {
                                    case 0:    // 0 - Before or after an element Menu (this)
                                        menu(134);
                                        break;
                                    case 1:    // 1 - Before an element
                                        printf("Enter the index of the element before which you want to delete: ");
                                        scanf(" %d", &tmp);
                                        for (int i=tmp; i<=UB; i++)
                                        {
                                            ARRAY[i-1] = ARRAY[i];
                                        }
                                        UB--;
                                        printf("Element at the before location (index: %d) deleted!\n", tmp);
                                        break;
                                    case 2:    // 2 - After an element
                                        printf("Enter the index of the element after which you want to delete: ");
                                        scanf(" %d", &tmp);
                                        for (int i=tmp+1; i<=UB; i++)
                                        {
                                            ARRAY[i] = ARRAY[i+1];
                                        }
                                        UB--;
                                        printf("Element at the after location (index: %d) deleted!\n", tmp);
                                        break;
                                    case 3:    // 3 - Back to Main Menu
                                        PREV1 = 1;
                                        break;
                                    case 4:    // 4 - Exit
                                        printf("\nTata! See you soon...\n\n");
                                        return 0;
                                        break;
                                    default:
                                        printf("\nInvalid option!\n\n");
                                        break;
                                }
                                if ( PREV1 == 1 )
                                {
                                    PREV1 = 0;
                                    break;
                                }
                            }
                            break;
                        case 5:    // 5 - Back to Main Menu
                            PREV1 = 1;
                            break;
                        case 6:
                            printf("\nTata! See you soon...\n\n");
                            return 0;
                            break;
                        default:
                            printf("\nInvalid option!\n\n");
                            break;
                    }
                    if ( PREV1 == 1 )
                    {
                        PREV1 = 0;
                        break;
                    }
                }
                break;
            case 5:    // 5 - Exit
                printf("\nTata! See you soon..\n\n");
                return 0;
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;
        }
    }  
    return 0;     
}

int traverse (int ARRAYPARAM[], int ARRAYSIZE, int LOWERBOUND, int UPPERBOUND)
{
    printf("\nIndex\tValue\n");
    for (int i = LOWERBOUND;i <= UPPERBOUND;i++)
    {
        printf("%d\t%d\n",i,ARRAYPARAM[i]);
    }
    printf("\n");
    return 0;
}
/*
Here i am using a scheme of submenus due to which there is case 11 after case 1 which shows its the case of 1 from case 1.
Basically the case option will be readed left to right to understand which option is selected.
For example, if there is a case 125, it means that its the the 5th option selected from the 2nd option's menu from 1st option's menu.
*/

int menu (int submenu)
    {
        switch (submenu)
        {
            case 1:
                printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create an array\n2 - Traverse an array\n3 - Insert elements into an array\n4 - Delete elements from an array\n5 - Exit\n\n\n");
                break;
            case 11:
                printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Input elements\n2 - Random elements\n3 - Exit\n\n\n");
                break;
            case 13:
                printf("\n\n### --- INSERTION MENU --- ###\n\n0 - Insertion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - At a particular location\n4 - Before or after an element\n5 - Back to previous menu\n6 - Exit\n\n\n");
                break;
            case 134:
                printf("\n\n### --- BEFORE OR AFTER AN ELEMENT MENU --- ###\n\n0 - Before or after an element Menu (this)\n1 - Before an element\n2 - After an element\n3 - Back to previous menu\n4 - Exit\n\n\n");
                break;
            case 14:
                printf("\n\n### --- DELETION MENU --- ###\n\n0 - Deletion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - At a particular location\n4 - Before or after an element\n5 - Back to previous menu\n6 - Exit\n\n\n");

        }
        
        return 0;
    }


