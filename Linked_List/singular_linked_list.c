#include <stdio.h>
#include <stdlib.h>

// structure definition
struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    // creation

    struct node *head;
    struct node *newnode;

    head = (struct node *)malloc(sizeof(struct node));

    (head == NULL)?printf("Yes\n"):printf("No\n");

    newnode->data = 20;
    newnode->next = NULL;

    head = newnode;

    printf("%d", head->data);
}






