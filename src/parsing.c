#include "../include/push_swap.h"

void print_stack(t_stack_node *stack)
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

static long	ft_atol(t_stack_node **stack, const char *s) 
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
	if (!ft_isdigit(*s))
		free_errors(stack);
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int number)
{
	t_stack_node	*node;	
	t_stack_node	*last_node;
	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ; 
	node->next = NULL;
	node->nbr = number;
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
	long	number;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_verifsyntax(argv[i]))
			free_errors(stack_a);
		number = ft_atol(stack_a, argv[i]);
		if (number < -2147483648 || number > 2147483647)
			free_errors(stack_a);
		if (ft_verifdouble(*stack_a, (int)number) == true)
			free_errors(stack_a);
		append_node(stack_a, (int)number);
		i++;
	}
}

t_stack	init_stack_b(void)
{
	t_stack	stack_b;
	int	i;

	i = 0;
	stack_b.tab = malloc(sizeof(int) * 0);
	if (!stack_b.tab)
		exit(1);
	stack_b.len = 0;
	return(stack_b);
}
