/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:01:10 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 05:31:45 by juduchar         ###   ########.fr       */
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
	char const	*s1_end;
	char		*trimmed_str;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (*s1 == '\0')
	{
		trimmed_str = ft_strdup("");
<<<<<<< HEAD
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
=======
  if (!trimmed_str)
     return (NULL);
		return (trimmed_str);
	}
	s1_end = (char *)(s1 + (ft_strlen(s1)));
	while (s1_end > s1_start && ft_strchr(set, *s1_end))
		s1_end--;
	trimmed_str = ft_substr(s1, s1_start - s1, (size_t)(s1_end - s1_start));
  if (!trimmed_str)
     return (NULL);
>>>>>>> d05873f544e24376685dcad26048377493bfeb7d
	return (trimmed_str);
}
