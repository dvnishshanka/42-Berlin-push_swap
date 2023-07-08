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

static int	find_small_num(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
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
		else if (target_node->pos == 'u' && (b->pos) == 'u')
		{	
			b->rr = find_small_num(cal_price_from(a_pos, a_stack_len, 'u'), cal_price_from(b_pos, b_stack_len, 'u'));
			b->ra = cal_price_from(a_pos, a_stack_len, 'u') - b->rr;
			b->rb = cal_price_from(b_pos, b_stack_len, 'u') - b->rr;
			b->push_price = b->ra + cal_price_from(b_pos, b_stack_len, 'u') + 1;
		}
		else if (target_node->pos == 'd' && (b->pos) == 'd')
		{	
			b->rrr = find_small_num(cal_price_from(a_pos, a_stack_len, 'd'), cal_price_from(b_pos, b_stack_len, 'd'));
			b->rra = cal_price_from(a_pos, a_stack_len, 'd') - b->rrr;
			b->rrb = cal_price_from(b_pos, b_stack_len, 'd') - b->rrr;
			b->push_price = b->rra  + cal_price_from(b_pos, b_stack_len, 'd') + 1;
		}
		else if (target_node->pos == 'd' && (b->pos) == 'u')
		{
			b->rra = cal_price_from(a_pos, a_stack_len, 'd');
			b->rb = cal_price_from(b_pos, b_stack_len, 'u');
			b->push_price = b->rra + b->rb + 1;
		}
		else if (target_node->pos == 'u' && (b->pos) == 'd')
		{
			b->ra = cal_price_from(a_pos, a_stack_len, 'u');
			b->rrb = cal_price_from(b_pos, b_stack_len, 'd');
			b->push_price = b->ra + b->rrb + 1;
		}
		if (b->push_price == 1)
			break;
		b = b->next;
	}
}