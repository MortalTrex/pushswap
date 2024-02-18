/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:03:27 by rbalazs           #+#    #+#             */
/*   Updated: 2023/12/13 11:03:29 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if ((int) count < 0 && (int) size < 0)
		return (NULL);
	if ((int)(count * size) < 0)
		return (NULL);
	str = malloc((sizeof (char)) * (count * size));
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

/*
#include <stdio.h>
int main()
{
  int *tab = (int *) ft_calloc (0, 5);
  int i;

  for(i = 0; i < 3; i++)
  {
    tab[i] = i;
    printf("%d", tab[i]);
  }
  free(tab);
}
*/
