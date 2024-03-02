#include "../include/push_swap.h"

// SPLITE

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

//STRJOIN
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);
}


int	main(int argc, char **argv)
{
	int	i;
	char **words;
	char *tmp;

	if (argc < 2) 
	{
		printf("Usage: %s <sentence1> <sentence2> ... <sentenceN>\n", argv[0]);
		return 1;
	}
	
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], argv[i + 1]);
		words = ft_split(tmp, ' ');

		for (int j = 0; words[j] != NULL; j++)
		{
			printf("%s", words[j]);
			free(words[j]);
		}
		free(words);
		i++;
	}
	free(tmp);
	return 0;
}
