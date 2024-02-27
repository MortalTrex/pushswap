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
