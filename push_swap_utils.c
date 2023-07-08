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

// Convert a string into a long integer. In case of an error "2147483648" number is returned.
long int	ft_atol(const char *str)
{
	long int	num;
	int			sign;

	sign = 1;
	num = 0;
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
	size_t 			target_val;
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
}