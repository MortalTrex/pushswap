#include "../include/push_swap.h"

void rrab(t_stack *stack_ab, int stack)
{
	int	temp;
	int	size;

	size = stack_ab->len;
	temp = stack_ab->tab[size - 1];
	while (size > 0)
	{
		stack_ab->tab[size] = stack_ab->tab[size - 1];
		size--;
	}
	stack_ab->tab[0] = temp;
	if (stack == 0)
		printf("rra\n");
	if (stack == 1)
		printf("rrb\n");
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrab(stack_a, 0);
	rrab(stack_b, 0);
	printf("rrr");
}
