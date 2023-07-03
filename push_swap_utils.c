#include "push_swap.h"

// Print the error message
void    print_error(void)
{
    write(1, "Error\n", 6);
}

// Convert a string into a long integer
long int ft_atol(const char *str)
{
    long int num;

    num = 0;
    while (*str)
    {
        if (*str > '9' || *str < '0')
        {
            print_error();
            exit(1);
            return (0);
        }
        num *= 10;
        num += *str - '0';
        str ++;
    }
    return (num);
}

