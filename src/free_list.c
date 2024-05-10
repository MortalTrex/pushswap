#include "../include/push_swap.h"

void	free_l_split_error(t_linked_stack **stack_a, char **split)
{
	free_split(split);
	free_linkedstack(stack_a, 1);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
void	free_linkedstack(t_linked_stack **stack, int error)
{
	t_linked_stack	*tmp;
	t_linked_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	if (error == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}

