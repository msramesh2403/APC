#include "apc.h"

// Perform addition of two large numbers
int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int sum;        // Store sum of digits
    int carry = 0;  // Store carry value
    int digit;      // Store result digit

    // Traverse both operands from LSB to MSB
    while(tail1 != NULL || tail2 != NULL)
    {
        // Initialize sum with previous carry
        sum = carry;

        // Add digit from first operand
        if(tail1 != NULL)
        {
            sum = sum + tail1->data;
            tail1 = tail1->prev;
        }

        // Add digit from second operand
        if(tail2 != NULL)
        {
            sum = sum + tail2->data;
            tail2 = tail2->prev;
        }

        // Extract result digit and carry
        digit = sum % 10;
        carry = sum / 10;

        // Store result digit
        insert_at_first(headR, tailR, digit);
    }

    // Insert remaining carry
    if(carry)
    {
        insert_at_first(headR, tailR, carry);
    }

    return SUCCESS;
}