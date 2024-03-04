#include "../include/push_swap.h"

t_stack_node	*find_last(t_stack_node *stack) //Define a function that returns the pointer to the last node
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

/*
int	ft_stack_len(t_stack_node *stack) 
{
	int	count;

	count = 0;
	while (stack)
	{
		stack->next;
		count++;
	}
	return (count);
}
*/

static void	append_node(t_stack_node **stack, int numbers)
{
	t_stack_node	*node; 	
	t_stack_node	*last_node;
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); 	
		return ;
	node->next = NULL;
	node->nbr = numbers;	
	if (!(*stack)) 
	{
		*stack = node; 
		node->prev = NULL; 
	}
	else 
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void init_stack_a(t_stack_node **stack_a, char **argv)
{
	long	numbers;
	int	i;

	i = 0;
	while (argv[i])
	{
		numbers = ft_atoi(argv[i]);
		printf("%ld - ", numbers);
		if (ft_verifdouble(stack_a, (int)numbers) == true)
			free_errors(stack_a);
		i++;
	}
	append_node(stack_a, (int)numbers);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return 0;
	init_stack_a(&stack_a, argv + 1);
	free_stack(&stack_a);
}
