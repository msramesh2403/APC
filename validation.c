#include "apc.h"

// Validate operand entered by the user
int validate_number(char *str)
{
    // Check for empty string
    if(str[0] == '\0')
    {
        return FAILURE;
    }

    int i = 0;

    // Skip sign character if present
    if(str[0] == '+' || str[0] == '-')
        i = 1;

    // Validate remaining characters as digits
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return FAILURE;
        }

        i++;
    }

    return SUCCESS;
}

// Validate arithmetic operator
int validate_operator(char op)
{
    // Check for supported operators
    if(op == '+' || op == '-' || op == 'x' || op == 'X' || op == '/')
    {
        return SUCCESS;
    }

    return FAILURE;
}