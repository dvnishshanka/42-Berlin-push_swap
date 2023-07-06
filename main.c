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

void	print_list(t_stack_node *list)
{
	t_stack_node	*current_node;

	current_node = list;
	while (current_node)
	{
		printf("Node: %d\n", current_node->value);
		current_node = current_node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				free_argv;

	free_argv = 0;
	a = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0' ))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_argv = 1;
	}
	a = init_stack(a, argv, free_argv);
	print_list(a);
	rotate(&a);
	rotate(&a);
	print_list(a);
	reverse_rotate(&a);
	print_list(a);
	swap(&a);
	print_list(a);
	push(&a, &b);
	print_list(a);
	print_list(b);
	if (free_argv)
		ft_free_array(argv, 0);
	ft_free_stack(a);
	return (0);
}
