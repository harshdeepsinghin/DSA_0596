## stack_with_functions_using_array.c
### Code
```C
#include <stdio.h>
#include <stdlib.h>

// Functions declaration

int PUSH ( int STACK[], int TOP, int ELEMENT );   // push (insert) an element
int POP ( int STACK[], int TOP );                 // pop (remove) the top element
int TRAVERSE ( int STACK[], int TOP );            // print all the values
int PEAK ( int STACK[], int TOP );                // print the value of top

int isOVERFLOW (int SIZE, int TOP);
int isUNDERFLOW (int TOP);

int MENU (int SUBMENU);

// main function

int main (void)
{
    // Variables declaration

    int SIZE;
    int TOP = -1;
    int QUERY1 = -1;    // identifier to take input in main menu loop
    int QUERY11 = -1;    // identifier to take input in creation menu loop
    int STACK_DECLARED = 0;    // identifier to check whether STACK is declared or not
    int INPUT_NUMBER;          // INPUT_NUMBER is the number of elements to push manually or randomly
    int PREV1 = 0;             // identifier to terminate menu loops, and get back to previous menu
    int ELEMENT;

    MENU(1);
    while ( STACK_DECLARED != 1)
    {
        printf("Query: ");
        scanf(" %d",&QUERY1);
        switch (QUERY1)
        {
            case 0:    // 0 - Main Menu
                MENU(1);
                break;
            case 1:    // 1 - Create
                STACK_DECLARED = 1;
                break;
            case 2:    // 2 - Traverse
            case 3:    // 3 - Push
            case 4:    // 4 - Pop
            case 5:    // 5 - Peak
                printf("\nStack is not created yet!\n\n");
                break;
            case 6:    // 6 - Exit
                printf("\nTata! See you soon..\n\n");
                return 0;
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;

        }
    }

    // Stack creation
    
    do
    {
        printf("Enter the size for a stack: ");
        scanf(" %d", &SIZE);
        if ( SIZE < 0)
        {
            printf("\nInvalid Input! Negative size not possible.\n\n");
        }
        else if ( INPUT_NUMBER == 0 )
        {
            printf("\n0 (zero) size is not possible!\n\n");
        }
        else
            break;
    } while (1);

    // Static Stack declaration

    int STACK[SIZE];

    // CREATION MENU LOOP
    MENU(11);
    while ( QUERY11 != 4 )
    {
        printf("Query (Creation): ");
        scanf(" %d",&QUERY11);
        switch (QUERY11)
        {
            case 0:    // 0 - Creation Menu (this)
                MENU(11);
                break;
            case 1:    // 1 - Keep the stack empty
                printf("\nAn empty stack of size %d created!\n\n", SIZE);
                PREV1 = 1;
                break;
            case 2:    // 2 - Push multiple elements manually
                do
                {
                    printf("Enter the number of elements to push: ");
                    scanf(" %d", &INPUT_NUMBER);
                    if ( INPUT_NUMBER > SIZE || INPUT_NUMBER < 0)
                    {
                        printf("\nInvalid Input! Out of stack size.\n\n");
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
                    for (int i = 0;i < INPUT_NUMBER;i++)
                    {
                        printf("Enter element (%d): ", i);
                        scanf(" %d", &STACK[i]);
                        TOP++;
                        TRAVERSE(STACK,TOP);
                    }
                }
                PREV1 = 1;
                break;
            case 3:    // 3 - Push multiple elements randomly
                do
                {
                    printf("Enter the number of elements to push randomly: ");
                    scanf(" %d", &INPUT_NUMBER);
                    if ( INPUT_NUMBER > SIZE || INPUT_NUMBER < 0)
                    {
                        printf("\nInvalid Input! Out of stack size.\n\n");
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
                    for (int i = 0;i < INPUT_NUMBER;i++)
                    {
                        STACK[i] = rand() % 1000;    // it will return random numbers from 0 to 999
                    }
                }
                TOP = INPUT_NUMBER - 1;
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

    // MAIN MENU LOOP
    
    MENU(1);
    QUERY1 = -1;
    while ( QUERY1 != 6 )
    {
        printf("Query: ");
        scanf(" %d",&QUERY1);
        switch (QUERY1)
        {  
            case 0:
                MENU(1);
                break;
            case 1:    // 1 - Create
                printf("\nStack is already created!\n\n");
                break;
            case 2:    // 2 - Traverse
                TRAVERSE(STACK,TOP);
                break;
            case 3:    // 3 - Push
                if ( !isOVERFLOW(SIZE,TOP) )
                {
                    printf("Enter the element to push: ");
                    scanf(" %d", &ELEMENT);
                    PUSH(STACK,TOP,ELEMENT); 
                    TOP++;
                    printf("\n%d pushed successfully!\n\n", ELEMENT);
                }                
                break;
            case 4:    // 4 - Pop
                if ( !isUNDERFLOW(TOP) )
                {
                    ELEMENT = POP(STACK,TOP);
                    TOP--;
                    printf("\n%d popped successfully!\n\n", ELEMENT);
                }                
                break;
            case 5:    // 5 - Peak
                if ( !isUNDERFLOW(TOP) )
                {
                    PEAK(STACK,TOP);
                }
                break;
            case 6:    // 6 - Exit
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



// PUSH function definition

int PUSH ( int STACK[], int TOP, int ELEMENT )
{
    STACK[TOP+1] = ELEMENT;
    return 0;
}

// POP function definition

int POP ( int STACK[], int TOP )
{
    int DATA = STACK[TOP];
    return DATA;
}

// PEAK function definition

int PEAK ( int STACK[], int TOP )
{
    printf("\nTOP  -->  %d\n\n", STACK[TOP]);
    return 0;
}

// Traverse function definition

int TRAVERSE ( int STACK[], int TOP )
{
    if ( TOP == -1 )
    {
        printf("\nStack is empty!\n\n");
        return 404;
    }
    else
    {
        printf("\nStack elements:\n");
        for (int i=TOP; i>=0; i--)
        {
            if ( i == TOP )
                printf("%d  <--  TOP\n", STACK[i]);
            else
                printf("%d\n", STACK[i]);
        }
        printf("\n");
    }
    return 0;
}

// UNDERFLOW checker function

int isUNDERFLOW (int TOP)
{
    if ( TOP < 0 )
    {   
        printf("\nStack is empty! (UNDERFLOW)\n\n");   // UNDERFLOW
        return 1;
    }
    else
        return 0;
}

// OVERFLOW checker function

int isOVERFLOW (int SIZE, int TOP)
{
    if ( TOP+1 == SIZE )
    {
        printf("\nStack is full! (OVERFLOW)\n\n");   // OVERFLOW
        return 1;
    }
    else
        return 0;
}

// menu function defition

int MENU (int SUBMENU)
{
    switch (SUBMENU)
    {
        case 1:
            printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Push\n4 - Pop\n5 - Peak\n6 - Exit\n\n\n");
            break;
        case 11:
            printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Keep the stack empty\n2 - Push multiple elements manually\n3 - Push multiple elements randomly\n4 - Exit\n\n\n");
            break;
    }
    return 0;
}

/*
Exit Status Codes

0 - Success
1 - Failure
404 - UNDERFLOW, Stack empty, Element not found
405 - OVERFLOW, Stack full

*/
```
### Output
```


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Push
4 - Pop
5 - Peak
6 - Exit


Query: 2

Stack is not created yet!

Query: 3

Stack is not created yet!

Query: 4

Stack is not created yet!

Query: 5

Stack is not created yet!

Query: 1
Enter the size for a stack: 5


### --- CREATION MENU --- ###

0 - Creation Menu (this)
1 - Keep the stack empty
2 - Push multiple elements manually
3 - Push multiple elements randomly
4 - Exit


Query (Creation): 3
Enter the number of elements to push randomly: 3


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Push
4 - Pop
5 - Peak
6 - Exit


Query: 2

Stack elements:
73  <--  TOP
249
807

Query: 3
Enter the element to push: 55

55 pushed successfully!

Query: 2

Stack elements:
55  <--  TOP
73
249
807

Query: 3
Enter the element to push: 56

56 pushed successfully!

Query: 3

Stack is full! (OVERFLOW)

Query: 2

Stack elements:
56  <--  TOP
55
73
249
807

Query: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Push
4 - Pop
5 - Peak
6 - Exit


Query: 4

56 popped successfully!

Query: 2

Stack elements:
55  <--  TOP
73
249
807

Query: 4

55 popped successfully!

Query: 4

73 popped successfully!

Query: 4

249 popped successfully!

Query: 2

Stack elements:
807  <--  TOP

Query: 4

807 popped successfully!

Query: 2

Stack is empty!

Query: 3
Enter the element to push: 67

67 pushed successfully!

Query: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Push
4 - Pop
5 - Peak
6 - Exit


Query: 5

TOP  -->  67

Query: 5

TOP  -->  67

Query: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Push
4 - Pop
5 - Peak
6 - Exit


Query: 6

Tata! See you soon..

```