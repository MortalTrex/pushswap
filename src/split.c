#include "../include/push_swap.h"

/*
static int	count_words(char *str, int	c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			count++;
		}
		i++;
	}
	if (str[i - 1] == c)
		return (count - 1);
	return (count + 1);
}

int main()
{
	printf("%d", count_words("salut    je suis là    ", ' '));
}
*/

static int	count_words(char *s, char c)
{
	int		count; 
	bool	inside_word; 

	count = 0;
	while (*s) 	{
		inside_word = false; 		
		while (*s == c) 			
			++s; 		
		while (*s != c && *s)
		{
			if (!inside_word) 			
			{
				++count; 				
				inside_word = true; 			
			}
		++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char c) 
{
	static int	cursor;
	char		*next_word; 
	int			len; 
	int			i; 

	cursor = 0;
	len = 0;
	i = 0;
	//Le curseur prend la taille du caractère c
	while (str[cursor] == c) 
		cursor++;
	//Calcule la longueur len de l'espace qui ne fait pas partie du caractère c après le curseur
	while ((str[cursor + len] != c) && str[cursor + len]) 
		len++;
	//Le prochain mot peut etre malloc 
	next_word = malloc(sizeof(char) * (size_t)len + 1); 
	if (!next_word) 
		return (NULL);
	//Copie le contenu dans next word
	while ((str[cursor] != c) && str[cursor]) 
		next_word[i++] = str[cursor++]; 
	next_word[i] = '\0'; 
	return (next_word);
}

char **ps_split(char *s, char c) 
{
	int		words_count; 
	char	**result_array; 
	int		i; 

	i = 0;
	// Compte d'abord le nombre de mots, s'il y'en a pas arrete le programme
	words_count = count_words(s, c);
	if (!words_count) 
		exit(1);
	// Alloue la mémoire au résultat en fonction du nombre de mots
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); 
	if (!result_array)
		return (NULL);
	// En partant de la fin, parcourt la boucle
	while (words_count-- >= 0) 
	{
		//Si i = 0, ajoute une fin au caractère d'après
		if (i == 0) 
		{
			result_array[i] = malloc(sizeof(char));
			if (!result_array[i]) 
				return (NULL);
			result_array[i++][0] = '\0'; 
			continue ;
		}
		//A chaque fois, prend le mot d'après
		result_array[i++] = get_next_word(s, c); 
	}
	result_array[i] = NULL; 
	return (result_array);
}
