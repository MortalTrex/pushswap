/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:36:52 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/10 19:10:04 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft_core/libft.h"
# include <stdbool.h>

// STRUCTURES
typedef struct s_linked_stack
{
	int					nbr;
	struct s_linked_stack	*next;
}				t_linked_stack;

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
void					free_split_error(t_stack *stack_a, char **split);
void					ft_free_splt(char **split_result);
void 					free_l_split_error(t_linked_stack **stack_a, char **split);
void					free_linkedstack(t_linked_stack **stack, int error);

// VERIF
void					print_tab(t_stack *stack);
bool					ft_issort(t_stack *stack);
bool					antilonglong(char *str);
bool					ft_verifdouble(t_stack *stack_a);
bool					ft_verifsyntax(char *str);
void 					ft_verifonlyspace(char **argv);

// PARSING
void					ft_parsing(t_linked_stack **stack_a, char **argv);

// UTILS 
t_stack					create_index(t_stack *stack_a, t_stack *stack_b, int count);
void					init_stack_b(t_stack *stack_a, t_stack *stack_b);
int						ft_stack_a_len(char **argv);
int						find_bit_size(int a_size);
t_stack					ft_hybrid_listtotab(t_linked_stack *stacklist);

// RADIX
void					ft_radix(t_stack stack_a);

// RADIX
void					sort_three_elements(t_stack *stack_a, int max);
void					sort_four_elements(t_stack *a, t_stack *b, int min);
void					sort_five_elements(t_stack *stack_a, t_stack *stack_b);
void					radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
