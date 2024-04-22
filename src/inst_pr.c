/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:02:45 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 19:59:06 by rbalazs          ###   ########.fr       */
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}

/*
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	
	if (stack_b->len <= 0)
		return ;
	tmp = stack_b->tab[0];
	ft_memmove(stack_a->tab + 1, stack_a->tab, sizeof(int) * stack_a->len);
	stack_a->tab[0] = tmp;
	stack_b->len--;
	ft_memmove(stack_b->tab, stack_b->tab + 1, sizeof(int) * stack_b->len);
	stack_a->len++;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	if (stack_b->len <= 0)
		return ;
	tmp = stack_a->tab[0];
	ft_memmove(stack_b->tab + 1, stack_b->tab, sizeof(int) * stack_b->len);
	stack_b->tab[0] = tmp;
	stack_a->len--;
	ft_memmove(stack_a->tab, stack_a->tab + 1, sizeof(int) * stack_a->len);
	stack_b->len++;
	ft_printf("pb\n");
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
		ft_printf("ra\n");
	if (stack == 1)
		ft_printf("rb\n");
}
*/

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
		ft_printf("ra\n");
	if (stack == 1)
		ft_printf("rb\n");
}
