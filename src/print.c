/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:41:38 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/17 16:41:39 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

void	print_tab(t_stack	*stacktab)
{
	int	i;

	i = 0;
	while (i < stacktab->len)
	{
		printf("%d\n", stacktab->tab[i]);
		i++;
	}
}
