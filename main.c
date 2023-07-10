/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:23:47 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:23:58 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack_node *list, char *msg)
{
	t_stack_node	*current_node;

	current_node = list;
	printf("----------Stack %s---------\n", msg);
	while (current_node)
	{
		printf("Node %ld- %d target: %d push_price: %ld above_median: %d",current_node->current_pos, current_node->value, current_node->target_node, current_node->push_price, current_node->pos);
		printf("ra:%ld rb:%ld rr:%ld rra:%ld rrb:%ld prev: %p next: %p\n", current_node->ra, current_node->rb, current_node->rr, current_node->rra, current_node->rrb, current_node->prev, current_node->next);
		current_node = current_node->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				free_argv;
	size_t			stack_length;

	free_argv = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0' ))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_argv = 1;
	}
	a = init_stack(a, argv, free_argv);
	if (is_stack_sorted(a))
	{
		stack_length = (ft_last_node(a)->current_pos) + 1;
		if (stack_length == 2)
			sa(&a);
		else if (stack_length == 3)
			small_sort(&a);
		else if (stack_length > 3)
			big_sort(&a, &b);
	}
	// print_list(a, "a");
	if (free_argv)
		ft_free_array(argv, 0);
	ft_free_stack(a);
	return (0);
}
