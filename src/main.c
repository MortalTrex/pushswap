/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:18 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/12 19:33:24 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_len(t_stack *a, t_stack *b)
{
	t_stack	stack_a_index;

	stack_a_index = create_index(a, b, 0);
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

void	tab_part(t_linked_stack **l_stack_a)
{
	t_stack			stack_a;
	t_stack			stack_b;

	stack_a = ft_hybrid_listtotab(*l_stack_a);
	free_linkedstack(l_stack_a, 0);
	if (ft_verifdouble(&stack_a) == true)
		free_error_a(&stack_a);
	if (ft_issort(&stack_a))
	{
		free(stack_a.tab);
		return ;
	}
	init_stack_b(&stack_a, &stack_b);
	ft_check_len(&stack_a, &stack_b);
	free_error(&stack_a, &stack_b, 0);
}

int	main(int argc, char **argv)
{
	t_linked_stack	*l_stack_a;
	char			**split;
	int				i;

	l_stack_a = NULL;
	if (argc <= 1)
		return (0);
	ft_verifonlyspace(argv);
	if (argv == NULL || argv[0] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL || split[0] == 0)
			free_l_split_error(&l_stack_a, split);
		ft_parsing(&l_stack_a, split);
		ft_free_splt(split);
		i++;
	}
	tab_part(&l_stack_a);
	return (0);
}
