/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:08:45 by rbalazs           #+#    #+#             */
/*   Updated: 2023/12/13 11:08:46 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_strndup_split(const char *s1, int index, int n)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[index];
		i++;
		index++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_free_split(char **res, int index)
{
	while (index >= 0)
	{
		free(res[index]);
		index--;
	}
	free(res);
}

static void	ft_processwords(char const *s, char c, char **res, int words)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		n = 0;
		while (s[i + n] && s[i + n] != c)
			n++;
		res[j] = ft_strndup_split(s, i, n);
		if (!res[j])
		{
			ft_free_split(res, j);
			return ;
		}
		j++;
		i += n;
	}
	res[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ft_processwords(s, c, res, words);
	return (res);
}

/*
int main()
{
  char *s = "salutca-va";
  printf("Il y'a %d mots\n", ft_countwords(s, ' '));
  char **res = ft_split(s, '-');
  int i = 0;
  while(res[i])
  {
    printf("%s", res[i]);
    i++;
  }
  free(res);
}
*/
