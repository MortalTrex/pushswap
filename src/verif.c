/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:19 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:18:20 by rbalazs          ###   ########.fr       */
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

bool	ft_issort(t_stack stacktab)
{
	int	i;

	i = 0;
	while (i < stacktab.len - 1)
	{
		if (stacktab.tab[i] > stacktab.tab[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_verifsyntax(char *argv)
{
	if (!(*argv == '+' || *argv == '-' || (*argv >= '0' && *argv <= '9')))
		return (true);
	if ((*argv == '+' || *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9'))
		return (true);
	while (*++argv)
	{
		if (!(*argv >= '0' && *argv <= '9'))
			return (true);
	}
	return (false);
}

bool	antilonglong(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i >= 10)
			return (true);
		i++;
	}
	return (false);
}
