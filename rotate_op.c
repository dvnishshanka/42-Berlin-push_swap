
#include "push_swap.h"

// Rotate the stack. First element will be the last element of the stack.
static void	rotate(t_stack_node **stack)
{
	t_stack_node	*new_head;
	t_stack_node	*last_node;

	new_head = (*stack)->next;
	new_head->prev = NULL;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = last_node;
	*stack = new_head;
	insert_node_pos(*stack);
}

// Rotate the stack a.
void	ra(t_stack_node **a)
{
	if (*a)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

// Rotate the stack a.
void	rb(t_stack_node **b)
{
	if (*b)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

// Rotate both stacks.
void	rr(t_stack_node **a, t_stack_node **b)
{
	if (*a && *b)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}