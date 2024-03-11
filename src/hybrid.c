#include "../include/push_swap.h"

t_stack ft_hybrid_listotab(t_stack_node *stacklist)
{
	int	i;
	int	sizelist;
	t_stack	stacktab;

	i = 0;
	sizelist = ft_stack_len(stacklist);
	stacktab.len = sizelist;
	stacktab.tab = malloc(sizeof(int) * sizelist);
	if (!stacktab.tab)
		exit(1);
	while (i < sizelist)
	{
		stacktab.tab[i] = stacklist->nbr;
		stacklist = stacklist->next;
		i++;
	}
	return(stacktab);
}
