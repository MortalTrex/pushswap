/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:26 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 21:19:55 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(t_stack_node **stack, const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		free_stacknode(stack, 1);
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int number)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = number;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_parsing(t_stack_node **stack_a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (antilonglong(argv[i]) == true)
			free_stacknode(stack_a, 1);
		if (ft_verifsyntax(argv[i]))
			free_stacknode(stack_a, 1);
		number = ft_atol(stack_a, argv[i]);
		if (number < -2147483648 || number > 2147483647)
			free_stacknode(stack_a, 1);
		if (ft_verifdouble(*stack_a, (int)number) == true)
			free_stacknode(stack_a, 1);
		append_node(stack_a, (int)number);
		i++;
	}
}

void	init_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->tab = malloc(stack_a->len * sizeof(int));
	if (!stack_b->tab)
		handle_error_stack(stack_a, stack_b);
	stack_b->len = 0;
}
