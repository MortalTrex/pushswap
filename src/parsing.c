/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:26 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 21:19:55 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(t_stack *stack, const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		free(stack);
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

void	ft_parsing(t_stack *stack_a, char **argv)
{
	long	number;
	int		i;

	stack_a->tab = malloc(sizeof(int) * 3);
	stack_a->len = 3; 
	i = 0;
	while (argv[i])
	{
		if (antilonglong(argv[i]) == true)
			exit(1);
		if (ft_verifsyntax(argv[i]))
			exit(1);
		number = ft_atol(stack_a, argv[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(1);
		//if (ft_verifdouble(stack_a, (int)number) == true)
			//exit(1);
		//append_node(stack_a, (int)number);
		stack_a->tab[i] = number;
		i++;
	}
}

void	init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->tab = malloc(stack_a->len * sizeof(int));
	if (!stack_b->tab)
		free_error(stack_a, stack_b, 1);
	stack_b->len = 0;
}
