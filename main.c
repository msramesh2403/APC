/*
Name : M S RAMESH
Sec : int26001B
Project : Arbitrary Precision Calculator (APC)
Description : Arbitrary Precision Calculator is used to perform arithmetic operations such as Addition, Subtraction, Multiplication 
and Division on large numbers that exceed the range of built-in data types.The numbers are stored using Doubly Linked Lists, where 
each node represents a single digit, enabling calculations on numbers of arbitrary length.
*/



#include "apc.h"

int main(int argc, char *argv[])
{
    // Variable declarations and sign initialization
    int i, sign1 = 1, sign2 = 1;

    // Store operand strings
    char *op1 = argv[1];
    char *op2 = argv[3];

    // Check sign of first operand
    if(argv[1][0] == '-')
    {
        sign1 = -1;
        op1++;
    }
    else if(argv[1][0] == '+')
    {
        op1++;
    }

    // Check sign of second operand
    if(argv[3][0] == '-')
    {
        sign2 = -1;
        op2++;
    }
    else if(argv[3][0] == '+')
    {
        op2++;
    }

    // DLL pointers for operands and result
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    // Validate command-line argument count
    if (argc != 4)
    {
        printf("Usage : ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    // Validate first operand
    if (validate_number(argv[1]) == FAILURE)
    {
        printf("Invalid Operand1\n");
        return FAILURE;
    }

    // Validate second operand
    if (validate_number(argv[3]) == FAILURE)
    {
        printf("Invalid Operand2\n");
        return FAILURE;
    }

    // Validate operator
    if (validate_operator(argv[2][0]) == FAILURE)
    {
        printf("Invalid Operator\n");
        return FAILURE;
    }

    // Create DLL for first operand
    for(int i=0; op1[i]; i++)
    {
        insert_at_last(&head1, &tail1, op1[i]-'0');
    }

    // Create DLL for second operand
    for(i=0; op2[i]; i++)
    {
        insert_at_last(&head2, &tail2, op2[i]-'0');
    }

    // Display first operand
    printf("Operand1 : ");

    if(sign1 == -1)
        printf("-");

    print_list(head1);

    // Display second operand
    printf("Operand2 : ");

    if(sign2 == -1)
        printf("-");

    print_list(head2);


    switch (argv[2][0])
    {
        // Addition operation
        case '+':
        {
            // Same sign addition
            if(sign1 == sign2)
            {
                // Perform addition
                addition(tail1, tail2, &headR, &tailR);

                printf("Result   : ");

                // Print sign for negative result
                if(sign1 == -1)
                    printf("-");

                // Display result
                print_list(headR);

                return SUCCESS;
            }
            else
            {
                // Compare operands for subtraction
                int ret = compare(head1, head2);

                printf("Result   : ");

                if(ret == 1)
                {
                    // Operand1 is greater
                    subtraction(tail1, tail2, &headR, &tailR);

                    if(sign1 == -1)
                        printf("-");
                }
                else if(ret == -1)
                {
                    // Operand2 is greater
                    subtraction(tail2, tail1, &headR, &tailR);

                    if(sign2 == -1)
                        printf("-");
                }
                else
                {
                    // Operands are equal
                    printf("0\n");
                    return SUCCESS;
                }

                // Display result
                print_list(headR);
                return SUCCESS;
            }
        }

        // Subtraction operation
        case '-':
        {
            // Different sign subtraction
            if(sign1 != sign2)
            {
                // Perform addition
                addition(tail1, tail2, &headR, &tailR);

                printf("Result   : ");

                // Print sign for negative result
                if(sign1 == -1)
                    printf("-");

                // Display result
                print_list(headR);

                return SUCCESS;
            }
            else
            {
                // Compare operands for subtraction
                int ret = compare(head1, head2);

                printf("Result   : ");

                if(ret == 1)
                {
                    // Operand1 is greater
                    subtraction(tail1, tail2, &headR, &tailR);

                    if(sign1 == -1)
                        printf("-");
                }
                else if(ret == -1)
                {
                    // Operand2 is greater
                    subtraction(tail2, tail1, &headR, &tailR);

                    if(sign1 == 1)
                        printf("-");
                }
                else
                {
                    // Operands are equal
                    printf("0\n");
                    return SUCCESS;
                }

                // Display result
                print_list(headR);

                return SUCCESS;
            }
        }
        // Division operation
        case '/':
        {
            // Check for division by zero
            Dlist *temp = head2;

            while(temp && temp->data == 0)
                temp = temp->next;

            if(temp == NULL)
            {
                printf("Division by zero not possible\n");
                return FAILURE;
            }

            // Create quotient list
            Dlist *count_head = NULL;
            Dlist *count_tail = NULL;

            int quotient;

            // Perform division
            quotient = division(&head1, &tail1, head2, tail2, &headR, &tailR);

            // Store quotient in DLL
            if(quotient == 0)
            {
                insert_at_last(&count_head, &count_tail, 0);
            }
            else
            {
                while(quotient)
                {
                    insert_at_first(&count_head, &count_tail, quotient % 10);

                    quotient /= 10;
                }
            }

            // Display result
            printf("Result   : ");

            // Print sign for negative result
            if(sign1 * sign2 < 0)
                printf("-");

            print_list(count_head);

            return SUCCESS;
        }

        // Multiplication operation
        case 'x':
        case 'X':
        {
            // Perform multiplication
            multiplication(head1, tail1, head2, tail2, &headR, &tailR);

            printf("Result   : ");

            // Print sign for negative result
            if(sign1 * sign2 < 0)
                printf("-");

            // Display multiplication result
            print_list(headR);

            return SUCCESS;
        }

        // Invalid operator
        default:
            printf("Operation not supported\n");
            return FAILURE;
        }

        // Display result for addition and subtraction
        printf("Result   : ");
        print_list(headR);

        return SUCCESS;
}
