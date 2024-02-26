/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:04:04 by rbalazs           #+#    #+#             */
/*   Updated: 2024/02/26 14:04:06 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a, bool print)
{
	int	temp;

	if (stack_a->len < 2)
		return ;
	temp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = temp;
	if (print == true)
		printf("sa\n");
}

void	sb(t_stack *stack_b, bool print)
{
	int	temp;

	if (stack_b->len < 2)
		return ;
	temp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = temp;
	if (print == true)
		printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, false);
	sb(stack_b, false);
	printf("ss\n");
}
