/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:23:24 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/10 17:27:52 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// lst : Le début de la liste.

// Valeur de retour :
// Taille de la liste

// Description :
// Compte le nombre d’éléments de la liste.
int	ft_lstsize(t_list *lst)
{
	int		count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
