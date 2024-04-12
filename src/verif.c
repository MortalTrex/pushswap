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

bool	ft_verifdouble(t_stack_node *stack_a, int number) 
{
	while (stack_a)
	{
		if (stack_a->nbr == number)
			return (true);
		stack_a = stack_a->next;
	}
	return (false);
}

bool ft_issort(t_stack stacktab)
{
	int	i;

	i = 0;
	while (i < stacktab.len - 1)
	{
		if (stacktab.tab[i] > stacktab.tab[i + 1])
			return(false);
		i++;
	}
	return(true);
}

bool	ft_verifsyntax(char *argv) 
{
	if (!(*argv == '+'|| *argv == '-' || (*argv >= '0' && *argv <= '9'))) 
		return (1);
	if ((*argv == '+'|| *argv == '-') && !(argv[1] >= '0' && argv[1] <= '9')) 
		return (1);
	while (*++argv) 
	{
		if (!(*argv >= '0' && *argv <= '9')) 
			return (1);
	}
	return (0);
}
