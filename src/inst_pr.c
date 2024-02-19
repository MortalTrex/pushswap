#include "../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->len;
	if (stack_b->len == 0)
		return ;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	stack_a->len++;
	stack_b->len--;
	while (i < stack_b->len)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	printf("pa\n");
}

/*
void  pa(t_stack *stack_a, t_stack *stack_b)
{
  int temp;
  temp = stack_a->tab[0];
  stack_a->tab[0] = stack_b->tab[0];
  stack_b->tab[0] = temp;
  printf("pa\n");
}
*/

int main() 
{
  t_stack stack;
  t_stack stackb;
  int	array[] = {5, 2, 3, 4, 5};
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
  
  pa(&stack, false);
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
