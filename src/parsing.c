#include "../include/push_swap.h"

// SPLITE
/*
int	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_strndup_split(const char *s1, int index, int n)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[index];
		i++;
		index++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_free_split(char **res, int index)
{
	while (index >= 0)
	{
		free(res[index]);
		index--;
	}
	free(res);
}

static void	ft_processwords(char const *s, char c, char **res, int words)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		n = 0;
		while (s[i + n] && s[i + n] != c)
			n++;
		res[j] = ft_strndup_split(s, i, n);
		if (!res[j])
		{
			ft_free_split(res, j);
			return ;
		}
		j++;
		i += n;
	}
	res[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ft_processwords(s, c, res, words);
	return (res);
}

//STRJOIN
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long int		res;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - '0');
		res *= 10;
		i++;
	}
	return ((res * sign) / 10);
}
*/

void	free_stack(t_stack_node **stack) //Define a function to free a stack if there are errors
{
	t_stack_node	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_stack_node	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	exit(1);
}

void init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int	i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		printf("%ld - ", n);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return 0;
	init_stack_a(&a, argv + 1);
	free_stack(&a);
}
