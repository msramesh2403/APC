#include "apc.h"


// Insert a node at the end of the doubly linked list
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for new node
    Dlist *new = malloc(sizeof(Dlist));

    // Check memory allocation failure
    if(new == NULL)
        return FAILURE;

    // Initialize new node
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // Insert first node if list is empty
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    // Link new node at the end
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;

    return SUCCESS;
}

// Insert a node at the beginning of the doubly linked list
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    // Allocate memory for new node
    Dlist *new = malloc(sizeof(Dlist));

    // Check memory allocation failure
    if(new == NULL)
        return FAILURE;

    // Initialize new node
    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    // Insert first node if list is empty
    if(*head == NULL)
    {
        *head = *tail = new;
        return SUCCESS;
    }

    // Link new node at the beginning
    new->next = *head;
    (*head)->prev = new;
    *head = new;

    return SUCCESS;
}

// Display all elements of the list
void print_list(Dlist *head)
{
    // Check if list is empty
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Traverse and print each node
    while(head)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}

// Delete all nodes from the list
void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    // Traverse and free each node
    while(*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // Update tail pointer
    *tail = NULL;
}