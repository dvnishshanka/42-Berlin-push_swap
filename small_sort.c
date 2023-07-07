
#include "push_swap.h"

// This sort is applied if the stack size = 3
t_stack_node	*small_sort(t_stack_node *stack)
{
	int	value_1;
	int	value_2;
	int	value_3;

	if (!stack)
		return (NULL) ;
	value_1 = stack->value;
	value_2 = stack->next->value;
	value_3 = stack->next->next->value;
	
	if (value_2 > value_3 && value_2 > value_1)
	{
		rra(&stack);
		if (value_3 > value_1)
			sa(&stack);
	}
	else if (value_1 > value_3 && value_1 > value_2)
	{
		ra(&stack);
		if (value_2 > value_3)
			sa(&stack);
	}
	else if (value_1 > value_2)
		sa(&stack);
	return (stack);
}