/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:18 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/09 18:18:43 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_len(t_stack a, t_stack stack_b)
{
	t_stack	stack_a_index;

	stack_a_index = create_index(&a, 0);
	if (stack_a_index.len == 2)
		rab(&stack_a_index, 0);
	if (stack_a_index.len == 3)
		sort_three_elements(&stack_a_index, 2);
	if (stack_a_index.len == 4)
		sort_four_elements(&stack_a_index, &stack_b, 0);
	if (stack_a_index.len == 5)
		sort_five_elements(&stack_a_index, &stack_b);
	if (stack_a_index.len > 5)
		radix_sort(&stack_a_index, &stack_b);
	free(stack_a_index.tab);
}

/*
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_a_index;
	t_stack	stack_b;
	int		add;

	if (ft_only_space(argv) == true)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	add = 1;
	// checker si un arguments est VIDE ou COUTIENT que des WHITESPACE
	// un ARV empty = argv[1][0] = '\0'
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
			if (!argv)
			{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
			}
		add = 0;
	}
	ft_parsing(&stack_a, argv + add);
	if (ft_issort(&stack_a))
	{
		free(stack_a.tab);
		exit(1);
	}
	init_stack_b(&stack_a, &stack_b);
	stack_a_index.tab = malloc(sizeof(int) * stack_a.len);
	create_index(&stack_a_index, &stack_a, 0);
	ft_check_len(stack_a_index, stack_b);
	free_error(&stack_a, &stack_b, 0);
	free(stack_a_index.tab);
	exit(1);
}
*/

int	ft_quotes(char **argv)
{
	int	i;

	if (argv == NULL || argv[0] == NULL)
	{
		ft_free_splt(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[i])
	{
		if (ft_verifsyntax(argv[i]))
		{
			ft_free_splt(argv);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		add;
	int		i;

	add = 1;
	ft_verifonlyspace(argv);
	if (argc < 2)
		return (1);
	/*if (argc == 2 && argv[1][0] != '\0')
	{
	 	argv = ft_split(argv[1], ' ');
	 	add = ft_quotes(argv);
	}
	*/
	i = 1;
	while (argv[i])
	{
		argv = ft_split(argv[i], ' ');
		i ++;
	}
	add = ft_quotes(argv);
	ft_parsing(&stack_a, argv + add);
	if (add == 0)
		ft_free_splt(argv);
	if (ft_issort(&stack_a))
	{
		free(stack_a.tab);
		return (1);
	}
	init_stack_b(&stack_a, &stack_b);
	ft_check_len(stack_a, stack_b);
	free_error(&stack_a, &stack_b, 0);
	return (0);
}
