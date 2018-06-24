/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static int	check(char c, char delimitor)
{
	if (c == '\t')
		return (0);
	if (c != delimitor)
		return (1);
	return (0);
}

static int	count_words(char *str, char delimitor)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while ((check(str[i], delimitor) == 0) && str[i] != '\0')
		i++;
	while (str[i] != '\0') {
		while ((check(str[i], delimitor) == 1) && str[i] != '\0')
			i++;
		nb_words++;
		while ((check(str[i], delimitor) == 0) && str[i] != '\0')
			i++;
	}
	return (nb_words);
}

static int	len_str(char *str, int i, char delimitor)
{
	int	len;

	len = 0;
	while ((check(str[i], delimitor) == 0) && str[i] != '\0')
		i = i + 1;
	while ((check(str[i], delimitor) == 1) && str[i] != '\0') {
		len = len + 1;
		i++;
	}
	return (len);
}

char	**str_to_wordtab(char *str, char delimitor)
{
	char	**tab;
	int	i = 0;
	int	nb_words;
	int	p = 0;
	int	k;
	int	len;

	nb_words = count_words(str, delimitor);
	if ((tab = malloc(sizeof(char *) * (nb_words + 1))) == NULL)
		return (NULL);
	while (i < nb_words && (k = 0) == 0) {
		len = len_str(str, p, delimitor);
		if ((tab[i] = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		while ((check(str[p], delimitor) == 1) && str[p] != '\0')
			tab[i][k++] = str[p++];
		tab[i++][k] = '\0';
		p++;
	}
	tab[i] = NULL;
	return (tab);
}
