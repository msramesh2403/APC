#include "apc.h"

// Compare two large numbers represented as DLLs
int compare(Dlist *head1, Dlist *head2)
{
    // Skip leading zeros in first operand
    while(head1 && head1->data == 0 && head1->next)
    {
        head1 = head1->next;
    }

    // Skip leading zeros in second operand
    while(head2 && head2->data == 0 && head2->next)
    {
        head2 = head2->next;
    }

    int len1 = 0, len2 = 0; // Store lengths

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    // Calculate length of first operand
    while(temp1)
    {
        len1++;
        temp1 = temp1->next;
    }

    // Calculate length of second operand
    while(temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    // Compare lengths
    if(len1 > len2)
        return 1;

    if(len1 < len2)
        return -1;

    // Reset pointers for digit comparison
    temp1 = head1;
    temp2 = head2;

    // Compare digit by digit
    while(temp1 && temp2)
    {
        if(temp1->data > temp2->data)
            return 1;

        if(temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Both numbers are equal
    return 0;
}