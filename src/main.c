#include "../include/push_swap.h"

// INSTS
/*
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
  
  sb(&stackb, true);
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
*/

//INSTRR AND PR
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
 stack_a.tab[3] = 2;
 stack_a.tab[4] = 10;

 stack_a.len = 5;

 stack_b.tab[0] = 5;
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
 //rab(&stack_a, 0);
 rra(&stack_a);

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
}
