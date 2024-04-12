/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:18 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:17:20 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack			stacktab_a;
	int				add;

	stack_a = NULL;
	add = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		add = 0;
	}
	init_stack_a(&stack_a, argv + add);
	stacktab_a = ft_hybrid_listotab(stack_a);
	free_stack(&stack_a);
	ft_radix(stacktab_a);
}
