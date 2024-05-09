/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:16:54 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/09 07:41:02 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_error(t_stack *stack_a, char **split)
{
	free_split(split);
	free(stack_a->tab);
	stack_a->tab = NULL;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_error_a(t_stack *stack_a)
{
	free(stack_a->tab);
	stack_a->tab = NULL;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_error(t_stack *stack_a, t_stack *stack_b, int err)
{
	if (stack_a != NULL)
		free(stack_a->tab);
	if (stack_b != NULL)
		free(stack_b->tab);
	if (err == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_splt(char **split_result)
{
	int	i;

	if (!split_result)
		return ;
	i = 0;
	while (split_result[i])
	{
		free(split_result[i]);
		i++;
	}
	free(split_result);
}
