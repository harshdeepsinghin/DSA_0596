#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;       // Alias for `struct node`
typedef struct node *NodePTR;      // Alias for `struct node *`

// structure definition
struct node
{
    int data;
    NodePTR next;
};

// Variables Declaration
int SIZE;               // integer identifier for max size of queue
int FRONT = -1;         // integer identifier for queue front
int REAR = -1;          // integer identifier for queue rear
int ELEMENT;            // integer identifier for temp data
int CHOICE = 0;         // integer identifier for selection from menu
int CREATE_QUEUE = 0;   // integer identifier to create queue 
NodePTR front;
NodePTR rear;
NodePTR newnode; 

// Functions Declaration
void MENU (int SUBMENU);                                        // MENU function
int isOVERFLOW(NodePTR NEWNODE);                                // full queue check
int isUNDERFLOW(NodePTR FRONT);                                 // empty queue check
int ENQUEUE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE);     // insert element to queue
int DEQUEUE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE);     // delete element from queue
int TRAVERSE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE);    // display all items of queue

// main function
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
    

    newnode = (NodePTR)malloc(sizeof(Node));    // memory allocation

    printf("Enter 1st element: ");
    scanf(" %d", &newnode->data);

    newnode->next = NULL;
    front = rear = newnode;

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
                TRAVERSE(front,rear,newnode);
                break;

            case 3:     // 3 - Enqueue
                ENQUEUE(front,rear,newnode);
                break;

            case 4:     // 4 - Dequeue
                DEQUEUE(front,rear,newnode);
                break;

            case 5:     // 5 - Exit
                printf("\nTata! Come back soon...\n\n");
                return 0;
        }

    }
    return 0;
}

// ENQUEUE function definition
int ENQUEUE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE)
{
    if (isUNDERFLOW(FRONT))    // Empty queue
    {
        NEWNODE = (NodePTR)malloc(sizeof(Node));    // memory allocation
        
        if (isOVERFLOW(NEWNODE))    // Overflow
        {
            printf("Queue Overflow!\n");
        }
        else
        {
            printf("Enter 1st element: ");
            scanf(" %d", &NEWNODE->data);
            NEWNODE->next = NULL;
            FRONT = REAR = NEWNODE;

            printf("1st element - %d enqueued successfully!\n", REAR->data);
        }
    }
    else                // Not empty queue
    {
        NEWNODE = (NodePTR)malloc(sizeof(Node));    // memory allocation
        
        if (NEWNODE == NULL)    // Overflow
        {
            printf("Queue Overflow!\n");
        }
        else
        {
            printf("Enter element: ");
            scanf(" %d", &NEWNODE->data);
            NEWNODE->next = NULL;
            REAR->next = NEWNODE;
            REAR = NEWNODE;      // increment to next node

            printf("%d enqueued successfully!\n", REAR->data);
        }
    }
    return 0;
}

// DEQUEUE function definition
int DEQUEUE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE)
{
    if (isOVERFLOW(NEWNODE))   // Empty queue
        printf("Queue Underflow!\n");
    else
    {
        if (FRONT == REAR)          // Only 1 element in queue
        {
            ELEMENT = FRONT->data;
            FRONT = REAR = NULL;
            printf("%d dequeued successfully!\n", ELEMENT);
        }
        else                        // Partially filled queue
        {
            ELEMENT = FRONT->data;
            FRONT = FRONT->next;    // increment to next node
            printf("%d dequeued successfully!\n", ELEMENT);
        }
    } 
    return 0;
}

// TRAVERSE function definition
int TRAVERSE (NodePTR FRONT, NodePTR REAR, NodePTR NEWNODE)
{
    if (isUNDERFLOW(FRONT))                 // Empty queue
    {
        printf("\nEmpty Queue!\n\n");
    }
    else if (FRONT->next == NULL)    // Single element
    {
        printf("\nQueue elements:\n");
        printf("\nFRONT  -->  %d  <--  REAR\n\n", FRONT->data);
    }
    else                            // More than one element
    {
        printf("\nQueue elements:\n");
        NodePTR tmp = FRONT;
        printf("\n%d  <--  FRONT\n", tmp->data);

        tmp = tmp->next;    // increment to next node to skip front
        while (tmp != REAR)
        {
            printf("%d\n", tmp->data);
            tmp = tmp->next;    // increment to next node
        }
        printf("%d  <--  REAR\n\n", tmp->data);
    }
    
    return 0;
}

// isOVERFLOW function definition
int isOVERFLOW(NodePTR NEWNODE)
{
    if (NEWNODE == NULL)    // memory full
        return 1;
    else
        return 0;
}

// isUNDERFLOW function definition
int isUNDERFLOW(NodePTR FRONT)
{
    if (FRONT == NULL)
        return 1;
    else
        return 0;
}


// MENU function definition
void MENU (int SUBMENU)
{
    switch (SUBMENU)
    {
        case 0:
            printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create\n2 - Traverse\n3 - Enqueue\n4 - Dequeue\n5 - Exit\n\n\n");
            break;
        case 1: //TODO
            printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Keep the queue empty\n2 - Enqueue multiple elements manually\n3 - Enqueue multiple elements randomly\n4 - Exit\n\n\n");
            break;
    }
}

