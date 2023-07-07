/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:41:58 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/07 13:37:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns  the last node of the stack
t_stack_node	*ft_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

// Check whether the stack is sorted. Returns 1 if it is not sorted.
int is_stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
