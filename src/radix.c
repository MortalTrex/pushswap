/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:36 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/09 06:01:41 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_in_a(int j, t_stack *stack_a, t_stack *stack_b)
{
	int	a_size;

	a_size = stack_a->len;
	while (a_size-- && !ft_issort(stack_a))
	{
		if (((stack_a->tab[0] >> j) & 1) == 0)
			pb(stack_a, stack_b);
		else
			rab(stack_a, 0);
	}
}

void	sort_in_b(int i, t_stack *stack_a, t_stack *stack_b)
{
	int	b_size;

	b_size = stack_b->len;
	while (b_size-- && !ft_issort(stack_a))
	{
		if (((stack_b->tab[0] >> i) & 1) == 0)
			rab(stack_b, 1);
		else
			pa(stack_a, stack_b);
	}
	if (ft_issort(stack_a))
		while (stack_b->len != 0)
			pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit_size;
	int	i;

	bit_size = find_bit_size(stack_a->len);
	i = 0;
	while (i <= bit_size)
	{
		sort_in_a(i, stack_a, stack_b);
		sort_in_b(i + 1, stack_a, stack_b);
		i++;
	}
	while (stack_b->len > 0)
		pa(stack_a, stack_b);
}
