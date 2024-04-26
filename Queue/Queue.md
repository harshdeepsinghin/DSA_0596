# Using Array
## linear_queue_without_functions_using_array.c
### Code
```C
#include <stdio.h>

// Variables Declaration
int SIZE;               // integer identifier for max size of queue
int FRONT = -1;         // integer identifier for queue front
int REAR = -1;          // integer identifier for queue rear
int ELEMENT;            // integer identifier for temp data
int CHOICE = 0;         // integer identifier for selection from menu
int CREATE_QUEUE = 0;   // integer identifier to create queue 

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

    // QUEUE creation
    printf("Enter the size for queue: ");
    scanf(" %d", &SIZE);

    int QUEUE[SIZE];    // array declaration

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
                if (FRONT < 0)              // Empty queue
                {
                    printf("\nEmpty Queue!\n\n");
                }
                else if (FRONT == REAR)     // Single element
                {
                    printf("\nQueue elements:\n");
                    printf("\n%d  <--  FRONT\n\n", QUEUE[REAR]);
                }
                else                        // More than one element
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
```
### Output
```

### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2
Queue is not created yet!
Select: 3
Queue is not created yet!
Select: 4
Queue is not created yet!
Select: 1
Enter the size for queue: 5


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Empty Queue!

Select: 3
Enter the element to enqueue: 45
1st element - 45 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 3
Enter the element to enqueue: 67
67 enqueued successfully!
Select: 3
Enter the element to enqueue: 88
88 enqueued successfully!
Select: 3
Enter the element to enqueue: 99
99 enqueued successfully!
Select: 3
Enter the element to enqueue: 23
23 enqueued successfully!
Select: 3
Queue Overflow!
Select: 2

Queue elements:

45  <--  FRONT
67
88
99
23  <--  REAR

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 4
45 dequeued successfully!
Select: 2

Queue elements:

67  <--  FRONT
88
99
23  <--  REAR

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 4
67 dequeued successfully!
Select: 2

Queue elements:

88  <--  FRONT
99
23  <--  REAR

Select: 4
88 dequeued successfully!
Select: 2

Queue elements:

99  <--  FRONT
23  <--  REAR

Select: 4
99 dequeued successfully!
Select: 2

Queue elements:

23  <--  FRONT

Select: 3
Queue Overflow!
Select: 4
23 dequeued successfully!
Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Empty Queue!

Select: 3
Enter the element to enqueue: 45
1st element - 45 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT

Select: 5

Tata! Come back soon...

```

<div style="page-break-after: always;"></div>

## linear_queue_with_functions_using_array.c
### Code
```C
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
                printf("\nTata! Come back soon...\n\n");
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
                printf("\nTata! Come back soon...\n\n");
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
        case 1: //TODO
            printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Keep the queue empty\n2 - Enqueue multiple elements manually\n3 - Enqueue multiple elements randomly\n4 - Exit\n\n\n");
            break;
    }
}
```

### Output
```

### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2
Queue is not created yet!
Select: 3
Queue is not created yet!
Select: 4
Queue is not created yet!
Select: 1
Enter the size for queue: 5


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Empty Queue!

Select: 3
Enter the element to enqueue: 45
1st element - 45 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 3
Enter the element to enqueue: 67
67 enqueued successfully!
Select: 3
Enter the element to enqueue: 88
88 enqueued successfully!
Select: 3
Enter the element to enqueue: 99
99 enqueued successfully!
Select: 3
Enter the element to enqueue: 23
23 enqueued successfully!
Select: 3
Queue Overflow!
Select: 2

Queue elements:

45  <--  FRONT
67
88
99
23  <--  REAR

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 4
45 dequeued successfully!
Select: 2

Queue elements:

67  <--  FRONT
88
99
23  <--  REAR

Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 4
67 dequeued successfully!
Select: 2

Queue elements:

88  <--  FRONT
99
23  <--  REAR

Select: 4
88 dequeued successfully!
Select: 2

Queue elements:

99  <--  FRONT
23  <--  REAR

Select: 4
99 dequeued successfully!
Select: 2

Queue elements:

23  <--  FRONT

Select: 3
Queue Overflow!
Select: 4
23 dequeued successfully!
Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Empty Queue!

Select: 3
Enter the element to enqueue: 45
1st element - 45 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT

Select: 5

Tata! Come back soon...

```

<div style="page-break-after: always;"></div>

# Using Linked List
## linear_queue_without_functions_using_linked_list.c
### Code
```C
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
```

### Output
```


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2
Queue is not created yet!
Select: 3
Queue is not created yet!
Select: 4
Queue is not created yet!
Select: 1
Enter 1st element: 45


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Queue elements:

FRONT  -->  45  <--  REAR

Select: 3
Enter element: 66
66 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT
66  <--  REAR

Select: 3
Enter element: 88
88 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT
66
88  <--  REAR

Select: 99
Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Queue elements:

45  <--  FRONT
66
88  <--  REAR

Select: 4
45 dequeued successfully!
Select: 2

Queue elements:

66  <--  FRONT
88  <--  REAR

Select: 4
66 dequeued successfully!
Select: 2

Queue elements:

FRONT  -->  88  <--  REAR

Select: 4
88 dequeued successfully!
Select: 2

Empty Queue!

Select: 3
Enter 1st element: 87
1st element - 87 enqueued successfully!
Select: 2

Queue elements:

FRONT  -->  87  <--  REAR

Select: 3
Enter element: 66
66 enqueued successfully!
Select: 2

Queue elements:

87  <--  FRONT
66  <--  REAR

Select: 4
87 dequeued successfully!
Select: 4
66 dequeued successfully!
Select: 4
Queue Underflow!
Select: 2

Empty Queue!

Select: 5

Tata! Come back soon...

```

<div style="page-break-after: always;"></div>

## linear_queue_with_functions_using_linked_list.c
### Code
```C
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
```
### Output
```


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2
Queue is not created yet!
Select: 3
Queue is not created yet!
Select: 4
Queue is not created yet!
Select: 1
Enter 1st element: 45


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Queue elements:

FRONT  -->  45  <--  REAR

Select: 3
Enter element: 66
66 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT
66  <--  REAR

Select: 3
Enter element: 88
88 enqueued successfully!
Select: 2

Queue elements:

45  <--  FRONT
66
88  <--  REAR

Select: 99
Select: 0


### --- MAIN MENU --- ###

0 - Main Menu (this)
1 - Create
2 - Traverse
3 - Enqueue
4 - Dequeue
5 - Exit


Select: 2

Queue elements:

45  <--  FRONT
66
88  <--  REAR

Select: 4
45 dequeued successfully!
Select: 2

Queue elements:

66  <--  FRONT
88  <--  REAR

Select: 4
66 dequeued successfully!
Select: 2

Queue elements:

FRONT  -->  88  <--  REAR

Select: 4
88 dequeued successfully!
Select: 2

Empty Queue!

Select: 3
Enter 1st element: 87
1st element - 87 enqueued successfully!
Select: 2

Queue elements:

FRONT  -->  87  <--  REAR

Select: 3
Enter element: 66
66 enqueued successfully!
Select: 2

Queue elements:

87  <--  FRONT
66  <--  REAR

Select: 4
87 dequeued successfully!
Select: 4
66 dequeued successfully!
Select: 4
Queue Underflow!
Select: 2

Empty Queue!

Select: 5

Tata! Come back soon...

```

<div style="page-break-after: always;"></div>
