#include <stdio.h>
#include <stdlib.h>

// Variables Declaration
int SIZE;               // integer identifier for max size of queue
int FRONT = -1;         // integer identifier for queue front
int REAR = -1;          // integer identifier for queue rear
int ELEMENT;            // integer identifier for temp data
int CHOICE = 0;         // integer identifier for selection from menu
int CREATE_QUEUE = 0;   // integer identifier to create queue 

typedef struct node Node;       // Alias for `struct node`
typedef struct node *NodePTR;      // Alias for `struct node *`

// structure definition
struct node
{
    int data;
    NodePTR next;
};

int main (void)
{

    printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");
    
    // before creation loop
    while ( !CREATE_QUEUE )
    {
        printf("Select: ");
        scanf(" %d", &CHOICE);

        switch (CHOICE)
        {
            case 0:
                printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");
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
    


    printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");

    // main loop
    while ( CHOICE != 5 )
    {
        printf("Select: ");
        scanf(" %d", &CHOICE);

        switch (CHOICE)
        {
            case 0:     // 0 - Menu
                printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");
                break;
                
            case 1:     // 1 - Create
                printf("Queue is alreay created!\n");
                break;
            case 2:     // 2 - Traverse
                if (FRONT < 0)
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
                break;
            case 3:     // 3 - Enqueue
                if (!(REAR == SIZE-1))    // Not empty
                {
                    printf("Enter the element to enqueue: ");
                    scanf(" %d", &ELEMENT);
                    if (FRONT < 0)     // Empty queue
                    {
                        FRONT = REAR = 0;
                        QUEUE[REAR] = ELEMENT;
                        printf("1st element - %d enqueued successfully!\n", ELEMENT);
                    }
                    else                        // Partially filled queue
                    {
                        REAR++;
                        QUEUE[REAR] = ELEMENT;
                        printf("%d enqueued successfully!\n", ELEMENT);
                    }
                }
                else                            // Full queue
                    printf("Queue Overflow!\n");
                break;

            case 4:     // 4 - Dequeue
                if (!(FRONT < 0))
                {
                    if (FRONT == REAR)          // Only 1 element in queue
                    {
                        ELEMENT = QUEUE[FRONT];
                        printf("%d dequeued successfully!\n", ELEMENT);
                        FRONT = REAR = -1;
                    }
                    else                        // Partially filled queue
                    {
                        ELEMENT = QUEUE[FRONT];
                        FRONT++;
                        printf("%d dequeued successfully!\n", ELEMENT);
                    }
                } 
                else                            // Empty queue
                    printf("Queue Underflow!\n");
                break;

            case 5:     // 5 - Exit
                printf("\nTata! Come back soon...\n\n");
                return 0;
        }

    }
    return 0;
}