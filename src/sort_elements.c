/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 06:09:30 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/09 06:09:33 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elements(t_stack *stack_a, int max)
{
	if (stack_a->tab[2] != max)
	{
		if (stack_a->tab[0] == max)
			rab(stack_a, 0);
		else
			rrab(stack_a, 0);
	}
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	sort_four_elements(t_stack *a, t_stack *b, int min)
{
	int	i;

	i = 0;
	while (i < a->len && a->tab[i] != min)
		i++;
	if (i == 1)
		rab(a, 0);
	if (i == 2)
	{
		rrab(a, 0);
		rrab(a, 0);
	}
	if (i == 3)
		rrab(a, 0);
	pb(a, b);
	if (min == 0)
		sort_three_elements(a, 3);
	if (min == 1)
		sort_three_elements(a, 4);
	pa(a, b);
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;

	i = 0;
	while (i < stack_a->len && stack_a->tab[i] != 0)
		i++;
	size = i;
	if (size < 2)
	{
		if (i == 1)
			rab(stack_a, 0);
	}
	if (size >= 2)
	{
		while (i < stack_a->len)
		{
			rrab(stack_a, 0);
			i++;
		}
	}
	pb(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b, 1);
	pa(stack_a, stack_b);
}
