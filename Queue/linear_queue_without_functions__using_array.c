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

    MENU(0);

    // main loop
    while ( CHOICE != 5 )
    {
        printf("Select: ");
        scanf(" %d", &CHOICE);

        switch (CHOICE)
        {
            case 0:     // 0 - Menu
                MENU(0);
                break;
                
            case 1:     // 1 - Create
                printf("Queue is alreay created!\n");
                break;
            case 2:     // 2 - Traverse
                TRAVERSE(QUEUE,FRONT,REAR);
                break;
            case 3:     // 3 - Enqueue
                if (!isOVERFLOW(SIZE, REAR))    // Not empty
                {
                    printf("Enter the element to enqueue: ");
                    scanf(" %d", &ELEMENT);
                    if (isUNDERFLOW(FRONT))     // Empty queue
                    {
                        FRONT = REAR = 0;
                        ENQUEUE(QUEUE,REAR,ELEMENT);
                        printf("1st element - %d enqueued successfully!\n", ELEMENT);
                    }
                    else                        // Partially filled queue
                    {
                        REAR++;
                        ENQUEUE(QUEUE,REAR,ELEMENT);
                        printf("%d enqueued successfully!\n", ELEMENT);
                    }
                }
                else                            // Full queue
                    printf("Queue Overflow!\n");
                break;

            case 4:     // 4 - Dequeue
                if (!isUNDERFLOW(FRONT))
                {
                    if (FRONT == REAR)          // Only 1 element in queue
                    {
                        ELEMENT = DEQUEUE(QUEUE,FRONT);
                        printf("%d dequeued successfully!\n", ELEMENT);
                        FRONT = REAR = -1;
                    }
                    else                        // Partially filled queue
                    {
                        ELEMENT = DEQUEUE(QUEUE,FRONT);
                        FRONT++;
                        printf("%d dequeued successfully!\n", ELEMENT);
                    }
                } 
                else                            // Empty queue
                    printf("Queue Underflow!\n");
                break;

            case 5:     // 5 - Exit
                printf("\nTata! See you soon...\n\n");
                return 0;
        }

    }
    return 0;
}

// ENQUEUE function definition
int ENQUEUE (int QUEUE[], int REAR, int ELEMENT)
{
    QUEUE[REAR] = ELEMENT;
    return 0;
}

// DEQUEUE function definition
int DEQUEUE (int QUEUE[], int FRONT)
{
    int ELEMENT = QUEUE[FRONT];
    return ELEMENT;
}

// TRAVERSE function definition
int TRAVERSE (int QUEUE[], int FRONT, int REAR)
{
    if (isUNDERFLOW(FRONT))
    {
        printf("\nEmpty Queue!\n\n");
    }
    else if (FRONT == REAR)
    {
        printf("\nQueue elements:\n");
        printf("\n%d  <--  FRONT\n\n", QUEUE[REAR]);
    }
    else
    {
        printf("\nQueue elements:\n");
        int tmp = FRONT;
        printf("\n%d  <--  FRONT\n", QUEUE[tmp]);
        tmp++;
        while (tmp != REAR)
        {
            printf("%d\n", QUEUE[tmp]);
            tmp++;
        }
        printf("%d  <--  REAR\n\n", QUEUE[tmp]);
    }
    
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