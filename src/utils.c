/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:11 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 20:08:05 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_tab(t_stack	*stacktab)
{
	int	i;

	i = 0;
	while (i < stacktab->len)
	{
		printf("%d\n", stacktab->tab[i]);
		i++;
	}
}

t_stack	create_index(t_stack	*stacktab, int count)
{
	t_stack	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result.tab = malloc(sizeof(int) * stacktab->len);
	if (!result.tab)
		exit(1);
	result.len = stacktab->len;
	while (i < result.len)
	{
		while (j < result.len)
		{
			if (stacktab->tab[i] > stacktab->tab[j])
				count++;
			j++;
		}
		result.tab[i] = count;
		count = 0;
		j = 0;
		i++;
	}
	return (result);
}
