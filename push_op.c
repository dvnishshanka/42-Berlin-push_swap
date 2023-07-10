/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:22:39 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:22:42 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push first element at the top of first stack and
// put it at the top of second stack.
static void	push(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*element;

	element = *stack1;
	if (element)
	{
		*stack1 = element->next;
		if (*stack1)
			(*stack1)->prev = NULL;
		if (*stack2)
		{
			element->next = *stack2;
			(*stack2)->prev = element;
		}
		else
		{
			element->next = NULL;
		}
		*stack2 = element;
		insert_node_pos(*stack1);
		insert_node_pos(*stack2);
	}
}

/* Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty. */
void	pa(t_stack_node **b, t_stack_node **a)
{
	if (*b)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
}

/* Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	pb(t_stack_node **a, t_stack_node **b)
{
	if (*a)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
}
