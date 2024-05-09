/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:26 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/09 16:16:30 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(t_stack *stack, const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		free_error_a(stack);
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

void	ft_parsing(t_stack *stack_a, char **argv)
{
	long	number;
	int		i;
	int		len;

	len = ft_stack_a_len(argv);
	stack_a->tab = malloc(sizeof(int) * len);
	if (!stack_a->tab)
		free_split_error(stack_a, argv);
	stack_a->len = len;
	i = 0;
	if (antilonglong(argv[i]) == true)
		free_split_error(stack_a, argv);
	while (argv[i])
	{
		if (ft_verifsyntax(argv[i]))
			free_split_error(stack_a, argv);
		number = ft_atol(stack_a, argv[i]);
		if (number < -2147483648 || number > 2147483647)
			free_split_error(stack_a, argv);
		stack_a->tab[i] = number;
		i++;
	}
	if (ft_verifdouble(stack_a) == true)
		free_split_error(stack_a, argv);
	printf("stack_a->len = %d\n", stack_a->len);
}