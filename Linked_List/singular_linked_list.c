#include <stdio.h>
#include <stdlib.h>

// structure definition
struct node
{
    int data;
    struct node *next;
};

// typedef for structure
typedef struct node Node;           // Alias for `struct node`
typedef struct node *NodePTR;       // Alias for `struct node *`


// Variables declaration
NodePTR head;
NodePTR newnode;

// Functions declaration
void create(NodePTR head);
void traverse(NodePTR head);
void insert(int option, NodePTR head);
int isOVERFLOW(NodePTR newnode);
int isUNDERFLOW(NodePTR head);
void menu(int submenu);

int main(void)
{
    create(head);
    traverse(head);
    insert(1, head);
    traverse(head);
    insert(2, head);
    traverse(head);
    insert(3, head);

    return 0;
}

void create(NodePTR HEAD)
{
    newnode = (NodePTR)malloc(sizeof(Node));

    printf("Enter data for 1st node: ");
    scanf(" %d", &newnode->data);

    newnode->next = NULL;

    HEAD = newnode;
}

void traverse(NodePTR HEAD)
{
    if (isUNDERFLOW(HEAD))                 // Empty queue
    {
        printf("\nEmpty List\n\n");
    }
    else                            // More than one element
    {
        printf("\nList elements:\n");
        NodePTR tmp = HEAD;
        printf("\nHead  -->  %d", tmp->data);

        tmp = tmp->next;    // increment to next node to skip first
        while (tmp != NULL)
        {
            printf("  -->  %d\n", tmp->data);
            tmp = tmp->next;    // increment to next node
        }
    }
}

void insert(int option, NodePTR HEAD)
{
    NodePTR tmp = HEAD, tmp_before, tmp_after;
    int QUERY, KEY;
    newnode = (NodePTR)malloc(sizeof(Node));

    if (isOVERFLOW(newnode))
    {
        printf("Overflow!\n");
        return;
    }
    switch (option)
    {
    case 0:
    case 1: // insertion at the beginning
        printf("Enter data: ");
        scanf(" %d", &newnode->data);
        newnode->next = HEAD;
        HEAD = newnode;
        break;

    case 2: // insertion at the end
        while (tmp->next != NULL)
            tmp = tmp->next;
        printf("Enter data: ");
        scanf(" %d", &newnode->data);
        tmp->next = newnode;
        newnode->next = NULL;
        break;

    case 3: // insertion before or after an element
        menu(33);
        printf("Select (Insertion): ");
        scanf(" %d", &QUERY);

        switch (QUERY)
        {
        case 0:
        case 1: // insertion before an element
            printf("Enter the element before which you want to insert: ");
            scanf(" %d", &KEY);
            tmp_before = HEAD;
            while ((tmp_before->next)->data != KEY)
                tmp_before = tmp_before->next;
            tmp_after = tmp_before->next;
            printf("Enter the element to insert: ");
            scanf(" %d", &newnode->data);
            newnode->next = tmp_after;
            tmp_before->next = newnode;
            break;

        case 2: // insertion after an element
            printf("Enter the element after which you want to insert: ");
            scanf(" %d", &KEY);
            tmp_before = HEAD;
            while (tmp_before->data != KEY)
                tmp_before = tmp_before->next;
            tmp_after = tmp_before->next;
            printf("Enter the element to insert: ");
            scanf(" %d", &newnode->data);
            newnode->next = tmp_after;
            tmp_before->next = newnode;
            break;
        }
        break;

    case 4:
        break;
    }
}

// isOVERFLOW function definition
int isOVERFLOW(NodePTR newnode)
{
    if (newnode == NULL) // memory full
        return 1;
    else
        return 0;
}

// isUNDERFLOW function definition
int isUNDERFLOW(NodePTR HEAD)
{
    if (HEAD == NULL)
        return 1;
    else
        return 0;
}

void menu(int submenu)
{
    switch (submenu)
    {
    case 0:
        printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create a singular linked list\n2 - Traverse a linked list\n3 - Insert elements into a linked list\n4 - Delete elements from a linked list\n5 - Exit\n\n\n");
        break;
    case 1:
        printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Input elements\n2 - Random elements\n3 - Exit\n\n\n");
        break;
    case 3:
        printf("\n\n### --- INSERTION MENU --- ###\n\n0 - Insertion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - Before or after an element\n4 - Back to previous menu\n5 - Exit\n\n\n");
        break;
    case 33:
    case 43:
        printf("\n\n### --- BEFORE OR AFTER AN ELEMENT MENU --- ###\n\n0 - Before or after an element Menu (this)\n1 - Before an element\n2 - After an element\n3 - Back to previous menu\n4 - Exit\n\n\n");
        break;
    case 4:
        printf("\n\n### --- DELETION MENU --- ###\n\n0 - Deletion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - Before or after an element\n4 - Back to previous menu\n5 - Exit\n\n\n");
    }
}
