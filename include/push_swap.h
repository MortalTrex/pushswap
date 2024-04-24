/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:36:52 by rbalazs           #+#    #+#             */
/*   Updated: 2024/04/22 21:11:46 by rbalazs          ###   ########.fr       */
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

typedef struct s_stack_node
{
	int					nbr;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

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
void					free_stacknode(t_stack_node **stack);
void	handle_error_stack(t_stack *stack_a, t_stack *stack_b);

// VERIF
void					print_tab(t_stack *stacktab);
bool					ft_verifdouble(t_stack_node *stack_a, int numbers);
bool					ft_verifsyntax(char *argv);
bool					ft_issort(t_stack stacktab);

// PARSING
void					init_stack_a(t_stack_node **stack_a, char **argv);
t_stack					init_stack_b(t_stack *stack_a);

// UTILS
t_stack_node			*find_last(t_stack_node *stack);
int						ft_stack_len(t_stack_node *stack);
t_stack					create_index(t_stack *stacktab, int count);

// CONVERSION
t_stack					ft_hybrid_listtotab(t_stack_node *stacklist);

// RADIX
void					ft_radix(t_stack stack_a);

// PRINT
void					print_stack(t_stack_node *stack);
void					print_tab(t_stack *stacktab);

// RADIX
void					sort_three_elements(t_stack *stack_a);
void					sort_four_elements(t_stack *stack_a, t_stack *stack_b);
void					sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void					radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
