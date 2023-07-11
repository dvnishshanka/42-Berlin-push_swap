/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_push_price2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:08:01 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/11 10:08:04 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Set push price and operation details if a and b are both rotated
// to bring to the top of the stack
static size_t	set_push_price_tt(t_stack_node *stack,
	size_t a_top, size_t b_top)
{
	reset_seq(stack);
	stack->rr = find_small_num(a_top, b_top);
	stack->rb = b_top - stack->rr;
	stack->ra = a_top - stack->rr;
	stack->push_price = stack->rr + stack->rb + stack->ra + 1;
	return (stack->push_price);
}

// Set push price and operation details if a and b are both reverse rotated
// to bring to the top of the stack
static size_t	set_push_price_bb(t_stack_node *stack,
	size_t a_bot, size_t b_bot)
{
	reset_seq(stack);
	stack->rrr = find_small_num(a_bot, b_bot);
	stack->rrb = b_bot - stack->rrr;
	stack->rra = a_bot - stack->rrr;
	stack->push_price = stack->rrr + stack->rrb + stack->rra + 1;
	return (stack->push_price);
}

// Set push price and operation details if a rotated b reverse rotated
// to bring to the top of the stack
static size_t	set_push_price_tb(t_stack_node *stack,
	size_t a_top, size_t b_bot)
{
	reset_seq(stack);
	stack->ra = a_top;
	stack->rrb = b_bot;
	stack->push_price = stack->ra + stack->rrb + 1;
	return (stack->push_price);
}

// Set push price and operation details if a reverse rotated b rotated
// to bring to the top of the stack
static size_t	set_push_price_bt(t_stack_node *stack,
	size_t a_bot, size_t b_top)
{
	reset_seq(stack);
	stack->rra = a_bot;
	stack->rb = b_top;
	stack->push_price = stack->rra + stack->rb + 1;
	return (stack->push_price);
}

// Calculate the minimum push price
void	insert_push_op(t_stack_node *a, t_stack_node *b)
{
	size_t	a_top;
	size_t	a_bot;
	size_t	b_top;
	size_t	b_bot;
	size_t	push_price;

	a_top = cal_price_from((b->target_node),
			ft_last_node(a)->current_pos + 1, 'u');
	a_bot = cal_price_from((b->target_node),
			ft_last_node(a)->current_pos + 1, 'd');
	b_top = cal_price_from(b->current_pos,
			ft_last_node(b)->current_pos + 1, 'u');
	b_bot = cal_price_from(b->current_pos,
			ft_last_node(b)->current_pos + 1, 'd');
	push_price = set_push_price_tt(b, a_top, b_top);
	if (push_price > (a_bot + b_bot - find_small_num(a_bot, b_bot)))
		push_price = set_push_price_bb(b, a_bot, b_bot);
	if (push_price > (a_top + b_bot))
		push_price = set_push_price_tb(b, a_top, b_bot);
	if (push_price > (a_bot + b_top))
		push_price = set_push_price_bt(b, a_bot, b_top);
}
