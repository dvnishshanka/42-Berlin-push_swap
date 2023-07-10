/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:26:56 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/10 10:27:01 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This sort is applied if the stack size = 3
void	small_sort(t_stack_node **stack)
{
	int	value_1;
	int	value_2;
	int	value_3;

	if (!(*stack))
		return ;
	value_1 = (*stack)->value;
	value_2 = (*stack)->next->value;
	value_3 = (*stack)->next->next->value;
	if (value_2 > value_3 && value_2 > value_1)
	{
		rra(stack);
		if (value_3 > value_1)
			sa(stack);
	}
	else if (value_1 > value_3 && value_1 > value_2)
	{
		ra(stack);
		if (value_2 > value_3)
			sa(stack);
	}
	else if (value_1 > value_2)
		sa(stack);
}

// Find the node where the push_price is smallest
static t_stack_node	*cheepest_node(t_stack_node *stack)
{
	t_stack_node	*cheepest;

	if (!stack)
		return (NULL);
	cheepest = stack;
	while (stack)
	{
		if (stack->push_price < cheepest->push_price)
			cheepest = stack;
		if (cheepest->push_price == 1)
			break ;
		stack = stack->next;
	}
	return (cheepest);
}

// This sort is applied if the stack size > 3
void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int				stack_a_len;
	t_stack_node	*node;
	t_stack_node	*smallest_node;
	size_t			price_from_top;
	size_t			price_from_bot;

	stack_a_len = (ft_last_node(*a)->current_pos) + 1;
	while (stack_a_len > 3)
	{
		pb(a, b);
		stack_a_len --;
	}
	small_sort(a);
	update_target_nodes(b, *a);
	while (*b)
	{
		node = cheepest_node(*b);
		while ((node->ra)--)
		{
			ra(a);}

		while ((node->rb)--)
			rb(b);
		while ((node->rr)--)
			rr(a, b);
		while ((node->rra)--)
			rra(a);
		while ((node->rrb)--)
			rrb(b);
		while ((node->rrr)--)
			rrr(a, b);
		pa(b, a);
		reset_node_data(*b);
		update_target_nodes(b, *a);
	}
	smallest_node = find_smallest(*a);
	price_from_top = cal_price_from(smallest_node->current_pos, (ft_last_node(*a)->current_pos) + 1,'u');
	price_from_bot = cal_price_from(smallest_node->current_pos, (ft_last_node(*a)->current_pos) + 1,'d');
	if (price_from_top < price_from_bot)
	{
		while (price_from_top--)
			ra(a);
	}
	else
	{
		while (price_from_bot--)
			rra(a);
	}
}
