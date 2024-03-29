#include "../include/push_swap.h"

void	recurrence_test(int* example_array, int* count)
{
	if (*count > 10) 
		return ;
	printf("recurrence count %d\n", *count);
	++*count;
	recurrence_test(example_array, count);
}

void	recurrence_with_int(int* example_array, int count)
{
	if (count > 10) 
		return ;
	printf("recurrence count %d\n", count);
	++count;
	recurrence_with_int(example_array, count);
}

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

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;
	t_nbinfo	nbinfo;

	printf("\033[0;35mSéparation des unités du chiffre :\033[0m\n");
	nbinfo = ft_unit(stack_a.tab[0]);
	stack_b = init_stack_b(&stack_a);

	//pa(&stack_a, &stack_b);
	//rab(&stack_a, 0);
	//rrab(stack_a, 0);
	
	free(stack_b.tab);
	free(nbinfo.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
 	for (int i = 0; i < stack_a.len; i++)
 	{
 		printf("%d\n", stack_a.tab[i]);
 	}
}
