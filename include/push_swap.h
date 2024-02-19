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
# include	"../libft/get_next_line/get_next_line_bonus.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*tab;
	int	len;
}			t_stack;

//INSTRUCTIONS
void	sa(t_stack *stack_a, bool print);
void	sb(t_stack *stack_b, bool print);
void ss(t_stack *stack_a, t_stack *stack_b);

#endif
