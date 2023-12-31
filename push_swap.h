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

typedef struct s_stack_node {
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	int					value;
	size_t				current_pos;
	size_t				push_price;
	int					target_node;
	size_t				ra;
	size_t				rb;
	size_t				rr;
	size_t				rra;
	size_t				rrb;
	size_t				rrr;
}	t_stack_node;

///////// Support functions ////////

long int		ft_atol(const char *str);
char			**ft_split(char *str, char sep);
void			print_error(void);
int				find_small_num(int num1, int num2);

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
void			small_sort(t_stack_node **stack);
void			big_sort(t_stack_node **a, t_stack_node **b);
void			update_target_nodes(t_stack_node **b, t_stack_node *a);
void			cal_push_price(t_stack_node	*a, t_stack_node *b);
void			reset_node_data(t_stack_node *stack);
size_t			cal_price_from(size_t pos, size_t length, char dir);
void			insert_push_op(t_stack_node *a, t_stack_node *b);
void			reset_seq(t_stack_node *stack);

// Util Functions
int				check_duplicate(long int num, t_stack_node *a);
int				is_stack_sorted(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack);
t_stack_node	*ft_last_node(t_stack_node *stack);

// Freeing the memory
void			ft_free_array(char **str, int el);
void			free_all(t_stack_node *a, char **argv, int free_argv);
void			free_n_print_error(t_stack_node *a, char **argv, int free_argv);

// Printing
void			print_list(t_stack_node *list, char *msg);

#endif
