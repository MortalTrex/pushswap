#include "../include/push_swap.h"

t_stack_node	*find_last(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}

/*
int	ft_stack_len(t_stack_node *stack) 
{
	int	count;

	count = 0;
	while (stack)
	{
		stack->next;
		count++;
	}
	return (count);
}
*/

// static long	ft_atol(const char *s) 
// {
// 	long	result;
// 	int		sign;
//
// 	result = 0;
// 	sign = 1; 
// 	while (*s == ' ' || *s == '\t' || *s == '\n' || \
// 			*s == '\r' || *s == '\f' || *s == '\v')
// 		s++;
// 	if (*s == '-' || *s == '+')
// 	{
// 		if (*s == '-')
// 			sign = -1;
// 		s++;
// 	}
// 	while (ft_isdigit(*s))
// 		result = result * 10 + (*s++ - '0');
// 	return (result * sign);
// }
