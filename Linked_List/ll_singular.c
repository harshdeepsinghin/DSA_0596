#include <stdio.h>
#include <stdlib.h>

// typedef Declaration of Structures

typedef struct node
{
    int data;
    struct node *next;
} Node;       // Alias for `struct node`


typedef Node *NodePTR;      // Alias for `struct node *`



// Functions Declaration

int MENU (int SUBMENU);    // menu function declaration
NodePTR creation (NodePTR head, NodePTR newnode);    // creation function declaration
NodePTR traverse (NodePTR head);    // traverse function declaration


int main (void)
{
    int SLL_DECLARED = 0;    // identifier to check whether the Singular Linked List is declared or not 
    int SLL_DEFINED = 0;     // identifier to check whether the Singular Linked List is defined or not
    int QUERY1 = -1;
    
    NodePTR head = NULL;
    NodePTR newnode;

    MENU(1);
    QUERY1 = -1;
    while ( QUERY1 != 5 )
    {
        printf("Query: ");
        scanf(" %d",&QUERY1);
        switch (QUERY1)
        {
            case 0:
                MENU(1);
                break;
            case 1:
                if ( head == NULL )
                    creation (head,newnode);
                break;
            case 2:    // 2 - Traverse a linked list
            case 3:    // 3 - Insert elements into a linked list
            case 4:    // 4 - Delete elements from a linked list
                printf("\nNot implemented yet!\n\n");
                break;
            case 5:    // 5 - Exit
                printf("\nTata! See you soon..\n\n");
                return 0;
                break;
            default:
                printf("\nInvalid option!\n\n");
                break;

        }
    }

    return 0;
}

NodePTR creation (NodePTR head, NodePTR newnode)
{
    char terminate;
    int data;

    head = NULL;
    
    printf("Wants to put data? (y/n): ");
    scanf(" %c", &terminate);

    while ( terminate != 'n' || terminate != 'N' )
    {
        NodePTR ptr; 
        newnode = (NodePTR)malloc(sizeof(Node));
        if (newnode == NULL)    // malloc return NULL
        {
            printf("\nInsufficient Memory!\n\n");
            break;
        }
        else if ( head == NULL )    // List is empty
        {
            printf("Enter data: ");
            scanf(" %d", &newnode->data);
            newnode->next = NULL;
            head = newnode;
        }
        else  // List have nodes
        {
            ptr = head;
            while ( ptr->next != NULL )
                ptr = ptr->next;
            ptr->next = newnode;

            printf("Enter data: ");
            scanf(" %d", &newnode->data);
            newnode->next = NULL;
        }
        
        printf("Wants to put data? (y/n): ");
        scanf(" %c", &terminate);
    }
    return 0;
}

NodePTR traverse (NodePTR head)
{
    NodePTR ptr = head;
    while ( ptr->next != NULL )
    {
        if ( ptr == head )
            printf("HEAD -> [ %d ]", ptr->data);
        else
        {
            ptr = ptr->next;
            printf("-> [ %d ]", ptr->data);
        }
    }
    return 0;
}

/*
Here i am using a scheme of submenus due to which there is case 11 after case 1 which shows its the case of 1 from case 1.
Basically the case option will be readed left to right to understand which option is selected.
For example, if there is a case 125, it means that its the the 5th option selected from the 2nd option's menu from 1st option's menu.
*/

int menu (int submenu)
    {
        switch (submenu)
        {
            case 1:
                printf("\n\n### --- MAIN MENU --- ###\n\n0 - Main Menu (this)\n1 - Create a singular linked list\n2 - Traverse a linked list\n3 - Insert elements into a linked list\n4 - Delete elements from a linked list\n5 - Exit\n\n\n");
                break;
            case 11:
                printf("\n\n### --- CREATION MENU --- ###\n\n0 - Creation Menu (this)\n1 - Input elements\n2 - Random elements\n3 - Exit\n\n\n");
                break;
            case 13:
                printf("\n\n### --- INSERTION MENU --- ###\n\n0 - Insertion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - At a particular location\n4 - Before or after an element\n5 - Back to previous menu\n6 - Exit\n\n\n");
                break;
            case 134:
                printf("\n\n### --- BEFORE OR AFTER AN ELEMENT MENU --- ###\n\n0 - Before or after an element Menu (this)\n1 - Before an element\n2 - After an element\n3 - Back to previous menu\n4 - Exit\n\n\n");
                break;
            case 14:
                printf("\n\n### --- DELETION MENU --- ###\n\n0 - Deletion Menu (this)\n1 - At the beginning\n2 - At the end\n3 - At a particular location\n4 - Before or after an element\n5 - Back to previous menu\n6 - Exit\n\n\n");

        }
        
        return 0;
    }