/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:17:36 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/12 18:17:37 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elements(t_stack *stack_a)
{
	if (stack_a->tab[2] != 2)
	{
		if (stack_a->tab[0] == 2)
			rab(stack_a, 0);
		else
			rrab(stack_a, 0);
	}
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	sort_four_elements(t_stack	*stack_a, t_stack	*stack_b)
{
	while (stack_a->tab[0] != 3)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

void	sort_five_elements(t_stack	*stack_a, t_stack	*stack_b)
{
	while (stack_a->tab[0] != 4)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

/*
static void	radix_sort_stack_b(t_stack *stack_a, t_stack *stack_b, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !ft_issort(*stack_a))
	{
		if (((stack_b->tab[0] >> j) & 1) == 0)
			rab(stack_b, 0);
		else
			pa(stack_a, stack_b);
	}
	if (ft_issort(*stack_a))
		while (stack_b->len != 0)
			pa(stack_a, stack_b);
}

void	radix_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	int	bit_size;
	int	size;
	int	j;

	bit_size = 0;
	size = stack_a->len;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack_a->len;
		while (size-- && !ft_issort(*stack_a))
		{
			if (((stack_a->tab[0] >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rab(stack_a, 0);
		}
		radix_sort_stack_b(stack_a, stack_b, stack_b->len, bit_size, j + 1);
	}
	while (stack_b->len != 0)
		pa(stack_a, stack_b);
}
*/

/*
void	radix_sort(t_stack	*stack_a, t_stack	*stack_b)
{
	int	bit_size;
	int	size;
	int b_size;
	int	j;

	bit_size = 0;
	size = stack_a->len;
	b_size = stack_b->len;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack_a->len;
		while (size-- && !ft_issort(*stack_a))
		{
			if (((stack_a->tab[0] >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rab(stack_a, 0);
		}
		while (b_size-- && j <= bit_size && !ft_issort(*stack_a))
		{
			if (((stack_b->tab[0] >> j) & 1) == 0)
				rab(stack_b, 0);
			else
				pa(stack_a, stack_b);
		}
		if (ft_issort(*stack_a))
			while (stack_b->len != 0)
				pa(stack_a, stack_b);
		}
		while (stack_b->len != 0)
			pa(stack_a, stack_b);
	j++;
}
*/


void radix_sort(t_stack *stack_a, t_stack *stack_b) {
    int bit_size = 0;
    int size = stack_a->len;
    int b_size = stack_b->len;
    
    // Calculer le nombre maximum de bits nécessaires pour représenter le plus grand élément
    while (size > 0) {
        size /= 2;
        bit_size++;
    }
    
    // Itérer sur chaque position de bit du moins significatif au plus significatif
    for (int j = 0; j < bit_size; j++) {
        size = stack_a->len;
        
        // Déplacer les éléments de stack_a vers stack_b en fonction du j-ème bit
        while (size-- > 0) {
            if (((stack_a->tab[size] >> j) & 1) == 0)
                pb(stack_a, stack_b);
            else
                rab(stack_a, 0);
        }
        
        // Déplacer les éléments de stack_b vers stack_a en fonction du j-ème bit
        while (b_size-- > 0) {
            if (((stack_b->tab[b_size] >> j) & 1) == 0)
                rab(stack_b, 0);
            else
                pa(stack_a, stack_b);
        }
        
        // Réinitialiser b_size pour la prochaine itération
        b_size = stack_b->len;
    }
}
