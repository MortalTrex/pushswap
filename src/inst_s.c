#include "../include/push_swap.h"

void	sa(t_stack *stack_a, bool print)
{
	int	temp;

	if (stack_a->len < 2)
		return;
	temp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = temp;
	if (print == true)
		printf("sa\n");
}

void	sb(t_stack *stack_b, bool print)
{
	int	temp;
	if (stack_b->len < 2)
		return ;
	temp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = temp;
	if (print == true)
		printf("sb\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, false);
	sb(stack_b, false);
	printf("ss\n");
}

int main() 
{
  t_stack stack;
  t_stack stackb;
  int	array[] = {1, 2, 3, 4, 5};
  int	arrayb[] = {1, 2, 3};
  int	i = 0;
  stack.tab = array;
	stack.len = 5;
	stackb.tab = arrayb;
	stackb.len = 3;

  printf("Avant : \n");
  while	(i < stack.len) 
	{      
		printf("%d ", stack.tab[i]);
    i++;
  }
  printf("\n");
  i = 0;
  while	(i < stackb.len) 
	{      
		printf("%d ", stack.tab[i]);
    i++;
  }
  printf("\n");
  
  sa(&stack, false);
  //ss(&stack, &stackb);

  printf("Après : \n");
  i = 0;
  while	(i < stack.len) 
  {  
  	printf("%d ", stack.tab[i]);
  	i++;
  }
  printf("\n");
  i = 0;
  while	(i < stackb.len) 
	{      
		printf("%d ", stackb.tab[i]);
    i++;
  }
  printf("\n");
}
