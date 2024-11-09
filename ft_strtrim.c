/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:01:10 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 10:32:17 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// s1: La chaîne de caractères à trimmer.
// set: Le set de référence de caractères à trimmer.

// Valeur de retour :
// La chaîne de caractères trimmée.
// NULL si l’allocation échoue.

// Description :
// Alloue (avec malloc) et retourne une copie de
// la chaîne ’s1’, sans les caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de
// caractères.
char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*s1_end;
	char		*trimmed_str;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
	{
		trimmed_str = ft_strdup("");
		if (!trimmed_str)
			return (NULL);
		return (trimmed_str);
	}
	s1_end = s1 + ft_strlen(s1);
	s1_end--;
	while (s1_end > s1 && ft_strchr(set, *s1_end))
		s1_end--;
	s1_end++;
	trimmed_str = ft_substr(s1, 0, (size_t)(s1_end - s1));
	if (!trimmed_str)
		return (NULL);
	return (trimmed_str);
}
