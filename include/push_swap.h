/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:36:52 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/08 21:32:10 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft_core/libft.h"
# include <stdbool.h>

// STRUCTURES
typedef struct s_stack
{
	int					*tab;
	int					len;
}						t_stack;

// INSTRUCTIONS
void					sa(t_stack *stack_a, bool print);
void					sb(t_stack *stack_b, bool print);
void					ss(t_stack *stack_a, t_stack *stack_b);
void					pa(t_stack *stack_a, t_stack *stack_b);
void					pb(t_stack *stack_a, t_stack *stack_b);
void					rab(t_stack *stack_ab, int stack);
void					rrab(t_stack *stack_a, int stack);
void					rrr(t_stack *stack_a, t_stack *stack_b);

// FREE
void					free_error(t_stack *stack_a, t_stack *stack_b, int err);
void					free_error_a(t_stack *stack_a);
void	free_split_error(t_stack *stack_a, char **split);

// VERIF
void					print_tab(t_stack *stack);
bool					ft_issort(t_stack *stack);
bool					antilonglong(char *str);
bool					ft_verifdouble(t_stack *stack_a);
bool					ft_verifsyntax(char *str);

// PARSING
void					ft_parsing(t_stack *stack_a, char **argv);

// UTILS 
void					create_index(t_stack *res, t_stack *stack_a, int count);
void					init_stack_b(t_stack *stack_a, t_stack *stack_b);
int						ft_stack_a_len(char **argv);
int						find_bit_size(int a_size);

// RADIX
void					ft_radix(t_stack stack_a);

// RADIX
void					sort_three_elements(t_stack *stack_a);
void					sort_four_elements(t_stack *stack_a, t_stack *stack_b);
void					sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void					sort_four_five_elements(t_stack *stack_a, t_stack *stack_b);
void					radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
