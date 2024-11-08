/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:56:54 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 09:17:58 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// s: La chaîne de laquelle extraire la nouvelle chaîne.
// start: L’index de début de la nouvelle chaîne dans la chaîne ’s’.
// len: La taille maximale de la nouvelle chaîne.

// Valeur de retour :
// La nouvelle chaîne de caractères.
// NULL si l’allocation échoue.

// Description :
// Alloue (avec malloc(3)) et retourne une chaîne de caractères
// issue de la chaîne ’s’.
// Cette nouvelle chaîne commence à l’index ’start’ et
// a pour taille maximale ’len’.
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	size;
	char	*sub;

	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		return (NULL);
	size = len - start;
	sub = (char *) malloc((size + 1) + sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, size + 1);
	return (sub);
}