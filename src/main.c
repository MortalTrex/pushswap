/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:18 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/10 17:37:48 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_len(t_stack *a, t_stack *b)
{
	t_stack	stack_a_index;

	stack_a_index = create_index(a, 0);
	if (stack_a_index.len == 2)
		rab(&stack_a_index, 0);
	if (stack_a_index.len == 3)
		sort_three_elements(&stack_a_index, 2);
	if (stack_a_index.len == 4)
		sort_four_elements(&stack_a_index, b, 0);
	if (stack_a_index.len == 5)
		sort_five_elements(&stack_a_index, b);
	if (stack_a_index.len > 5)
		radix_sort(&stack_a_index, b);
	free(stack_a_index.tab);
}

int	ft_quotes(char **argv)
{
	int	i;

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
	t_linked_stack	*l_stack_a;
	t_stack			stack_a;
	char			**split;
	int				i;

	t_stack	stack_b;
	l_stack_a = NULL;
	ft_verifonlyspace(argv);
	if (argv == NULL || argv[0] == NULL)
	{
		ft_free_splt(argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (argc <= 1)
		return (0);
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		ft_parsing(&l_stack_a, split);
		
		ft_free_splt(split);
		i++;
	}
	stack_a = ft_hybrid_listtotab(l_stack_a);
	free_linkedstack(&l_stack_a, 0);
	if (ft_verifdouble(&stack_a) == true)
	 	free_error_a(&stack_a);
	if (ft_issort(&stack_a))
	{
		free(stack_a.tab);
		return (1);
	}
	init_stack_b(&stack_a, &stack_b);
	ft_check_len(&stack_a, &stack_b);
	print_tab(&stack_a);
	free_error(&stack_a, &stack_b, 0);
	return (0);
}
