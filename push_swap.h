#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

typedef struct Num_struct {
    struct Num_struct *prev;
    struct Num_struct *next;
    int value;
}   num_struct;

// Support functions
long int ft_atol(const char *str);
char **ft_split(char *str, char sep);

#endif