/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:07:39 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 09:13:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Paramètres :
// s: La chaîne de caractères sur laquelle itérer.
// f: La fonction à appliquer à chaque caractère.

// Valeur de retour :
// Aucune

// Description :
// Applique la fonction ’f’ à chaque caractère de la
// chaîne de caractères transmise comme argument,
// et en passant son index comme premier argument.
// Chaque caractère est transmis par adresse à ’f’
// afin d’être modifié si nécessaire.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
