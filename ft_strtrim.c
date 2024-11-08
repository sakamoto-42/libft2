/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:01:10 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 09:17:21 by juduchar         ###   ########.fr       */
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
// Alloue (avec malloc(3)) et retourne une copie de
// la chaîne ’s1’, sans les caractères spécifiés
// dans ’set’ au début et à la fin de la chaîne de
// caractères.
char *ft_strtrim(char const *s1, char const *set)
{
	char 	*s1_start;
	char 	*s1_end;
	char	*trimmed_str;

	s1_start = (char *) s1;
	while (*s1_start && ft_strchr(set, *s1_start))
		s1_start++;
	if (!(*s1_start))
	{
		trimmed_str = ft_strdup("");
		return (trimmed_str);
	}
	s1_end = (char *)(s1 + (ft_strlen(s1)));
	while (s1_end > s1_start && ft_strchr(set, *s1_start))
		s1_end--;
	trimmed_str = ft_substr(s1, s1_start - s1, (size_t)(s1_end - s1_start));
	return (trimmed_str);
}
