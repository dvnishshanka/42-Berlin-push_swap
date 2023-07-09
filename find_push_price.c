#include "push_swap.h"

// Add the data whether the node is above the median or not
void	add_above_median(t_stack_node *stack, size_t length)
{
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->current_pos == 0)
			stack->pos = 'u';
		else if ((stack->current_pos) <= (length / 2))
			stack->pos = 'u';
		stack = stack->next;
	}
}

t_stack_node	*find_node(t_stack_node *stack, size_t target)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->current_pos == target)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}



// Calculate push_price to bring the target node from rotating.
size_t cal_price_from(size_t pos, size_t length, char dir)
{
	if (dir == 'u')
		return (pos);
	else
		return (length - pos);
}



void	cal_push_price(t_stack_node	*a, t_stack_node *b)
{
	t_stack_node	*target_node;
	size_t			a_stack_len;
	size_t			b_stack_len;
	size_t			a_pos;
	size_t			b_pos;

	if (!a || !b)
		return ;
	a_stack_len = (ft_last_node(a)->current_pos) + 1;
	b_stack_len = (ft_last_node(b)->current_pos) + 1;
	while (b)
	{
		target_node = find_node(a, b->target_node);
		a_pos = target_node->current_pos;
		b_pos =  b->current_pos;
		if (a_pos == 0 && b_pos == 0)
			b->push_price = 1;
		else
			insert_push_op(target_node,b, a_stack_len, b_stack_len, a_pos, b_pos);
		if (b->push_price == 1)
			break;
		b = b->next;
	}
}