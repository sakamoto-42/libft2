/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:09:49 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 10:30:36 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// s: La chaîne de caractères à écrire.
// fd: Le descripteur de fichier sur lequel écrire.

// Valeur de retour :
// Aucune

// Description :
// Écrit la chaîne de caractères ’s’ sur le
// descripteur de fichier donné.
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd((int)*s, fd);
		s++;
	}
}
