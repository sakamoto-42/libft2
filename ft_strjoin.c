/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:58:53 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 04:22:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// s1: La chaîne de caractères préfixe.
// s2: La chaîne de caractères suffixe.

// Valeur de retour :
// La nouvelle chaîne de caractères.
// NULL si l’allocation échoue.

// Description : Alloue (avec malloc(3)) et retourne une nouvelle
// chaîne, résultat de la concaténation de s1 et s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	size;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	size = s1_len + ft_strlen(s2);
	joined_str = (char *) malloc((size + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, s1_len + 1);
	ft_strlcat(joined_str, s2, size + 1);
	return (joined_str);
}
