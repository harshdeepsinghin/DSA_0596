#include <stdio.h>

// Functions Declaration
void MENU (int SUBMENU);                              // menu function
int isOVERFLOW(int SIZE, int REAR);                   // full queue check
int isUNDERFLOW(int FRONT);                           // empty queue check
int ENQUEUE (int QUEUE[], int REAR, int ELEMENT);     // insert element to queue
int DEQUEUE (int QUEUE[], int FRONT);                 // delete element from queue
int TRAVERSE (int QUEUE[], int FRONT, int REAR);      // display all items of queue 

// Variables Declaration
int SIZE;               // integer identifier for max size of queue
int FRONT = -1;         // integer identifier for queue front
int REAR = -1;          // integer identifier for queue rear
int ELEMENT;            // integer identifier for temp data
int CHOICE = 0;         // integer identifier for selection from menu
int CREATE_QUEUE = 0;   // integer identifier to create queue 

int main (void)
{

    MENU(0);
    
    // before creation loop
    while ( !CREATE_QUEUE )
    {
        printf("Select: ");
        scanf(" %d", &CHOICE);

        switch (CHOICE)
        {
            case 0:
                MENU(0);
                break;
                
            case 1:
                CREATE_QUEUE = 1;
                break;

            case 2:
            case 3:
            case 4:
                printf("Queue is not created yet!\n");
                break;

            case 5:
                printf("\nTata! See you soon...\n\n");
                return 0;
        }

    }

    // QUEUE creation
    printf("Enter the size for queue: ");
    scanf(" %d", &SIZE);

    int QUEUE[SIZE];    // array declaration

    MENU(0)
    // main loop
    while ( CHOICE != 5 )
    {
        printf("Select: ");
        scanf(" %d", &CHOICE);

        switch (CHOICE)
        {
            case 0:
                MENU(0);
                break;
                
            case 1:
                printf("Queue is alreay created!\n");
                break;
            case 2:
                TRAVERSE(QUEUE,FRONT,REAR);
            case 3:
                printf("Enter the element to enter: ");
                scanf(" %d", )
            case 4:
                printf("Queue is not created yet!\n");
                break;

            case 5:
                printf("\nTata! See you soon...\n\n");
                return 0;
        }

    }
    return 0;
}

// ENQUEUE function definition
int ENQUEUE (int QUEUE[], int REAR, int ELEMENT)
{
    if ( !isOVERFLOW(SIZE, REAR) )
    {
        REAR++;
        QUEUE[REAR] = ELEMENT;
        return 0;
    } 
    return 1;
}

// DEQUEUE function definition
int DEQUEUE (int QUEUE[], int FRONT)
{
    if ( !isUNDERFLOW(FRONT) )
    {
        int ELEMENT = QUEUE[FRONT];
        FRONT++;
        return ELEMENT;
    } 
    return -1;
}

// TRAVERSE function definition
int TRAVERSE (int QUEUE[], int FRONT, int REAR)
{
    int tmp = FRONT;
    do
    {
        printf("%d", QUEUE[tmp]);
    } while ( tmp != REAR);
    return 0;
}

// isOVERFLOW function definition
int isOVERFLOW(int SIZE, int REAR)
{
    if ( REAR == SIZE-1 )
        return 1;
    else
        return 0;
}

// isUNDERFLOW function definition
int isUNDERFLOW(int FRONT)
{
    if ( FRONT < 0 )
        return 1;
    else
        return 0;
}

void MENU (int SUBMENU)
{
    switch (SUBMENU)
    {
        case 0:
            printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");
            break;
        case 1:
            printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Keep the queue empty\n2 - Enqueue multiple elements manually\n3 - Enqueue multiple elements randomly\n4 - Exit\n\n\n");
            break;
    }
}






