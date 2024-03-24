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
    
    NodePTR front;
    NodePTR rear;
    NodePTR newnode;

    newnode = (NodePTR)malloc(sizeof(Node));    // memory allocation

    printf("Enter 1st element: ");
    scanf(" %d", &newnode->data);

    newnode->next = NULL;
    front = rear = newnode;

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
                if (front == NULL)               // Empty queue
                {
                    printf("\nEmpty Queue!\n\n");
                }
                else if (front->next == NULL)    // Single element
                {
                    printf("\nQueue elements:\n");
                    printf("\nFRONT  -->  %d  <--  REAR\n\n", front->data);
                }
                else                            // More than one element
                {
                    printf("\nQueue elements:\n");
                    NodePTR tmp = front;
                    printf("\n%d  <--  FRONT\n", tmp->data);

                    tmp = tmp->next;    // increment to next node to skip front
                    while (tmp != rear)
                    {
                        printf("%d\n", tmp->data);
                        tmp = tmp->next;    // increment to next node
                    }
                    printf("%d  <--  REAR\n\n", tmp->data);
                }
                break;

            case 3:     // 3 - Enqueue
                if (front == NULL)    // Empty queue
                {
                    newnode = (NodePTR)malloc(sizeof(Node));    // memory allocation
                    
                    if (newnode == NULL)    // Overflow
                    {
                        printf("Queue Overflow!\n");
                    }
                    else
                    {
                        printf("Enter 1st element: ");
                        scanf(" %d", &newnode->data);
                        newnode->next = NULL;
                        front = rear = newnode;

                        printf("1st element - %d enqueued successfully!\n", rear->data);
                    }
                }
                else                // Not empty queue
                {
                    newnode = (NodePTR)malloc(sizeof(Node));    // memory allocation
                    
                    if (newnode == NULL)    // Overflow
                    {
                        printf("Queue Overflow!\n");
                    }
                    else
                    {
                        printf("Enter element: ");
                        scanf(" %d", &newnode->data);
                        newnode->next = NULL;
                        rear->next = newnode;
                        rear = newnode;      // increment to next node

                        printf("%d enqueued successfully!\n", rear->data);
                    }
                }
                break;

            case 4:     // 4 - Dequeue
                if (front == NULL)   // Empty queue
                    printf("Queue Underflow!\n");
                else
                {
                    if (front == rear)          // Only 1 element in queue
                    {
                        ELEMENT = front->data;
                        front = rear = NULL;
                        printf("%d dequeued successfully!\n", ELEMENT);
                    }
                    else                        // Partially filled queue
                    {
                        ELEMENT = front->data;
                        front = front->next;    // increment to next node
                        printf("%d dequeued successfully!\n", ELEMENT);
                    }
                } 
                break;

            case 5:     // 5 - Exit
                printf("\nTata! Come back soon...\n\n");
                return 0;
        }

    }
    return 0;
}