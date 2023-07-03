#include "push_swap.h"

static int count_words(char *str, char sep)
{
    int word_count;
    int    is_inside_word;

    word_count = 0;
    while (*str)
    {
        is_inside_word = 0;
        while (*str == ' ')
            str ++;
        while (*str != sep && *str)
        {
            if (!is_inside_word)
                word_count ++;
            is_inside_word = 1;
            str ++;
        } 
    }
    return (word_count);
}


char **ft_split(char *str, char sep)
{
    char    **argv;
    int     word_count;
    int     i;

    i = 0;
    word_count = count_words(str, sep);
    argv = (char **)malloc(sizeof (char) * (word_count + 2));
    if (!argv)
        return (NULL);

    while (i < (word_count + 2))
    {
        i 
    }
    printf("%d", word_count);
    return (argv);
}