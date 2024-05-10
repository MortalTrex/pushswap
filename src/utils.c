/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:11 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/10 19:47:29 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stack_len(t_linked_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	ft_hybrid_listtotab(t_linked_stack *stacklist)
{
	int		i;
	int		sizelist;
	t_stack	stacktab;

	i = 0;
	sizelist = ft_stack_len(stacklist);
	stacktab.len = sizelist;
	stacktab.tab = malloc(sizeof(int) * sizelist);
	if (!stacktab.tab)
		free_linkedstack(&stacklist, 1);
	while (i < sizelist)
	{
		stacktab.tab[i] = stacklist->nbr;
		stacklist = stacklist->next;
		i++;
	}
	return (stacktab);
}

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

void	print_tab(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		printf("%d\n", stack->tab[i]);
		i++;
	}
}

int	find_bit_size(int a_size)
{
	int	bit_size;

	bit_size = 0;
	while (a_size > 1)
	{
		a_size = a_size / 2;
		bit_size++;
	}
	return (bit_size);
}

t_stack	create_index(t_stack *stack_a, t_stack *stack_b, int count)
{
	t_stack	stack_a_index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	stack_a_index.tab = malloc(sizeof(int) * stack_a->len);
	if (!stack_a_index.tab)
		free_error(stack_a, stack_b, 1);
	stack_a_index.len = stack_a->len;
	while (i < stack_a_index.len)
	{
		while (j < stack_a_index.len)
		{
			if (stack_a->tab[i] > stack_a->tab[j])
				count++;
			j++;
		}
		stack_a_index.tab[i] = count;
		count = 0;
		j = 0;
		i++;
	}
	return (stack_a_index);
}
