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

static long	ft_atol(t_stack_node **stack, const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!ft_isdigit(*s))
		free_errors(stack);
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
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

void	init_stack_a(t_stack_node **stack_a, char **argv)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_verifsyntax(argv[i]))
			free_errors(stack_a);
		number = ft_atol(stack_a, argv[i]);
		if (number < -2147483648 || number > 2147483647)
			free_errors(stack_a);
		if (ft_verifdouble(*stack_a, (int)number) == true)
			free_errors(stack_a);
		append_node(stack_a, (int)number);
		i++;
	}
}
/*
t_stack	init_stack_b(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b.len = 0;
	stack_b.tab = malloc(stack_a.len * sizeof * stack_b.tab);
	if (!stack_b.tab)
		exit (1);
	return (stack_b);
}
*/

void	handle_error_stack(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->tab);
	free(stack_b->tab);
	free(stack_a);
	free(stack_b);
	exit(EXIT_FAILURE);
}


t_stack	init_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;
	
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		handle_error_stack(stack_a, stack_b);
	stack_b->tab = malloc(stack_a->len * sizeof(int));
	if (!stack_b->tab)
		handle_error_stack(stack_a, stack_b);
	stack_b->len = 0;

	return (*stack_b);
}