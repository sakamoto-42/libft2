/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:12:27 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 14:46:55 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// n: L’entier à écrire.
// fd: Le descripteur de fichier sur lequel écrire.

// Valeur de retour :
// Aucune

// Description :
// Écrit l’entier ’n’ sur le descripteur de fichier donné.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd((int)n / 10, fd);
	ft_putchar_fd((char)(n % 10 + 48), fd);
}
