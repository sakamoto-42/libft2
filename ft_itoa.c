/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:04:12 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 05:06:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// count and returns the numbers present in n
static size_t	ft_get_n_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// Paramètres :
// n: L’entier à convertir.

// Valeur de retour
// La chaîne de caractères représentant l’entier.
// NULL si l’allocation échoue.

// Description :
// Alloue (avec malloc(3)) et retourne une chaîne
// de caractères représentant l’entier ’n’ reçu en
// argument.
// Les nombres négatifs doivent être gérés.
char	*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	nb;

	len = ft_get_n_len(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nb = (unsigned int)-n;
	else
		nb = (unsigned int)n;
	while (len--)
	{
		str[len] = (char)((nb % 10) + 48);
		nb = nb / 10;
		if (len == 0 && n < 0)
			str[0] = '-';
	}
	return (str);
}
