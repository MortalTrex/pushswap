/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:16:54 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:17:00 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_error(t_stack *stack_a, t_stack *stack_b, int	error)
{
	if (stack_a != NULL)
	{
		free(stack_a->tab);
		free(stack_a);
	}
	if (stack_b != NULL)
	{
		free(stack_b->tab);
		free(stack_b);
	}
	if (error == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
