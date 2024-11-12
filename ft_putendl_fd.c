/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:10:59 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 10:30:20 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// s: La chaîne de caractères à écrire.
// fd: Le descripteur de fichier sur lequel écrire.

// Valeur de retour :
// Aucune

// Description :
// Écrit La chaîne de caractères ’s’ sur le descripteur de fichier donné
// suivie d’un retour à la ligne.
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
