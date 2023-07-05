#include "push_swap.h"

// Print the error message
void    print_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

// Convert a string into a long integer
long int ft_atol(const char *str)
{
    long int num;
    int sign;

    sign = 1;
    num = 0;
    if (*str && *str == '-')
    {
        sign = -1;
        str ++;
    }
    while (*str)
    {
        if (*str > '9' || *str < '0')
        {
            print_error();
        }
        num *= 10;
        num += *str - '0';
        str ++;
    }
    return (num * (sign));
}

