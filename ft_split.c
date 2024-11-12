/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:02:33 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 11:22:51 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// count words separated by the character c in the string s

// DESCRIPTION :
// The ft_count_words() function count the words in the string s
// A word is a set of characters delimited by the character c
// (and by the start and the and of the string)

// RETURN VALUE :
// The ft_memmove() function returns a size_t corresponding
// to the number of words found
static size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			word_count++;
		s++;
	}
	return (word_count);
}

// The ft_get_word_end() function returns a pointer to the first occurrence
// of the character c in the string s
// or to the end of the string if the character c is not found
static const char	*ft_get_word_end(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

// extract a word in a string
// between start and end pointer
static char	*ft_extract_word(const char *start, const char *end)
{
	char	*word;
	char	*dest;

	word = (char *) malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	dest = word;
	while (start < end)
		*dest++ = *start++;
	*dest = '\0';
	return (word);
}

// free n strings of an array of strings
static char	**ft_free_strs(char **strs, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

// Paramètres :
// s: La chaîne de caractères à découper.
// c: Le caractère délimiteur.

// Valeur de retour :
// Le tableau de nouvelles chaînes de caractères résultant du découpage.
// NULL si l’allocation échoue.

// Description :
// Alloue (avec malloc) et retourne un tableau
// de chaînes de caractères obtenu en séparant ’s’ à
// l’aide du caractère ’c’, utilisé comme délimiteur.
// Le tableau doit être terminé par NULL.
char	**ft_split(char const *s, char c)
{
	size_t		word_count;
	char		**splitted_strs;
	size_t		i;
	const char	*word_end;

	word_count = ft_count_words(s, c);
	splitted_strs = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!splitted_strs)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_end = ft_get_word_end(s, c);
		splitted_strs[i] = ft_extract_word(s, word_end);
		if (!splitted_strs[i])
			return (ft_free_strs(splitted_strs, i));
		s = word_end;
		i++;
	}
	splitted_strs[i] = NULL;
	return (splitted_strs);
}
