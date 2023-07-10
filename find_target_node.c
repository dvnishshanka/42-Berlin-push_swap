/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:21:24 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:21:26 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_smallest(t_stack_node *stack)
{
	t_stack_node	*smallest_node;

	if (!stack)
	{
		return (NULL);
	}
	smallest_node = stack;
	while (stack)
	{
		if ((stack->value) < smallest_node->value)
			smallest_node = stack;
		stack = stack->next;
	}
	return (smallest_node);
}

size_t	find_target_node(t_stack_node *stack, int value)
{
	t_stack_node	*target_node;
	t_stack_node	*curr_node;

	target_node = NULL;
	if (!stack)
		return (0);
	curr_node = stack;
	while (curr_node)
	{
		if (((curr_node->value) > value) && (target_node == NULL
				|| (target_node->value > (curr_node->value))))
		{
			target_node = curr_node;
		}
		curr_node = curr_node->next;
	}
	if (!target_node)
		target_node = find_smallest(stack);
	return (target_node->current_pos);
}
