#include "../include/push_swap.h"

bool	ft_verifdouble(t_stack_node **stack_a, int numbers)
{
	while (stack_a)
	{
		if (stack_a->nbr == numbers)
			return (true)
		stack_a = stack_a->next;
	}
	return (false);
}
