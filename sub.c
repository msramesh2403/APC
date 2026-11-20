#include "apc.h"

// Perform subtraction of two large numbers
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int data1, data2;   // Store digits
    int borrow = 0;     // Store borrow value
    int diff;           // Store subtraction result


    // Traverse both operands from LSB to MSB
    while (tail1 || tail2)
    {
        data1 = (tail1) ? tail1->data : 0;      //If tail1 exists -> take its digit Else -> assume digit is 0
        data2 = (tail2) ? tail2->data : 0;

        // Apply previous borrow
        data1 = data1 - borrow;

        // Perform subtraction without borrow
        if (data1 >= data2)
        {
            diff = data1 - data2;
            borrow = 0;
        }
        else
        {
            // Perform subtraction with borrow
            diff = (data1 + 10) - data2;
            borrow = 1;
        }

        // Store result digit
        insert_at_first(headR, tailR, diff);

        // Move to previous digits
        if (tail1)
            tail1 = tail1->prev;

        if (tail2)
            tail2 = tail2->prev;
    }

    /* Remove leading zeros */
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    return SUCCESS;
}