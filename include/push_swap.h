/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:36:52 by rbalazs           #+#    #+#             */
/*   Updated: 2024/02/19 10:38:01 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft_core/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdbool.h>

typedef struct s_stack
{
	int	*tab;
	int	len;
}			t_stack;

typedef	struct	s_stack_node
{
	int	nbr;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
	struct	s_stack_node	*target_node;
}	t_stack_node;

//INSTRUCTIONS
void	sa(t_stack *stack_a, bool print);
void	sb(t_stack *stack_b, bool print);
void ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void rab(t_stack *stack_ab, int stack);
void rrab(t_stack *stack_a, int stack);
void rrr(t_stack *stack_a, t_stack *stack_b);

//FREE
void	free_stack(t_stack_node **stack);
void	free_errors(t_stack_node **stack_a);

//VERIF
bool	ft_verifdouble(t_stack_node *stack_a, int numbers);

#endif
