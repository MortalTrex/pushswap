#include "../include/push_swap.h"

void	sort_three_elements(t_stack *stack_a)
{
	if (stack_a->tab[2] != 2)
	{
		if (stack_a->tab[0] == 2)
			rab(stack_a, 0);
		else
			rrab(stack_a, 0);
	}
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	sort_three_elements_forfive(t_stack *stack_a)
{
	if (stack_a->tab[2] != 4)
	{
		if (stack_a->tab[0] == 4)
			rab(stack_a, 0);
		else
			rrab(stack_a, 0);
	}
	if (stack_a->tab[0] > stack_a->tab[1])
		sa(stack_a, true);
}

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->tab[0] != 3)
		rab(stack_a, 0);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
	rab(stack_a, 0);
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
    int i;
    int j;
    int size;

    j = 0;
    while (j < 2)
    {
        printf("%d\n");
        i = 0;
        while(i < stack_a->len && stack_a->tab[i] != j)
            i++;
        size = i;
        if (size <= 2)
        {
            if (i == 1)
                rab(stack_a, 0);
        }
        if (size > 2)
        {
            while (i < stack_a->len)
            {
                rrab(stack_a, 0);
                i++;
            }
        }
        pb(stack_a, stack_b);
        j++;
    }
    sort_three_elements_forfive(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    //print_tab(stack_a);
}
