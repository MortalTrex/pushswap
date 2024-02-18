/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:07:28 by rbalazs           #+#    #+#             */
/*   Updated: 2023/12/13 11:07:30 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	long	n1;
	long	res;

	res = 0;
	n1 = n;
	if (n1 < 0)
	{
		n1 = n1 * -1;
		res++;
	}
	if (n1 == 0)
		res = 1;
	while (n1 > 0)
	{
		res++;
		n1 = n1 / 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;
	long	last_nb;

	i = ft_count(n);
	res = malloc (sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	last_nb = n;
	if (n < 0)
		last_nb = last_nb * (-1);
	res[i] = '\0';
	while (i > 0)
	{
		res[i - 1] = '0' + last_nb % 10;
		last_nb = last_nb / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

/*
int main()
{
  int n = 456;
  char *res = ft_itoa(n);
  printf("%s", res);
  free(res);
}
*/
