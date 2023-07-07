/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:25:38 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:25:40 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node in the list
static t_stack_node	*ft_lstnew(int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = 0;
	new_node->prev = 0;
	new_node->current_pos = 0;
	new_node->target_node = 0;
	new_node->push_price = 0;
	return (new_node);
}

// Check for duplicate numbers. Return 0 if there are no duplicate values.
int	check_duplicate(long int num, t_stack_node *a)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next ;
	}
	return (0);
}

// Include index on stack
void	insert_node_pos(t_stack_node *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack->current_pos = i;
		stack = stack->next;
		i ++;
	}
}

// Insert the target_node
void	insert_target_node(t_stack_node *stack)
{
	int value;

	while (stack)
	{
		value = stack->value;
		stack->target_node = find_target_node(stack, value);
		stack = stack->next;
	}
}

// Initialize the stack
t_stack_node	*init_stack(t_stack_node *a, char **argv, int free_argv)
{
	int				i;
	long int		num;
	t_stack_node	*new_node;
	t_stack_node	*prev_node;

	i = 1;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (check_duplicate(num, a) || num > 2147483647 || num < (-2147483648))
		{
			ft_free_stack(a);
			if (free_argv)
				ft_free_array(argv, 0);
			print_error();
		}
		if (i == 1)
		{
			a = ft_lstnew(num);
			prev_node = a;
		}
		else
		{
			new_node = ft_lstnew(num);
			prev_node->next = new_node;
			new_node->prev = prev_node;
			prev_node = new_node;
		}
		i++;
	}
	insert_node_pos(a);
	return (a);
}
