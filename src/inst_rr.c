/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 09:25:19 by rbalazs           #+#    #+#             */
/*   Updated: 2024/03/02 09:25:21 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrab(t_stack *stack_ab, int stack)
{
	int	temp;
	int	size;

	size = stack_ab->len;
	temp = stack_ab->tab[size - 1];
	while (size > 0)
	{
		stack_ab->tab[size] = stack_ab->tab[size - 1];
		size--;
	}
	stack_ab->tab[0] = temp;
	if (stack == 0)
		ft_printf("rra\n");
	if (stack == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrab(stack_a, 0);
	rrab(stack_b, 0);
	ft_printf("rrr");
}
