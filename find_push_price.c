/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_push_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:20:41 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:20:44 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_node(t_stack_node *stack, size_t target)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->current_pos == target)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// Calculate push_price to bring the target node from rotating.
size_t	cal_price_from(size_t pos, size_t length, char dir)
{
	if (dir == 'u')
		return (pos);
	else
		return (length - pos);
}

void	cal_push_price(t_stack_node	*a, t_stack_node *b)
{
	t_stack_node	*target_node;
	size_t			a_pos;
	size_t			b_pos;

	if (!a || !b)
		return ;
	while (b)
	{
		target_node = find_node(a, b->target_node);
		a_pos = target_node->current_pos;
		b_pos = b->current_pos;
		if (a_pos == 0 && b_pos == 0)
			b->push_price = 1;
		else
			insert_push_op(a,b);
		if (b->push_price == 1)
			break ;
		b = b->next;
	}
}
