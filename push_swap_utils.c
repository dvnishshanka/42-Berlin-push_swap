/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:24:22 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:24:27 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Print the error message
void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

// Convert a string into a long integer.
// In case of an error "2147483648" number is returned.
long int	ft_atol(const char *str)
{
	long int	num;
	int			sign;

	sign = 1;
	num = 0;
	if (!*str)
		return (2147483648);
	if (*str && *str == '-')
	{
		sign = -1;
		str ++;
	}
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (2147483648);
		num *= 10;
		num += *str - '0';
		str ++;
	}
	return (num * (sign));
}

void	update_target_nodes(t_stack_node **b, t_stack_node *a)
{
	size_t			target_val;
	t_stack_node	*curr_node;

	if (!(*b))
		return ;
	curr_node = *b;
	while (curr_node)
	{
		target_val = find_target_node(a,curr_node->value);
		curr_node->target_node = target_val;
		curr_node = curr_node->next;
	}
	add_above_median(*b, (ft_last_node(*b)->current_pos) + 1);
	add_above_median(a, (ft_last_node(a)->current_pos) + 1);
	cal_push_price(a, *b);
}

// Reset rotation details, push_price, target_node, above_median
void	reset_node_data(t_stack_node *stack)
{
	while (stack)
	{
		stack->push_price = 0;
		stack->target_node = 0;
		stack->pos = 'd';
		stack->ra = 0;
		stack->rb = 0;
		stack->rr = 0;
		stack->rra = 0;
		stack->rrb = 0;
		stack->rrr = 0;
		stack = stack->next;
	}
}
