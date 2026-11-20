#include "apc.h"

// Perform division using repeated subtraction
int division(Dlist **head1, Dlist **tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    // Store quotient count
    int count = 0;

    // Continue until dividend becomes smaller than divisor
    while(compare(*head1, head2) != -1)
    {
        // Subtract divisor from dividend
        subtraction(*tail1, tail2, headR, tailR);

        // Delete old dividend list
        delete_list(head1, tail1);

        // Update dividend with subtraction result
        *head1 = *headR;
        *tail1 = *tailR;

        // Reset result pointers for next iteration
        *headR = NULL;
        *tailR = NULL;

        // Increment quotient count
        count++;
    }

    return count;
}