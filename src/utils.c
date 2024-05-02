/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:11 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 20:08:05 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stack_a_len(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

void	init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->tab = malloc(stack_a->len * sizeof(int));
	if (!stack_b->tab)
		free_error(stack_a, stack_b, 1);
	stack_b->len = 0;
}

void	print_tab(t_stack	*stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

t_stack	create_index(t_stack	*stacktab, int count)
{
	t_stack	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result.tab = malloc(sizeof(int) * stacktab->len);
	if (!result.tab)
		exit(1);
	result.len = stacktab->len;
	while (i < result.len)
	{
		while (j < result.len)
		{
			if (stacktab->tab[i] > stacktab->tab[j])
				count++;
			j++;
		}
		result.tab[i] = count;
		count = 0;
		j = 0;
		i++;
	}
	return (result);
}
