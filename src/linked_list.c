/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:54:46 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/11 12:54:49 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_l_stack_len(t_linked_stack *stack)
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
	sizelist = ft_l_stack_len(stacklist);
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

void	free_l_split_error(t_linked_stack **stack_a, char **split)
{
	free_split(split);
	free_linkedstack(stack_a, 1);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_linkedstack(t_linked_stack **stack, int error)
{
	t_linked_stack	*tmp;
	t_linked_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
	if (error == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
