#include "../include/push_swap.h"

t_stack	create_index(t_stack	*stacktab)
{
	t_stack	result;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	result.tab = malloc(sizeof(int) * stacktab->len);
	if (!result.tab)
		exit(1);
	result.len = stacktab->len;
	while (i < result.len)
	{
		while (j < result.len)
		{
			if (stacktab->tab[i] > stacktab->tab[j])
				count++;
			j++;
		}
		result.tab[i] = count;
		count = 0;
		j = 0;
		i++;
	}
	return (result);
}

void	sort_three_elements(t_stack *stack_a)
{
	//Si le plus grand n'est pas à la fin
	if (stack_a->tab[2] != 2)
	{
	//Si le plus grand est au début, le passe en dernier en décalant vers le haut
		if (stack_a->tab[0] == 2)
			rab(stack_a, 0);
	//Sinon décale tout vers le bas pour passer le plus grand en dernier
		else
			rrab(stack_a, 0);
	}
	//Si le plus grand est déjà à la fin et que le
	//premier élément est plus grand que le deuxième, les échange 
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	sort_four_elements(t_stack	*stack_a, t_stack	*stack_b)
{
	while(stack_a->tab[0] != 3)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

void	sort_five_elements(t_stack	*stack_a, t_stack	*stack_b)
{
	while(stack_a->tab[0] != 4)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

static void	radix_sort_stack_b(t_stack	*stack_a,	t_stack	*stack_b, int	b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !ft_issort(*stack_a))
	{
		if (((stack_b->tab[0] >> j) & 1) == 0)
			rab(stack_b, 0);
		else
		{
			pa(stack_a, stack_b);
			printf("La longueur en else radix : %d\n", stack_b->len);
		}
	}
	if (ft_issort(*stack_a))
		while (b_size != 0)
			pa(stack_a, stack_b);
}

void	radix_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	int	bit_size;
	int	size;
	int	j;

	bit_size = 0;
	size = stack_a->len;
	while (size > 1 && ++bit_size)
		size = size / 2;
	j = -1;
	while (j++ <= bit_size)
	{
		size = stack_a->len;
		while (size-- && !ft_issort(*stack_a))
		{
			if (((stack_a->tab[0] >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rab(stack_a, 0);
		}
		radix_sort_stack_b(stack_a,	stack_b, stack_b->len, bit_size, j + 1);
	}
	while (stack_b->len != 0)
	{
		printf("La longueur : %d\n", stack_b->len);
		pa(stack_a, stack_b);
	}
}

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = init_stack_b(&stack_a);
	stack_a = create_index(&stack_a);
	if	(stack_a.len == 3)
		sort_three_elements(&stack_a);
	if	(stack_a.len == 4)
		sort_four_elements(&stack_a, &stack_b);
	if	(stack_a.len == 5)
		sort_five_elements(&stack_a, &stack_b);
	if	(stack_a.len == 6)
	{
		printf("Longueur de b : %d\n", stack_b.len);
		pb(&stack_a, &stack_b);
		printf("Longueur de b : %d\n", stack_b.len);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		pa(&stack_a, &stack_b);
		printf("Longueur de b : %d\n", stack_b.len);
	}
	//if	(stack_a.len > 6000)
		//radix_sort(&stack_a, &stack_b);
	free(stack_b.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
	print_tab(&stack_a);
	printf("Stack triée ?: %d\n", ft_issort(stack_a));
 	free(stack_a.tab);
}
