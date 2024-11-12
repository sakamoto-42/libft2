/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:08:45 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 10:27:57 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Paramètres :
// c: Le caractère à écrire.
// fd: Le descripteur de fichier sur lequel écrire.

// Valeur de retour :
// Aucune

// Description Écrit le caractère ’c’ sur le descripteur de fichier donné.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
