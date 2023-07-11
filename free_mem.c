/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:23:22 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:23:34 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free the allocated memory of array of strings.
// If el == 0, memory is allocated for all strings inside the array.
void	ft_free_array(char **str, int el)
{
	int	i;

	i = 1;
	while (i < el || (el == 0 && str[i]))
	{
		free(str[i]);
		i ++;
	}
	free(str);
}

// Free the allocated memory for the list
void	ft_free_stack(t_stack_node *a)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	next_node = a;
	while (next_node)
	{
		current_node = next_node;
		next_node = current_node->next;
		free(current_node);
	}
}

// Free stack and array
void	free_all(t_stack_node *a, char **argv, int free_argv)
{
	ft_free_stack(a);
	if (free_argv)
		ft_free_array(argv, 0);
}

// Print the error message
void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

// Free the stack, array and print error
void	free_n_print_error(t_stack_node *a, char **argv, int free_argv)
{
	free_all(a, argv, free_argv);
	print_error();
}
