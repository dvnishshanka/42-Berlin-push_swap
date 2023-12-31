/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:25:47 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:25:49 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotate the stack.
// Last element will be the first element of the stack.
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*new_head;

	if (!stack || (ft_last_node(*stack)->current_pos) == 0)
		return ;
	new_head = ft_last_node(*stack);
	(new_head->prev)->next = NULL;
	new_head->prev = NULL;
	new_head->next = *stack;
	(*stack)->prev = new_head;
	*stack = new_head;
	insert_node_pos(*stack);
}

// Reverse rotate the stack a.
void	rra(t_stack_node **a)
{
	if (*a)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

// Reverse rotate the stack a.
void	rrb(t_stack_node **b)
{
	if (*b)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

// Reverse rotate both stacks.
void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (*a && *b)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}
