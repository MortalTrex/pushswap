/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:26 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/11 11:44:52 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

t_linked_stack	*find_last(t_linked_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static bool	append_node(t_linked_stack **stack, int number)
{
	t_linked_stack	*node;
	t_linked_stack	*last_node;

	if (!stack)
		return (false);
	node = malloc(sizeof(t_linked_stack));
	if (!node)
		return (false);
	node->next = NULL;
	node->nbr = number;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
	}
	return (true);
}

void	ft_parsing(t_linked_stack **stack_a, char **split)
{
	long	number;
	int		i;

	i = 0;
	while (split[i])
	{
		if (antilonglong(split[i]) == true)
			free_l_split_error(stack_a, split);
		if (ft_verifsyntax(split[i]))
			free_l_split_error(stack_a, split);
		number = ft_atol(split[i]);
		if (number < -2147483648 || number > 2147483647)
			free_l_split_error(stack_a, split);
		if (append_node(stack_a, (int)number) == false)
			free_l_split_error(stack_a, split);
		i++;
	}
}
