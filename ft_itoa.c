/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:04:12 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 14:46:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// count and returns the numbers present in n
static size_t	ft_get_n_len(long long int n)
{
	size_t	n_len;

	if (n == 0)
		return (1);
	n_len = 0;
	if (n < 0)
	{
		n = -n;
		n_len++;
	}
	while (n > 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
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
char *ft_itoa(int n)
{
	int		size;
	char	*str;
	int		start;
	long long int	nb;

	nb = (long long int) n;
	size = ft_get_n_len(nb);
	str = (char *) malloc((size + 1) * sizeof(char));
	start = 0;
	if (nb < 0)
	{
		str[0] = '-';
		start = 1;
		nb = -nb;
	}
	while (size > start)
	{
		str[size - 1] = (char) ((nb % 10) + 48);
		nb = nb / 10;
		size--;
	}
	return (str);
}