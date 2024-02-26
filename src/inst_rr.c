#include "../include/push_swap.h"

void rra(t_stack *stack_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a->tab[i];
	while (i < stack_a->len)
	{
		stack_a->tab[i + 1] = stack_a->tab[i];
		i++;
	}
	stack_a->tab[] = temp;
	printf("rra\n");
}
