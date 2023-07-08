/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:24:48 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:24:57 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// 'above median' = 0 by default. If the node is above median it is set to '1'.
typedef struct s_stack_node {
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					value;
	size_t				current_pos;
	size_t				push_price;
	int					target_node;
	int					above_median;
}	t_stack_node;

///////// Support functions ////////

long int		ft_atol(const char *str);
char			**ft_split(char *str, char sep);
void			print_error(void);

// Initialize the stack
t_stack_node	*init_stack(t_stack_node *a, char **argv, int free_argv);
void			insert_node_pos(t_stack_node *stack);

// Stack operations
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);

void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

size_t			find_target_node(t_stack_node *stack, int value);
int				is_stack_sorted(t_stack_node *stack);
t_stack_node	*ft_last_node(t_stack_node *stack);
void			small_sort(t_stack_node **stack);
void			big_sort(t_stack_node **a, t_stack_node **b);
void			update_target_nodes(t_stack_node **b, t_stack_node *a);
void			add_above_median(t_stack_node *stack, size_t length);
void			cal_push_price(t_stack_node	*a, t_stack_node *b);
// Freeing the memory
void			ft_free_stack(t_stack_node *a);
void			ft_free_array(char **str, int el);


void	print_list(t_stack_node *list, char *msg);
#endif
