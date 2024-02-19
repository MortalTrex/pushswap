#include "../include/push_swap.h"

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
