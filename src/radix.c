#include "../include/push_swap.h"

/*
void	read_nbinfo(t_nbinfo	nbinfo)
{
	int	i;

	i = 0;
	while (i < nbinfo.len)
	{
		printf("La valeur est %d pour %d\n", nbinfo.tab[i], i);
		i++;
	}
	printf("La valeur de la longueur est : %d\n", nbinfo.len);
}

t_nbinfo	ft_unit(int	nb)
{
	t_nbinfo	nbinfo;
	int	i;
	int	digit;

	digit = nb;
	i = 0;
	while (digit)
	{
		digit = digit / 10;
		i++;
	}
	nbinfo.tab = malloc(sizeof(int) * i);
	if (!nbinfo.tab)
		exit(1) ;
	digit = nb;
	i = 0;
	while (nb)
	{
		digit = nb % 10;
		nb = nb / 10;
		nbinfo.tab[i] = digit;
		if (nb == 0)
			break;
		i++;
	}
	nbinfo.len = i + 1;
	return (nbinfo);
}
*/

void	sort_three_elements(t_stack *stack_a)
{
	if (stack_a->tab[2] != 2)
	{
		if (stack_a->tab[0] == 2)
			rab(stack_a, 0);
		else
			rrab(stack_a, 0);
	}
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;
	//t_nbinfo	nbinfo;

	//nbinfo = ft_unit(stack_a.tab[0]);
	stack_b = init_stack_b(&stack_a);

	sort_three_elements(&stack_a);
	
	free(stack_b.tab);
	//free(nbinfo.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
	print_tab(stack_a);
}
