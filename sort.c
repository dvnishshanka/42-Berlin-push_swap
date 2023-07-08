
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

// This sort is applied if the stack size > 3
void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int				stack_a_len;

	stack_a_len = (ft_last_node(*a)->current_pos) + 1;
	while (stack_a_len > 3)
	{
		pb(a, b);
		stack_a_len --;
	}
	small_sort(a);
	update_target_nodes(b, *a);
	add_above_median(*b, (ft_last_node(*b)->current_pos) + 1);
	add_above_median(*a, stack_a_len);
	cal_push_price(*a, *b);
}