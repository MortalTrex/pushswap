#include "../include/push_swap.h"

void	read_nbinfo(t_nbinfo	nbinfo)
{
	int	i;

	i = 0;
	while(i < nbinfo.len)
	{
		ft_printf("La valeur de %d est %d\n", i, nbinfo.tab[i]);
		i++;
	}
	ft_printf("La valeur de la longueur est : %d\n", nbinfo.len);
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
		printf("A %d on a %d\n", i, nb);
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
	nbinfo = ft_unit(348543433);
	read_nbinfo(nbinfo);
	stack_b = init_stack_b(&stack_a);

	//pa(&stack_a, &stack_b);
	//rab(&stack_a, 0);
	//rrab(stack_a, 0);
	
	free(stack_b.tab);
	free(nbinfo.tab);
	printf("\033[0;33mAprès le radix :\033[0m\n");
 	for (int i = 0; i < stack_a.len; i++)
 	{
 		printf("%d ", stack_a.tab[i]);
 	}
}
