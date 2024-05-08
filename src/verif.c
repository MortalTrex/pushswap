/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:19 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/08 17:06:03 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_verifdouble(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->len)
	{
		j = i + 1;
		while (j < stack_a->len)
		{
			if (stack_a->tab[i] == stack_a->tab[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	ft_issort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_verifsyntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (true);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

bool	antilonglong(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (i >= 10)
			return (true);
		i++;
	}
	return (false);
}
