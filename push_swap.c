#include "push_swap.h"

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && (argv[1][0] == ' ' || argv[1][0] == '\0' )))
        return (0);
    else if (argc == 2)
    {  
        argv = ft_split(argv[1], ' ');
   
    }
    //  printf("%d %s", argc, argv[1]);
    // printf("%ld %ld %ld", ft_atol("346576"), ft_atol("00"), ft_atol("53628961"));
    // printf("%ld", ft_atol("536289618dfbvj"));   
    return (0);
}