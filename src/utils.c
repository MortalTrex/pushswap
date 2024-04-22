/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:11 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:18:14 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_stack_len(t_stack_node *stack)
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

t_stack	ft_hybrid_listtotab(t_stack_node *stacklist)
{
	int		i;
	int		sizelist;
	t_stack	stacktab;

	i = 0;
	sizelist = ft_stack_len(stacklist);
	stacktab.len = sizelist;
	stacktab.tab = malloc(sizeof(int) * sizelist);
	if (!stacktab.tab)
		exit(1);
	while (i < sizelist)
	{
		stacktab.tab[i] = stacklist->nbr;
		stacklist = stacklist->next;
		i++;
	}
	return (stacktab);
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
