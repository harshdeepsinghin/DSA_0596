#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;           // Alias for `struct node`
typedef struct node *NodePTR;       // Alias for `struct node *`

int main(void)
{
    //creation
    NodePTR head;
    NodePTR newnode;

    int tmp;
    
    newnode = (NodePTR)malloc(sizeof(Node));

    printf("Enter data: ");
    scanf(" %", &newnode->data);

    newnode->next = NULL;

    head = newnode;     // Head linked to first node

    printf("%d", head->data);


    

    return 0;
}


