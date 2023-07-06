/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 10:41:58 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 12:07:23 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_last_node(t_stack_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

// Rotate the stack. First element will be the last element of the stack.
void	rotate(t_stack_node **stack)
{
	t_stack_node	*new_head;
	t_stack_node	*last_node;

	new_head = (*stack)->next;
	new_head->prev = NULL;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last_node;
	*stack = new_head;
}

// Reverse rotate the stack.
// Last element will be the first element of the stack.
void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*new_head;

	new_head = ft_last_node(*stack);
	(new_head->prev)->next = NULL;
	new_head->prev = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

// Swap the first 2 elements at the top of stack
void	swap(t_stack_node **stack)
{
	int	temp;

	temp = (*stack)->value;
	(*stack)->value = ((*stack)->next)->value;
	(*stack)->next->value = temp;
}

// Push first element at the top of first stack and
// put it at the top of second stack.
void	push(t_stack_node **stack1, t_stack_node **stack2)
{
	t_stack_node	*element;

	element = *stack1;
	if (element)
	{
		*stack1 = element->next;
		(*stack1)->prev = NULL;
		element->next = *stack2;
		(*stack2)->prev = element;
		*stack2 = element;
	}
}
