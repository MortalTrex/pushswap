/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:18 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 21:12:03 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_check_len(t_stack stack_a_index, t_stack stack_b)
{
	if (stack_a_index.len == 2)
		rab(&stack_a_index, 0);
	if (stack_a_index.len == 3)
		sort_three_elements(&stack_a_index);
	if (stack_a_index.len == 4)
		sort_four_elements(&stack_a_index, &stack_b);
	if (stack_a_index.len == 5)
		sort_five_elements(&stack_a_index, &stack_b);
	if (stack_a_index.len > 5)
		radix_sort(&stack_a_index, &stack_b);
	printf("\033[0;33mAprès le radix :\033[0m\n");
	print_tab(&stack_a_index);
	printf("Stack triée ?: %d\n", ft_issort(stack_a_index));
}

int	main(int argc, char **argv)
{
	t_stack			stack_a;
	t_stack			stack_a_index;
	t_stack			stack_b;
	int				add;

	add = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		add = 0;
	}
	ft_parsing(&stack_a, argv + add);
	if (ft_issort(stack_a))
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
