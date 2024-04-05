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

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b = init_stack_b(&stack_a);
	stack_a = create_index(&stack_a);
	sort_three_elements(&stack_a);
	free(stack_b.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
	print_tab(&stack_a);
	printf("Stack triée ?: %d\n", ft_issort(stack_a));
 	free(stack_a.tab);
}
