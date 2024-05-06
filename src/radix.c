/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:36 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:17:37 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->tab[0] != 3)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->tab[0] != 4)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

void	sort_in_ab(int j, t_stack *stack_a, t_stack *stack_b, int a_or_b)
{
	if (a_or_b == 0)
	{
		if (((stack_a->tab[0] >> j) & 1) == 0)
			pb(stack_a, stack_b);
		else
			rab(stack_a, 0);
	}
	if (a_or_b == 1)
	{
		if (((stack_b->tab[0] >> j) & 1) == 0)
			rab(stack_b, 0);
		else
			pa(stack_a, stack_b);
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int			bit_size;
	static int	a_size;
	int			b_size;
	int			j;

	a_size = stack_a->len;
	bit_size = find_bit_size(a_size);
	j = -1;
	while (j <= bit_size)
	{
		while (a_size-- && !ft_issort(*stack_a))
			sort_in_ab(j, stack_a, stack_b, 0);
		j++;
		b_size = stack_b->len;
		while (b_size-- && j <= bit_size && !ft_issort(*stack_a))
			sort_in_ab(j, stack_a, stack_b, 1);
		if (ft_issort(*stack_a))
			while (stack_b->len != 0)
				pa(stack_a, stack_b);
	}
	while (stack_b->len != 0)
		pa(stack_a, stack_b);
}

/*
void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit_size;
	int	a_size;
	int	b_size;
	int	j;

	a_size = stack_a->len;
	bit_size = find_bit_size(a_size);
	j = -1;
	while (j <= bit_size)
	{
		while (a_size-- && !ft_issort(*stack_a))
		{
			if (((stack_a->tab[0] >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rab(stack_a, 0);
		}
		j++;
		b_size = stack_b->len;
		while (b_size-- && j <= bit_size && !ft_issort(*stack_a))
		{
			if (((stack_b->tab[0] >> j) & 1) == 0)
				rab(stack_b, 0);
			else
				pa(stack_a, stack_b);
		}
		if (ft_issort(*stack_a))
			while (stack_b->len != 0)
				pa(stack_a, stack_b);
	}
	while (stack_b->len != 0)
		pa(stack_a, stack_b);
}
*/