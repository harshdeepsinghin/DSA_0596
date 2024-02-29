#include <stdio.h>

// Functions declaration

int PUSH ( int STACK[], int SIZE, int TOP, int ELEMENT );   // push (insert) an element
int POP ( int STACK[], int SIZE, int TOP );                 // pop (remove) the top element
int PEAK ( int STACK[], int SIZE, int TOP );                // print the value of top
int TRAVERSE ( int STACK[], int SIZE, int TOP );            // print all the values
int CREATE ( int STACK[], int SIZE, int TOP );

int main (void)
{
    // Variables declaration

    int SIZE;
    int TOP = -1;

    // Stack creation
    printf("Enter the size for a stack: ");
    scanf(" %d", &SIZE);
    
    // Static Stack declaration
    int STACK[SIZE];
    return 0;
}

int PUSH ( int STACK[], int SIZE, int TOP, int ELEMENT )
{
    if ( TOP == SIZE - 1 )
        return 1;    // OVERFLOW
    else
        STACK[TOP+1] = ELEMENT;
    return 0;
}

int POP ( int STACK[], int SIZE, int TOP )
{
    if ( TOP < 0 )
        return 1;    // UNDERFLOW
    else
    {
        int DATA = STACK[TOP];
        TOP--;
    }
    return DATA;
}

