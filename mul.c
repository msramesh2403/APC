#include "apc.h"

// Perform multiplication of two large numbers
int multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = tail2;   // Traverse second operand from LSB
    int shift = 0;

    while(temp2)
    {
        Dlist *temp1 = tail1;   // Traverse first operand from LSB

        Dlist *phead = NULL;    // Partial product list head
        Dlist *ptail = NULL;    // Partial product list tail

        int carry = 0;

        while(temp1)
        {
             // Multiply digits and add carry
            int res = temp2->data * temp1->data + carry;

            insert_at_first(&phead, &ptail, res % 10);

            carry = res / 10;

            temp1 = temp1->prev;
        }

        // Insert remaining carry
        if(carry)
        {
            insert_at_first(&phead, &ptail, carry);
        }

        /* append zeros according to position */
        for(int i = 0; i < shift; i++)
        {
            insert_at_last(&phead, &ptail, 0);
        }

        /* first partial product */
        if(*headR == NULL)
        {
            *headR = phead;
            *tailR = ptail;
        }
        else
        {
            Dlist *sum_head = NULL;     // Addition result head
            Dlist *sum_tail = NULL;     // Addition result tail

            // Add partial product with accumulated result
            addition(*tailR, ptail, &sum_head, &sum_tail);

            // Free old lists
            delete_list(headR, tailR);
            delete_list(&phead, &ptail);

            // Update result list 
            *headR = sum_head;
            *tailR = sum_tail;
        }

        shift++;
        temp2 = temp2->prev;        // Move to next digit of second operand
    }

    return SUCCESS;
}