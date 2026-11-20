#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Return status */
#define SUCCESS 0
#define FAILURE -1

/* Doubly Linked List Node */
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

/* Validation Functions */
int validate_number(char *str);
int validate_operator(char op);

/* List Functions */
int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
void delete_list(Dlist **head, Dlist **tail);


/* Create Operand Lists */
int create_list(Dlist **head, Dlist **tail, char *str);

/* Addition */
int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Subtraction */
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

int compare(Dlist *head1, Dlist *head2);

/* Multiplication */
int multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Division */
int division(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);


#endif