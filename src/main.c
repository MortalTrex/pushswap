#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack	stacktab_a;
	int	add;

	stack_a = NULL;
	add = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		add = 0;
	}
	init_stack_a(&stack_a, argv + add);
	stacktab_a = ft_hybrid_listotab(stack_a);
	free_stack(&stack_a);

 	printf("\033[0;31mStack A en tableau:\033[0m\n");
 	for (int i = 0; i < stacktab_a.len; i++)
 	{
 		printf("%d\n", stacktab_a.tab[i]);
 	}
 	printf("\n");
 	ft_radix(stacktab_a);
	printf("Stack triée ?: %d\n", ft_issort(stacktab_a));
 	free(stacktab_a.tab);
}
