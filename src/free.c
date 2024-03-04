#include "../include/push_swap.h"

void	free_stack(t_stack_node **stack) 
{
	t_stack_node	*tmp;
	t_stack_node	*current;

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
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	exit(1);
}
