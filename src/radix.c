#include "../include/push_swap.h"

int ft_unit(int	number)
{
	int	i; 

	i = 0;
	while(number > 0)
	{
		number = number / 10;
		printf("\nA %d on a : %d\n", i, number);
	}
	return(number);
}

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;
	ft_unit(34);

	stack_b = init_stack_b(&stack_a);
	//pa(&stack_a, &stack_b);
	//rab(&stack_a, 0);
	//rrab(stack_a, 0);
	free(stack_b.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
 	for (int i = 0; i < stack_a.len; i++)
 	{
 		printf("%d ", stack_a.tab[i]);
 	}
}
