#include "push_swap.h"


static int	find_small_num(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

void	insert_push_op(t_stack_node *target_node, t_stack_node *b, size_t a_stack_len, size_t b_stack_len, size_t a_pos,size_t b_pos)
{
	if (target_node->pos == 'u' && (b->pos) == 'u')
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
}