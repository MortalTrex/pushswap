#include "../include/push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

void	print_tab(t_stack	*stacktab)
{
	int	i;

	i = 0;
	while (i < stacktab->len)
	{
		printf("%d\n", stacktab->tab[i]);
		i++;
	}
}
