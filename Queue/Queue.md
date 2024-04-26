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

##
