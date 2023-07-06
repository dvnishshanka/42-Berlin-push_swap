/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:24:48 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:24:57 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node {
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					value;
}	t_stack_node;

///////// Support functions ////////

long int		ft_atol(const char *str);
char			**ft_split(char *str, char sep);
void			print_error(void);
t_stack_node	*init_stack(t_stack_node *a, char **argv, int free_argv);

// Stack operations
void			rotate(t_stack_node **stack);
void			reverse_rotate(t_stack_node **stack);
void			swap(t_stack_node **stack);
void			push(t_stack_node **stack1, t_stack_node **stack2);

// Freeing the memory
void			ft_free_stack(t_stack_node *a);
void			ft_free_array(char **str, int el);
#endif
