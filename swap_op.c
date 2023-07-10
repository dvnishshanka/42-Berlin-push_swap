/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:27:18 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:27:23 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack
static void	swap(t_stack_node **stack)
{
	int	temp;

	temp = (*stack)->value;
	(*stack)->value = ((*stack)->next)->value;
	(*stack)->current_pos = 0;
	(*stack)->next->value = temp;
	(*stack)->next->current_pos = 1;
}

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
void	sa(t_stack_node **a)
{
	if (*a && ((*a)->next))
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	sb(t_stack_node **b)
{
	if (*b && ((*b)->next))
	{
		swap(b);
		write(1, "sb\n", 3);
	}
}

// sa and sb at the same time.
void	ss(t_stack_node **a, t_stack_node **b)
{
	if (*a && ((*a)->next) && *b && ((*b)->next))
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}
