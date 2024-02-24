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

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->len;
	if (stack_a->len == 0)
		return ;
	while (i > 0)
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = stack_a->tab[0];
	stack_b->len++;
	stack_a->len--;
	while (i < stack_a->len)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	printf("pb\n");
}

void ra(t_stack *stack_a)
{
 int i;

 i = stack_a->len;
 if (stack_a->len == 0)
  return;
 while (i > 0)
 {
  stack_a->tab[i] = stack_a->[i - 1];
  i--;
 }
}

int		main(void)
{
 // Création des piles
 t_stack stack_a;
 t_stack stack_b;
 stack_a.len = 0;
 stack_b.len = 0;
 stack_a.tab = malloc(sizeof(int) * 10); 
 stack_b.tab = malloc(sizeof(int) * 10); 
 
 // Ajout de quelques éléments à la pile B pour le test
 stack_a.tab[0] = 3;
 stack_a.tab[1] = 5;
 stack_a.tab[2] = 4;
 stack_a.len = 3;

 stack_b.tab[0] = 0;
 stack_b.tab[1] = 8;
 stack_b.tab[2] = 10;
 stack_b.len = 3;

 // Affichage des piles avant l'appel de la fonction
 printf("Stack A: ");
 for (int i = 0; i < stack_a.len; i++)
 {
 	printf("%d ", stack_a.tab[i]);
 }
 printf("\n");
 
 printf("Stack B: ");
 for (int i = 0; i < stack_b.len; i++)
 {
 	printf("%d ", stack_b.tab[i]);
 }
 printf("\n");

 // Appel de la fonction 
 pb(&stack_a, &stack_b);
 
 // Affichage des piles après l'appel de la fonction
 printf("Stack A: ");
 for (int i = 0; i < stack_a.len; i++)
 {
 	printf("%d ", stack_a.tab[i]);
 }
 printf("\n");
 
 printf("Stack B: ");
 for (int i = 0; i < stack_b.len; i++) 
 {
 	printf("%d ", stack_b.tab[i]);
 }
 printf("\n");
 
 // Libération de la mémoire allouée pour les piles
 free(stack_a.tab);
 free(stack_b.tab);
 
 return (0);
}
