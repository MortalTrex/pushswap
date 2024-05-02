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

void	ft_radix(t_stack stack_a)
{
	t_stack	stack_b;

	init_stack_b(&stack_a, &stack_b);
	stack_a = create_index(&stack_a, 0);
	if (stack_a.len == 2)
		rab(&stack_a, 0);
	if (stack_a.len == 3)
		sort_three_elements(&stack_a);
	if (stack_a.len == 4)
		sort_four_elements(&stack_a, &stack_b);
	if (stack_a.len == 5)
		sort_five_elements(&stack_a, &stack_b);
	if (stack_a.len > 5)
		radix_sort(&stack_a, &stack_b);
	printf("\033[0;33mAprès le radix :\033[0m\n");
	print_tab(&stack_a);
	printf("Stack triée ?: %d\n", ft_issort(stack_a));
	free_error(&stack_a, &stack_b, 1);
}

int	main(int argc, char **argv)
{
	t_stack			stack_a;
	int				add;

	add = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		add = 0;
	}
	ft_parsing(&stack_a, argv + add);
	if (ft_issort(stack_a))
		free_error_a(&stack_a);
	ft_radix(stack_a);
	free_error_a(&stack_a);
}
