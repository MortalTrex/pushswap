/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:02:45 by rbalazs           #+#    #+#             */
/*   Updated: 2024/02/26 14:02:47 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->len;
	if (stack_b->len == 0)
		return ;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	stack_a->len++;
	stack_b->len--;
	while (i < stack_b->len)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

i = stack_b->len;
	if (stack_a->len == 0)
		return ;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->len++;
	stack_a->len--;
	while (i < stack_a->len)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	printf("pb\n");
}

void	rab(t_stack *stack_ab, int stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_ab->tab[0];
	while (i < stack_ab->len)
	{
		stack_ab->tab[i] = stack_ab->tab[i + 1];
		i++;
	}
	stack_ab->tab[i - 1] = temp;
	if (stack == 0)
		printf("ra\n");
	if (stack == 1)
		printf("rb\n");
}
