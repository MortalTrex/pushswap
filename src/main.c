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

size_t    ft_argvlen(char **strs)
{
    size_t    len;
    int        i;

    len = 0;
    i = 1;
    while (strs[i])
    {
        len = len + ft_strlen(strs[i]);
        i++;
    }
    return (len);
}

char    *ft_strjoin_space(char **argv)
{
    int        i;
    int        j;
    int        index_join;
    char    *join;

    i = 1;
    index_join = 0;
    join = malloc(sizeof(char) + (ft_argvlen(argv) * 2) + 1);
    if (!join)
        return (NULL);
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            join[index_join] = argv[i][j];
            index_join++;
            j++;
        }
        join[index_join] = ' ';
        index_join++;
        i++;
    }
    join[index_join] = '\0';
    return (join);
}

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
	int	i;

	if (argc <= 1)
		return (0);
	ft_verifonlyspace(argv);
	for (i = 1; i < argc; i++) 
	{
    ft_split(argv[i], ' ');
	}
  ft_parsing(&stack_a, argv);
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
