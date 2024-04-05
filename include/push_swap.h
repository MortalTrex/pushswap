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

//STRUCTURES
typedef struct s_stack
{
	int	*tab;
	int	len;
}			t_stack;

typedef	struct	s_stack_node
{
	int	nbr;
	struct	s_stack_node	*next;
	struct	s_stack_node	*prev;
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

void	print_tab(t_stack	*stacktab);
bool	ft_verifdouble(t_stack_node *stack_a, int numbers);
bool	ft_verifsyntax(char *argv);
bool ft_issort(t_stack stacktab);

//PARSING
void init_stack_a(t_stack_node **stack_a, char **argv);
t_stack	init_stack_b(t_stack *stack_a);

//UTILS
t_stack_node	*find_last(t_stack_node *stack);
int	ft_stack_len(t_stack_node *stack); 

//CONVERSION
t_stack ft_hybrid_listotab(t_stack_node *stacklist);

//RADIX
void	ft_radix(t_stack stack_a);

#endif
