#include "../include/push_swap.h"

static long	ft_atol(const char *s) 
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

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
		numbers = ft_atol(argv[i]);
		printf("%ld", numbers);
		if (ft_verifdouble(*stack_a, (int)numbers) == true)
			free_errors(stack_a);
		append_node(stack_a, (int)numbers);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return 0;
	if (argc == 2)
		argv = ps_split(argv[1], ' ');
	init_stack_a(&stack_a, argv + 1);
	free_stack(&stack_a);
}
