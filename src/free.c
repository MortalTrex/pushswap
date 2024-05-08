/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:16:54 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/08 21:30:49 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_error(t_stack *stack_a, char **split)
{
	free_split(split);
	free(stack_a->tab);
	stack_a->tab = NULL;
	ft_printf("Error\n");
	exit(1);
}

void	free_error_a(t_stack *stack_a)
{
	free(stack_a->tab);
	stack_a->tab = NULL;
	ft_printf("Error\n");
	exit(1);
}

void	free_error(t_stack *stack_a, t_stack *stack_b, int err)
{
	if (stack_a != NULL)
		free(stack_a->tab);
	if (stack_b != NULL)
		free(stack_b->tab);
	if (err == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
